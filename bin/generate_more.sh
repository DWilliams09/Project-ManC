#!/bin/bash -x

cd "$(dirname "$0")/.." || exit

make || exit

mkdir -p data || exit

bin/julia -2 2 -2 2 800 800 -2.1 1.25 >data/julia2.csv
bin/plot_data.py data/julia2.csv

bin/julia -2 2 -2 2 800 800 -1.1 0.37 >data/julia3.csv
bin/plot_data.py data/julia3.csv

bin/mandelbrot -2 2 -2 2 800 800 0.5 0.5 >data/mandelbrot2.csv
bin/plot_data.py data/mandelbrot2.csv

bin/mandelbrot -2 2 -2 2 800 800 -0.6 -0.1 >data/mandelbrot3.csv
bin/plot_data.py data/mandelbrot3.csv
