import serial # import serial library
import numpy as np
import matplotlib.pyplot as plt # import matplotlib library
import csv
import matplotlib.animation as animation

csvfile="data.csv"
#create empty lists for sonar data
leftSonar=[]
frontSonar=[]
rightSonar=[]
xpos=[]
ypos=[]

#teensyData=serial.Serial("/dev/ttyACM0",9600) # Creating the serial object named teensy data
# Note that "/dev/ttyACM1" must match the connected port in the Arduino IDE
# 9600 is the boad rate
# plt.ion() #Tell matplotlib you want interactive mode to plot live data

location=["/dev/ttyACM0","/dev/ttyACM1"]
for device in location:
    try:
        teensyData=serial.Serial(device,9600)
        if(teensyData.isOpen() == True):
            print "Connected"
    except:
        print "Failed to connect"

while True:                              # While loop that loops forever 
    while (teensyData.inWaiting () == 0): # Wait here until there is data
           pass                          # do nothing
    teensyString = teensyData.readline() # read the line of text from the serial port
    dataArray = teensyString.split(',')  # Split it into an array called dataArray
    left  = float (dataArray[0]) # convert first element to floating number and put in left
    front = float (dataArray[1]) # convert second element to floating number and put in front
    right = float (dataArray[2]) # convert third element to floating number and put in right
    x = float(dataArray[3]) # etc
    y = float(dataArray[4]) # etc
    
    leftSonar.append(left)       # build our left sonar array by appending the sonar readings
    frontSonar.append(front)     # build our front sonar array by appending the sonar readings
    rightSonar.append(right)     # build our right sonar array by appending the sonar readings
    xpos.append(x) # etc
    ypos.append(y) # etc
    data=(left,front,right,x,y)
    #print left,front,right,x,y

    with open(csvfile, "a")as output:
        writer = csv.writer(output, delimiter=",", lineterminator = '\n')
        writer.writerow(data)    
    
    
   





   
    
