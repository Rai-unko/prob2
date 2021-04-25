#include <stdio.h>
#define N 4

int main(){
  float A[N][N];
  float b[N];
  int i, j, k;

  for(i=0; i<N; i++){
    for(j=0; j<N; j++){
      printf("A[%d][%d] = ", i+1, j+1); //係数行列とベクトルbの入力
      scanf("%f", &A[i][j]);
    }
    printf("b[%d] = ", i+1);
    scanf("%f", &b[i]);
    printf("\n");
  }

  float t; //基本変形で0を作るための倍率tの宣言

  for(k=0; k<N-1; k++){
    for(i=k+1; i<N; i++){
      t = (float)A[i][k]/A[k][k]; //tはピボットを作る列毎、または各行毎に変わるのでここで定義
      for(j=k; j<N; j++){
        A[i][j] = A[i][j] - (float)t*A[k][j];　//基本変形
      }
      b[i] = b[i] - (float)t*b[k];
    }
  }

float x[N];
x[N-1] = (float)b[N-1]/A[N-1][N-1]; //最初にx_(N-1)を求めておく。
 for(i=N-2; i>=0; i--){
   float sum = b[i];
   for(j=N-1; j>i; j--){
     sum =  (float)sum - A[i][j]*x[j];　//x_jを代入、移項を繰り返してx_iの項を孤立させる
   }
   x[i] = (float)sum/A[i][i];　//x_iの係数で両辺割ってx-iを求める。

 }
for(i=0; i<N; i++){
   printf("x_%d = %f\n", i+1, x[i]);　//解の表示
}

return 0;
}
