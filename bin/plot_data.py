#!/usr/bin/env python3

import sys
import numpy as np
import pandas as pd
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

def main():
	file_dir = sys.argv[1]

	d = pd.read_csv(file_dir, header=None)
	N = len(d) ## Total number of cells in our matrix

	xmin = d.ix[0,0]
	ymin = d.ix[0,1]
	xmax = d.ix[len(d)-1,0]
	ymax = d.ix[len(d)-1,1]

	ystep = d.ix[1,1] - d.ix[0,1]

	ylen = int(round((ymax-ymin)/ystep))+1
	xlen = int(N/ylen)

	d = d.ix[:,2]
	d = pd.DataFrame(d.values.reshape([xlen,ylen]))
	d = d.transpose()

	plt.matshow(d, cmap='jet')

	ax = plt.gca()
	### Format axis ticks and labels
	ax.invert_yaxis()
	ax.xaxis.set_ticks_position('bottom') 
	xlabels = [str(round(f,6)) for f in np.linspace(xmin, xmax, 5)]
	ylabels = [str(round(f,6)) for f in np.linspace(ymin, ymax, 5)]

	ax.xaxis.set_ticks(np.linspace(0, xlen, 5))
	ax.yaxis.set_ticks(np.linspace(0, ylen, 5))
	ax.xaxis.set_ticklabels(xlabels)
	ax.yaxis.set_ticklabels(ylabels)
	### Set axis labels
	ax.xaxis.set_label_position('bottom')
	plt.xlabel(r"$Re(z)$", size=12)
	plt.ylabel(r"$Im(z)$", size=12)

	fname = file_dir.split('/')[-1]
	fname = fname.split('.')[0]
	png = 'data/{}.png'.format(fname)
	plt.savefig(png)
	print("Wrote", png)

	plt.show()

if __name__ == "__main__":
	main()
