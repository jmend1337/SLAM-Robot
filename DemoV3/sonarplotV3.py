import csv
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

leftSonar=[]
frontSonar=[]
rightSonar=[]

fig=plt.figure()
ax1=fig.add_subplot(1,2,1)

def animate(i):
    cnt=0;
    with open('data.csv','rb') as csvfile:
        spamreader=csv.reader(csvfile, delimiter=' ',quotechar='|')
        for row in spamreader:
            cnt=cnt+1;
            #print ', '.join(row)
            data=', '.join(row)
            
            dataArray=data.split(',')
            
            left  = float (dataArray[0]) # convert first element to floating number and put in left
            front = float (dataArray[1]) # convert second element to floating number and put in front
            right = float (dataArray[2]) # convert third element to floating number and put in right
            x = float(dataArray[3]) # etc
            y = float(dataArray[4]) # etc
            
            leftSonar.append(left)       # build our left sonar array by appending the sonar readings
            frontSonar.append(front)     # build our front sonar array by appending the sonar readings
            rightSonar.append(right)     # build our right sonar array by appending the sonar readings
            #xpos.append(x) # etc
            #ypos.append(y) # etc
            
            #data=(left,front,right,x,y)
            #print data
            
        if (cnt>1):
            leftSonar.pop(0)
        ax1.clear()
        ax1.scatter(0,0,marker='o') # plot the robot's position
        ax1.scatter(-1*left,0, marker='x') # plot the left obstacle distance
        ax1.scatter(0, front, marker='x') # plot the front obstacle distance
        ax1.scatter(right,0, marker='x') # plot the right obstacle distance
        ax1.set_ylim(-200,200)
        ax1.set_xlim(-200,200)
        ax1.set_title('Obstacles With Respect to the Robot')        
        
        
ani=animation.FuncAnimation(fig,animate,interval=1000)
plt.show()
