#include <stdio.h>
#include <math.h>
#include <complex.h>
#include <time.h>
 
double PI;
typedef double complex cplx;
 
void _fft(cplx buf[], cplx out[], int n, int step)
{
	if (step < n) {
		_fft(out, buf, n, step * 2);
		_fft(out + step, buf + step, n, step * 2);
 
		for (int i = 0; i < n; i += 2 * step) {
			cplx t = cexp(-I * PI * i / n) * out[i + step];
			buf[i / 2]     = out[i] + t;
			buf[(i + n)/2] = out[i] - t;
		}
	}
}
 
void fft(cplx buf[], int n)
{
	cplx out[n];
	for (int i = 0; i < n; i++) out[i] = buf[i];
 
	_fft(buf, out, n, 1);
}
 
 
void ifft(cplx buf[],int n){
for (int i = 0; i < n; i++){
	buf[i]=conj(buf[i]);
	buf[i]/=n;
}
}

void show(const char * s, cplx buf[]) {
	printf("%s", s);
	for (int i = 0; i < 8; i++)
		if (!cimag(buf[i]))
			printf("%g ", creal(buf[i]));
		else
			printf("(%g, %g) ", creal(buf[i]), cimag(buf[i]));
}

int main()
{
	PI = atan2(1, 1) * 4;
	cplx buf[] = {1, 2,3,4,2,1,0,0};
 
	show("Data: ", buf);
    clock_t t;
    t = clock();
	fft(buf, 8);
	//ifft(buf,8);
    t = clock() - t;
	show("\nFFT : ", buf);
 

 FILE *fp = fopen("totalffttimect.dat", "w");
	if (!fp) {
		printf("Couldn't open file\n");
	}
	fprintf(fp, "%f\n", ((double)t)/CLOCKS_PER_SEC);
	fclose(fp);
	return 0;
}