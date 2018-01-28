#!/bin/bash -x

cd "$(dirname "$0")/.." || exit

make || exit

mkdir -p data || exit

bin/julia -2 2 -2 2 800 800 -1.037 0.17 >data/julia.csv
bin/plot_data.py data/julia.csv

bin/mandelbrot -2 2 -2 2 800 800 0 0 >data/mandelbrot.csv
bin/plot_data.py data/mandelbrot.csv
