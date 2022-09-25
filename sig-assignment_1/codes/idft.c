#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#include <complex.h>
#include "header.h"
#include <time.h>

#define pi 3.14159

int main(){
int N=8;
double *Yr = (double *)malloc(N*sizeof(double));
double *Yi = (double *)malloc(N*sizeof(double));
double *ynr = (double *)malloc(N*sizeof(double));
double *yni = (double *)malloc(N*sizeof(double));
Yr = readData("ykrealthroughmult.dat",N);
Yi = readData("ykimagthroughmult.dat",N);

clock_t t;
   t = clock();
for(int k=0;k<N;k++){
    for(int n=0;n<N;n++){
    	ynr[k]+=Yr[n]*cos(2*pi*n*k/N)+Yi[n]*sin(-2*pi*n*k/N);
}
//ynr[k]/=N;
//printf("%lf ",ynr[k]);
}
t = clock() - t; 

FILE *fp = fopen("idfttime.dat", "w");
	if (!fp) {
		printf("Couldn't open file\n");
	}
	fprintf(fp, "%f\n", ((double)t)/CLOCKS_PER_SEC);
	fclose(fp);
createDat("ynreal.dat",N,ynr);

free(ynr);
free(yni);
free(Yi);
free(Yr);
    return 0;
}