#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>
complex W(int k ,int N){
    return cos((2*M_PI*k)/N) - I*sin((2*M_PI*k)/N) ;
}
float h(int n){
    if(n<0){
        return 0 ;
    }
    else if(n>=0 & n < 2){
        return pow(-0.5,n) ;
    }
    return 5*(pow(-0.5,n)) ;
}
complex fft(int k ,int a[],int n,int N){
    if(n == 1){
        return a[0] ;
    }
    int e[n/2] ;
    int o[n/2] ;
    for(int i = 0 ;i < n ;i++){
        if(i%2 == 0){
            e[i/2] = a[i] ;
        }
        else{
            o[(i-1)/2] = a[i] ;
        }
    }
    return fft(k,e,n/2,N)+W(k,n)*fft(k,o,n/2,N) ;
}
complex ifft(int k ,complex a[],int n,int N){
    if(n == 1){
        return a[0] ;
    }
    complex e[n/2] ;
    complex o[n/2] ;
    for(int i = 0 ;i < n ;i++){
        if(i%2 == 0){
            e[i/2] = a[i] ;
        }
        else{
            o[(i-1)/2] = a[i] ;
        }
    }
    return (ifft(k,e,n/2,N)+W(-k,n)*ifft(k,o,n/2,N)) ;
}
float convolution(int k , int a[]){
    int t = 0 ;
    float y = 0 ;
    while(t <= k){
        y = y + a[t]*h(k-t) ;
        t++ ;
    }
    return y ;
}
int main(){
    int n = 8;
	int a[8] = {1,2,3,4,2,1,0,0} ;
    complex b[8] ;
    for(int i = 0 ;i < 8 ; i++){
    b[i] = fft(i,a,8,8) ;
    printf("%lf %lf\n",creal(b[i]),cimag(b[i]));
    }
    int X[8] ;
    for(int i=0;i<8;i++){
        X[i]=(ifft(i,b,8,8)/7);
        // printf("%lf %lf \n",creal(X[i]),cimag(X[i]));
    }
}


