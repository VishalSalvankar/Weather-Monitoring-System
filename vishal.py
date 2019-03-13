import serial
import requests


PORT = "COM3"
BAUD = 9600

ard = serial.Serial(PORT,BAUD)

while True:
    data = ard.readline()
    #print data
    #data=data.encode(encoding='utf-8', errors='strict')
    data=data.decode(encoding='utf-8', errors='strict')
    data = data.split("-")
    
           
    d1 = "&field1="+str(data[0])
    d2 = "&field2="+str(data[1])
    d3 = "&field3="+str(data[2])
    d4 = "&field4="+str(data[3])
    url = "https://api.thingspeak.com/update?api_key=VK493EKSQKAV6E19"+d1+d2+d3+d4

    response = requests.get(url)

    if(response.status_code == 200):
        print("Values uploadedd Sucessfully! Kindly check the cloud server.")
        
        
