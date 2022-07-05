import cv2 as cv
from cvzone.FaceDetectionModule import FaceDetector
from cvzone.SerialModule import SerialObject

cap = cv.VideoCapture(0) # Change number based on camera

detector = FaceDetector()
arduino = SerialObject()

while cap.isOpened():
    success, img = cap.read()

    img, bboxes = detector.findFaces(img)

    if bboxes:
        arduino.sendData([1])
    else:
        arduino.sendData([0])

    cv.imshow("Image", img)
    cv.waitKey(1)
