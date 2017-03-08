
import numpy as np
import matplotlib.pyplot as plt
import sys

def importData(file):
	file = open(file)
	time = []
	xPosition1 = []
	file.readline()
	for line in file:
		data = line.split(' ')
		# print(data)
		time.append(float(data[0]))
		xPosition1.append(float(data[5]))
	return (time, xPosition1)

def drawPlot(x1, y, xAxis, yAxis, title, file):
	plt.plot(y, x1, label = 'Line 1')
	plt.xlabel(xAxis)
	plt.ylabel(yAxis)
	plt.title(title)
	# plt.figure(figsize=(100, 50))
	plt.savefig(file + '.png')
	# plt.clf()
	# plt.close()
	plt.show()

if __name__ == '__main__':
	y, time = importData('log.txt')
	drawPlot(time, y, 'time', 'height', 'position', 'out')