double *readData(char *file, int size) ;
void createDat(char *file, int count,double *y);
double delta(int n);
double hnthroughdef(int n);

// Reads data from file into array and returns the array
double *readData(char *file, int size) {
	double *data = (double *)malloc(size * sizeof(double));
	FILE *fp = fopen(file, "r");
	if (!fp) {
		printf("Couldn't open file\n");
		return NULL;
	}
	for (int i = 0; i < size; i++) {
		fscanf(fp, "%lf", &data[i]);
	}
	fclose(fp);
	return data;
}

//Creates a Data file
void createDat(char *file, int count,double *y) {
	FILE *fp = fopen(file, "w");
	if (!fp) {
		printf("Couldn't open file\n");
		return;
	}
	for (int i = 0; i < count; i++) {
		fprintf(fp, "%lf\n", y[i]);
	}
	fclose(fp);
	return;
}

//Unit Sample Sequence
double delta(int n){
	if(n==0){
	  return 1;
}
	else {
	 return 0;  
	}
}

//Calculating h(n) through given definition
double hnthroughdef(int n){
	if(n<0) {
		return 0;
	}
	else {
		return delta(n)+delta(n-2)-(0.5*hnthroughdef(n-1));
	}
}