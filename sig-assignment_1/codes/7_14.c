#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include <time.h>
#include "header2.h"

int main() {
	srand(time(0));
	FILE *fft_times = fopen("fft_times.dat", "w");
	FILE *conv_times = fopen("conv_times.dat", "w");
	for (int n = 2; n < 10000; n *= 2) {
		double complex *x = malloc(n * sizeof(*x));
		double complex *h = malloc(n * sizeof(*h));
		for (int i = 0; i < n; i++) {
			x[i] = rand();
			h[i] = rand();
		}

		clock_t fft_begin = clock();
		double complex *X = fft(x, n);
		double complex *H = fft(h, n);
		double complex *Y = malloc(n * sizeof(*Y));
		for (int i = 0; i < n; i++)
			Y[i] = X[i] * H[i];
		double complex *y = ifft(Y, n);
		clock_t fft_end = clock();
		fprintf(fft_times, "%lf\n", (double)(fft_end - fft_begin) / CLOCKS_PER_SEC);
	
		clock_t conv_begin = clock();
		double complex *y2 = convolution(x, n, h, n);
		clock_t conv_end = clock();
		fprintf(conv_times, "%lf\n", (double)(conv_end - conv_begin) / CLOCKS_PER_SEC);
	}
	fclose(fft_times);
	fclose(conv_times);
	return 0;
}
