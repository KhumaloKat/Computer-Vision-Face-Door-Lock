import os
import cv2
import face_recognition
import pickle

path = 'KnownFaces'
classNames = []
encodeList = []

myList = os.listdir(path)
print("Faces Found", len(myList))

for cl in myList:
    curImg = cv2.imread(f'{path}/{cl}')
    img = cv2.cvtColor(curImg, cv2.COLOR_BGR2RGB)
    encodings = face_recognition.face_encodings(img)

    # Check if any face encodings are found
    if encodings:
        encode = encodings[0]
        encodeList.append(encode)
        classNames.append(os.path.splitext(cl)[0])
    else:
        print(f"No faces found in {cl}")

with open('encodes', 'wb') as f:
    pickle.dump([classNames, encodeList], f)

print("Done Encoding")
