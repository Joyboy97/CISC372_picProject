#include "omp.h"
#include <stdio.h>
#define NUMTHREADS 4
int main(int argc, char **argv){
	long num_steps=100000;
	double step, t1,t2;
	int i, nthreds,procs=atoi(argv[1]);
	double pi,sums[procs], sum;
	t1= omp_get_wtime();
	step=1.0/(double)num_steps;
	omp_set_num_threads(procs); 
	#pragma omp parallel
	//for (i=0; i<num_steps;i++)
	{
		int id,nthrds;
		double x;
		nthrds=omp_get_num_threads();
		id=omp_get_thread_num();
		if(id==0) nthreds=nthrds;
	//	int i;
		for (i=id, sums[id]=0.0; i<num_steps;i=i+nthrds){
			x=(i+.5)*step;
			#pragma omp critical
				sums[id]+=4.0/(1.0+x*x);
		}
	}
	t2= omp_get_wtime();
	for(i=0;i<nthreds;i++){
		pi+=sums[i]*step;
	}
	printf("pi = %f\n",pi);
	printf("done in %f seconds\n",(t2-t1));
}
