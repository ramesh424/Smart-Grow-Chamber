import os
import cv2
import torch
import numpy as np
from flask import Flask, Response, render_template
from ultralytics import YOLO

# Disable Qt GUI requirement
os.environ["QT_QPA_PLATFORM"] = "offscreen"

# Initialize Flask app
app = Flask(__name__)

# Load YOLO model
MODEL_PATH = "/home/pi/seed/best.pt"  # Update with your model path
model = YOLO(MODEL_PATH)

# Initialize video capture
cap = cv2.VideoCapture(0)
if not cap.isOpened():
    raise RuntimeError("Error: Could not open video capture.")

def generate_frames():
    while True:
        ret, frame = cap.read()
        if not ret:
            break

        # Resize frame for faster inference
        resized_frame = cv2.resize(frame, (640, 480))

        # Perform YOLO inference
        results = model(resized_frame, verbose=False)

        # Draw bounding boxes
        for result in results[0].boxes.data:
            x1, y1, x2, y2, conf, class_id = map(float, result[:6])
            if conf > 0.25:
                label = f"Class {int(class_id)} ({conf:.2f})"
                cv2.rectangle(frame, (int(x1), int(y1)), (int(x2), int(y2)), (0, 255, 0), 2)
                cv2.putText(frame, label, (int(x1), int(y1) - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)

        # Encode frame as JPEG
        _, buffer = cv2.imencode('.jpg', frame)
        frame_bytes = buffer.tobytes()

        # Yield frame for streaming
        yield (b'--frame\r\n'
               b'Content-Type: image/jpeg\r\n\r\n' + frame_bytes + b'\r\n')

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/video_feed')
def video_feed():
    return Response(generate_frames(), mimetype='multipart/x-mixed-replace; boundary=frame')

if __name__ == "__main__":
    try:
        app.run(host="0.0.0.0", port=5000, debug=False, threaded=True)
    finally:
        cap.release()  # Ensure video capture is released when the app stops
