#include <stdio.h>
#include <math.h>
#define N 4

int main(){

  float A[N][N];
  float b[N];
  int i, j, k;

  void swap(float*, float*); //下に定義したswap関数の宣言

  for(i=0; i<N; i++){
    for(j=0; j<N; j++){
      printf("A[%d][%d] = ", i+1, j+1);
      scanf("%f", &A[i][j]);
    }
    printf("b[%d] = ", i+1);
    scanf("%f", &b[i]);
    printf("\n");
  }

  float M;
  float t;
  int m, memo;

  for(k=0; k<N-1; k++){　//各列の絶対値最大の成分探し
    M = fabs(A[k][k]);  //とりあえず対角成分が、絶対値が最大ということにする（ピボットより下を探していくので）
    memo = k;　　　　　　//絶対値が最大の成分の行数を記憶
    for(m=k+1; m<N-1; m++){    //A_kkの下の成分を探していく
      if(M < fabs(A[m][k])){　　　//さらに絶対値が大きいものが見つかればMとmemoを更新
        memo = m;
        M = fabs(A[m][k]);
      }
    }
    swap(&b[k], &b[memo]);　　　//swap関数で行の交換
    for(m=k; m<N; m++){
      swap(&A[k][m], &A[memo][m]);
    }
      for(i=k+1; i<N; i++){
        t = (float)A[i][k]/A[k][k];
          for(j=k; j<N; j++){
            A[i][j] = A[i][j] - (float)t*A[k][j];
          }
          b[i] = b[i] - (float)t*b[k];
      }
  }

  float x[N];
  x[N-1] = (float)b[N-1]/A[N-1][N-1];
   for(i=N-2; i>=0; i--){
     float sum = b[i];
     for(j=N-1; j>i; j--){
       sum =  (float)sum - A[i][j]*x[j];
     }
     x[i] = (float)sum/A[i][i];
  }

  for(i=0; i<N; i++){
     printf("x_%d = %f\n", i+1, x[i]);
  }

  return 0;
}

void swap(float *x, float *y){　//swap関数（入れ替え関数）の定義
  float temp;
  temp = *y;
  *y = *x;
  *x = temp;

}
