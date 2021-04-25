#include <stdio.h>
#include <math.h>
#include <float.h>  //あとで計算機イプシロンを使うので
#define N 10  //なんでもいいけどなんとなくN=10

int main(){

printf("現在 N = %d　です。\n", N); //別にいらない

  double inpro(double [N], double [N]); //内積関数の宣言
  double norm(double [N]);  //ノルム関数の宣言

  float A[N][N];
  float b[N];
  int i, j, k, l;

  for(i=0; i<N; i++){  //数列Aの入力
    for(j=0; j<N; j++){
      if(j==i-1||j==i+1){　//対角成分の真横だったら-1
        A[i][j] = -1;
      }else if(i==j){  //対角成分は2
        A[i][j] = 2;
        if(i==N-1){
          A[N-1][N-1] = 1;  //ただしA_[9][9]は1
        }
      }else{
        A[i][j] = 0;  //それ以外は0
      }
    }
    if(i==N-1){ //ベクトルb b_9は1 それ以外0
      b[i] = 1;
    }else{
    b[i] = 0;
    }
  }

  double x[N];
  for(i=0; i<N; i++){ //解xの初期値を設定 なんでも良さそう
  x[i] = 0;
  if(i==N-1)
  x[i] = 1;
  }

  double r[N]; //ベクトルr
  double Ax[N]; //A*xの結果　一つのベクトルとしてここで宣言

    for(j=0; j<N; j++){　//ベクトルA*xの定義
      Ax[j] = 0;
      for(k=0; k<N; k++){
        Ax[j] += A[j][k]*x[k];
      }
      r[j] = b[j] - Ax[j];
    }


  double beta;　//スカラーβ
  double p[N]; //ベクトルp

  double alpha;  //スカラーα
  double Ap[N];  //A*pの結果 一つのベクトルとしてここで宣言
  double temp[N];  //βを更新するときに、古いrの情報が必要になるのでそれを保存するやつ

  for(i=0; ; i++){　//元々は数列の添字としてiを使うつもりだったけど、使ってないからほったらかし while文のがいいかも
    if(norm(r)< FLT_EPSILON){  // 繰り返しを止める条件
      break;
    }else{

      for(j=0; j<N; j++){ //ベクトルpを各成分ごとに定義
        if(i==0){
          p[j] = r[j];  //βの初期値が0なので簡単にした（pの初期値を定義しなくて良くなる）
        }else{
        p[j] = r[j] + beta*p[j];
      }
    }

        for(k=0; k<N; k++){  //A*pの計算
          Ap[k] = 0;
          for(l=0; l<N; l++){
            Ap[k] += A[k][l]*p[l];
          }
        }

      alpha = (double)inpro(r, r)/inpro(p, Ap);  //αの計算

      for(j=0; j<N; j++){
        x[j] = x[j] + alpha*p[j];  // 新しい近似解xの計算
        temp[j] = r[j];  //古いrの保存
        r[j] = r[j] - alpha*Ap[j];  //rの更新
      }
      beta = (double)inpro(r, r)/inpro(temp, temp);  //βの更新
    }
  }  //以上を繰り返す

  for(i=0; i<N; i++){
    printf("x_%d = %f\n", i, x[i]);
  }

  return 0;
}

double inpro(double x[N], double y[N]){  //内積関数の定義
  double s = 0;
  for(int n=0; n<N; n++){
    s += x[n]*y[n];
  }

  return s;
}

double norm(double x[N]){  //ノルム関数の定義
  double s = 0;
  for(int n=0; n<N; n++){
    s += pow(x[n], 2);
  }
  return sqrt(s);
}
