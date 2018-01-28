.PHONY: all
all: bin/julia bin/mandelbrot

bin/julia: src/julia/julia.c src/julia/complex.c src/julia/complex.h | bin
	gcc -O3 -o bin/julia src/julia/julia.c src/julia/complex.c -lm

bin/mandelbrot: src/mandelbrot/mandelbrot.cpp | bin
	g++ -O3 -o bin/mandelbrot src/mandelbrot/mandelbrot.cpp

bin:
	mkdir -p bin

.PHONY: clean
clean:
	rm -f bin/julia bin/mandelbrot
