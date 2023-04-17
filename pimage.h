#ifndef ___IMAGE
#define ___IMAGE
#include <stdint.h>

#define Index(x,y,width,bit,bpp) y*width*bpp+bpp*x+bit

typedef double Matrix[3][3];

typedef struct{
    uint8_t* data;
    int width;
    int height;
    int bpp;
} Image;

typedef struct{
	Image* srcImage;
	Image* destImage;
	Matrix* algorithm;
	int chunk;
	int procid;
} Convolutant;

enum KernelTypes{EDGE=0,SHARPEN=1,BLUR=2,GAUSE_BLUR=3,EMBOSS=4,IDENTITY=5};

uint8_t getPixelValue(Image* srcImage,int x,int y,int bit,Matrix algorithm);
void* convolute(void* convo);
//void convolute(Image* srcImage,Image* destImage,Matrix algorithm);
int Usage();
enum KernelTypes GetKernelType(char* type);

#endif
