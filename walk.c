#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int walk(double barrier, int seed);
double *reserva(int n_points);
void print(double *x, int n_points);
void exportarDatos(double* A,int n_walkers);

void main ()
{ 
  double *A;
  int i;
  int n_walkers = 500000;
  
  A = reserva(n_walkers);
  #pragma omp parallel
  {
  for (i=0; i<n_walkers; i++){
     A[i] = walk(10.0, i);
  }
  }
  exportarDatos(A,n_walkers);
}

int walk(double barrier, int seed){

  double pos;
  int n_steps;
  srand48(seed);
  pos = 0.0;
  n_steps = 0;
  do{
    pos += (drand48()-0.5) * 2.0;
    n_steps++;
  }while(fabs(pos)<barrier);

  return n_steps;
}


void print(double *x, int n_points){

  int i;
  for(i = 0 ; i < n_points ; i++)
  {
    fprintf(stdout, "%f\n", x[i]);
  }
  
 
}

double *reserva(int n_points){
  double *x;
  int i;
  if(!(x=malloc(sizeof(double) * n_points))){
    printf("malloc problem\n");
    exit(1);
}
  for(i=0;i<n_points;i++){
    x[i] = 0.0;
  }
  return x;
}

void exportarDatos(double* A, int n_points)
{
	
	FILE *arch;
	arch= fopen("walk.dat", "w");
	if (!arch)
	{
		printf("Problemas abriendo el archivos %s\n", "walk.dat" );
		exit(1);
	}

	int i;
	for (i = 0; i < n_points; ++i)
	{

		fprintf(arch, "%lf \n", A[i]);
	}

	fclose(arch);
}
