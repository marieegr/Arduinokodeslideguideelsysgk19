import time
import math
import firebase_admin
from firebase_admin import credentials,firestore


cred = credentials.Certificate("./accountKey.json")
default_app = firebase_admin.initialize_app(cred)
db = firestore.client()
doc_ref = db.collection(u'data').document(u'values')

def main():

    import serial
    ser = serial.Serial("COM3",baudrate=9600,timeout=1)



    distance1 = None
    distance2 = None
    r1 = 0
    r2 = 0

    while r1 < 20 and r2 < 20:
        arduinoData = ser.readline()
    #    print(arduinoData)
        data = str(ser.readline())
        g1 = distance1
        g2 = distance2
        if len(data) > 8 and len(data) < 50:
        #    data = str("b'\a110r\n")
            sug_meg = int(data[3:-2-(len(data)-6)])


            if data != "b'\r\n":
                if sug_meg == 1:
                    distance1 = int(data[4:-3])
                    
                if sug_meg == 2:
                    distance2 = int(data[4:-3])

            #distance2 = 15
            print(distance1)
            print(distance2)
        
        elif distance1 == g1 and distance1 != None:
            r1 += 1
        elif distance2 == g2 and distance2 != None:
            r2 += 1
            

    print("ferdig")
    #k=1000
    k=120
    if distance1 != None and distance2 != None:
        x=abs(distance1-distance2)
        angle=math.degrees(math.atan(x/k))
        print(angle)

        doc_ref.update({
                u'value': round(angle, 1)
            })
for i in range(0,10):
    print("Restarting")
    time.sleep(1)
    doc_ref.update({
        u'timer': 3
    })
    time.sleep(1)
    doc_ref.update({
        u'timer': 2
    })
    time.sleep(1)
    doc_ref.update({
        u'timer': 1
    })
    time.sleep(1)
    doc_ref.update({
        u'value': "waiting",
        u'timer': "Slide!"
    })
    main()