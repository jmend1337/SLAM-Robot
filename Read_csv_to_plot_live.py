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
ax1=fig.add_subplot(1,1,1)

def animate(i):
    with open('data.csv','rb') as csvfile:
        spamreader=csv.reader(csvfile, delimiter=' ',quotechar='|')
        for row in spamreader:
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
        ax1.clear()
        plt.xlim(-100, 100)
        plt.ylim(-100, 100)
        plt.annotate(s='current pos',
                    xy=(x, y)
                    )
        ax1.plot(xpos,ypos, marker='o')
        
ani=animation.FuncAnimation(fig,animate,interval=10)
plt.show()
        
            
    
