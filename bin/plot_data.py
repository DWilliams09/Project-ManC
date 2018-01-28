###
# Name: Tim Frenzel
# Student ID: 002267120
# Email: frenz102@mail.chapman.edu
# Course: CS510 Fall 2017
###

#######  START: CREATE PLOT #######
#import packages
import sys
import numpy as np
import pandas as pd
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

def main():
	file_dir = sys.argv[1]

	data = pd.read_csv(file_dir, header=None)
	N = len(data)
	
	#determine axis
	xmin = data.ix[0,0]
	ymin = data.ix[0,1]
	xmax = data.ix[len(data)-1,0]
	ymax = data.ix[len(data)-1,1]
	ystep = data.ix[1,1] - data.ix[0,1]
		ylen = int(round((ymax-ymin)/ystep))+1
		xlen = int(N/ylen)

	data = data.ix[:,2]
	data = pd.DataFrame(data.values.reshape([xlen,ylen]))
	data = data.transpose()
	
	#show plot
	plt.matshow(data, cmap='jet')
	ax = plt.gca()
	
	#axis ticks 
		ax.invert_yaxis()
		ax.xaxis.set_ticks_position('bottom') 
		xlabels = [str(round(f,6)) for f in np.linspace(xmin, xmax, 5)]
		ylabels = [str(round(f,6)) for f in np.linspace(ymin, ymax, 5)]

		ax.xaxis.set_ticks(np.linspace(0, xlen, 5))
		ax.yaxis.set_ticks(np.linspace(0, ylen, 5))
		ax.xaxis.set_ticklabels(xlabels)
		ax.yaxis.set_ticklabels(ylabels)
	
	#save file
	fname = file_dir.split('/')[-1]
	fname = fname.split('.')[0]
	png = 'data/{}.png'.format(fname)
	plt.savefig(png)

#######  END: CREATE PLOT #######
if __name__ == "__main__":
	main()
