
image:image.c image.h
	gcc -g image.c -o image -lm
clean:
	rm -f image output.png pimage opimage
pimage:pimage.c pimage.h
	gcc -g pimage.c -o pimage -lm -pthread

#export OMP_NUM_THREADS=4
opimage:opimage.c opimage.h
	gcc -g -fopenmp opimage.c -o opimage -lm

omp: testomp.c
	gcc -g -fopenmp testomp.c -o omp
pimagehpc: pimage.c pimage.h
	gcc pimage.c -o pimage -pthread -lm
	
