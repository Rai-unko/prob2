#include <stdio.h>
#include <math.h>
#define f(x) (5*(2-x)*x)

int main(){

  void Class_RK(double, double, double, double, int);

   int N;
    printf("分割数N = ");
    scanf("%d", &N);

    Class_RK(0.0, 0.04, 0.0, 1.0, N);

  return 0;
}

void Class_RK(double t, double u, double a, double b, int n){
  double dt = (double)(b-a)/n;
  int i;
  double k[4];

  for(i=0; i<=n; i++){
    printf("t = %f, u = %f\n", t, u);
    k[0] = f(u);
    k[1] = f(u + dt*k[0]/2);
    k[2] = f(u + dt*k[1]/2);
    k[3] = f(u + dt*k[2]);
    u = u + dt*(k[0] + 2*(k[1] + k[2]) + k[3])/6;
    t = t + dt;
  }
}
