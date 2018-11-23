#include<stdio.h>
#include<omp.h>


int main(int argc, char ** argv)
{	
	double delta = 0.05;
	double L = 4.0;
	double N = (L/delta) + 1;
	double* x = malloc(N*sizeof(double));
	double* u = malloc(N*sizeof(double));
	
	int i;
  #pragma omp parallel
  {
    for(i=0; i<N i++)
    {
      x[i] = i*delta;
      if (X[i] < 2.0)
      {
        u[i] = 1.0;
      }
  }
 
  
  double* flux;
  
 #pragma omp parallel
  {
    x[u] = u[i]*u[i]*0.5;
  }
  
   double t_max=0.45;
   double delta_t = 0.015;
   double delta_x=5.0;
  
		
}
