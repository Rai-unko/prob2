#include <stdio.h>
#include <math.h>

int main(){

  void Euler(double, double, double, double, int);

   int N;
    printf("分割数N = ");
    scanf("%d", &N);

    Euler(0.0, 0.04, 0.0, 1.0, N);

  return 0;
}

void Euler(double t, double u, double a, double b, int n){
  double dt = (double)(b-a)/n;
  int i;

  for(i=0; i<=n; i++){
    printf("t = %f, u = %f\n", t, u);
    u = u + dt*5*(2 - u)*u;
    t = t + dt;
  }
}
