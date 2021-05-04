#include <stdio.h>
#include <math.h>
#define f(x) (5*(2-x)*x)
#define g(y) (2/(1+49*exp(-10*y)))

int main(){

  void Euler(double, double, double, double, int);
  void Class_RK(double, double, double, double, int);

   int N;
    printf("分割数N = ");
    scanf("%d", &N);

    Euler(0.0, 0.04, 0.0, 1.0, N);
    Class_RK(0.0, 0.04, 0.0, 1.0, N);

  return 0;
}

void Euler(double t, double u, double a, double b, int n){
  double dt = (double)(b-a)/n;
  int i;
  double E_den, E_num;
  E_den = fabs(u);
  E_num = fabs(g(t)-u);

  for(i=0; i<=n; i++){
    u = u + dt*f(u);
    t = t + dt;
    if(E_den<fabs(u))
    E_den = fabs(u);
    if(E_num<fabs(g(t)-u))
    E_num = fabs(g(t)-u);
  }
  printf("E(Δt) of Euler = %f\n", E_num/E_den);
}

void Class_RK(double t, double u, double a, double b, int n){
  double dt = (double)(b-a)/n;
  int i;
  double k[4];
  double E_den, E_num;
  E_den = fabs(u);
  E_num = fabs(g(t)-u);

  for(i=0; i<=n; i++){
    k[0] = f(u);
    k[1] = f(u + dt*k[0]/2);
    k[2] = f(u + dt*k[1]/2);
    k[3] = f(u + dt*k[2]);
    u = u + dt*(k[0] + 2*(k[1] + k[2]) + k[3])/6;
    t = t + dt;
    if(E_den<fabs(u))
    E_den = fabs(u);
    if(E_num<fabs(g(t)-u))
    E_num = fabs(g(t)-u);
  }
  printf("E(Δt) of Runge-Kutta = %f\n", E_num/E_den);
}
