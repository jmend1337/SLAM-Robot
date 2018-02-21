import csv
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

leftSonar=[]
frontSonar=[]
rightSonar=[]
xpos=[]
ypos=[]

fig=plt.figure()
ax1=fig.add_subplot(1,2,1)
ax2=fig.add_subplot(2,2,2)
ax3=fig.add_subplot(2,2,4)

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
            xpos.append(x) # etc
            ypos.append(y) # etc
            
            #data=(left,front,right,x,y)
            #print data
        if (cnt>20):
            leftSonar.pop(0)
        ax1.clear()
        ax1.plot(leftSonar, marker='o')
        ax1.set_ylim(0,400)
        ax1.set_title('leftSonar')
        del leftSonar[:]
        
        ax2.clear()
        ax2.plot(frontSonar, marker='*')
        ax2.set_ylim(0,400)
        ax2.set_title('frontSonar')
        del frontSonar[:]
        
        ax3.clear()
        ax3.plot(rightSonar, marker='x')
        ax3.set_ylim(0,400)
        ax3.set_title('rightSonar')
        del rightSonar[:]
        
ani=animation.FuncAnimation(fig,animate,interval=1000)
plt.show()
