import serial
import datetime
import urllib3
ser = serial.Serial('COM5',9600)
ser.flushInput()

baseURL= 'https://api.thingspeak.com/update?api_key='
API_key= '6V16Q4S6I0KUU74G'
ID      = 'M00739105'

while True:
    try:
        ser_bytes = ser.readline()
        decoded_bytes = ser_bytes[0:len(ser_bytes)-2].decode("utf-8")
        now = datetime.datetime.now()
        now = now.strftime("%Y- %m -%d %H: %M: %S")
        data = ("’{}’,{}\r\n".format(now,decoded_bytes) )
        print(data)

        tsURL= ( "{}{}&field1=‘{}’&field2={}".format(baseURL,API_key,ID,decoded_bytes))
        http = urllib3.PoolManager()
        tspeak= http.request('GET', tsURL)
        tspeak.status
    except:
        print("Keyboard Interrupt")# keep looping until user press CTRL-C
        break
        
