
image:image.c image.h
	gcc -g image.c -o image -lm
clean:
	rm -f image output.png pimage
pimage:pimage.c image.h
	gcc -g pimage.c -o pimage -lm -pthread

