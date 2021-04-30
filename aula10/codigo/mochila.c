#include<stdio.h>
#include<stdlib.h>

#define max(a,b) ( (a>b)? a : b )

int **aloca_matriz(int linhas, int colunas){
  int **m = (int **) calloc(linhas, sizeof(int *));

  for (int i = 0; i < linhas; i++)
    m[i] = (int *)calloc(colunas, sizeof(int));   

  return m;
}

void desaloca_matriz(int **m, int linhas){
  for (int i = 0; i < linhas; i++)
    free(m[i]);
  free(m);
} 

void mostra_matriz(int **m, int linhas, int colunas){
  for (int i = 0; i <= linhas; i++){
    for (int j = 0; j <= colunas; j++){
	    printf("%3d ", m[i][j]);
    }
    printf("\n");
  }
}

int calcula_valor_mochila_booleana(int w[], int v[], int n, int W){
  int **t = aloca_matriz(n+1, W+1);
  int resultado, a, b;  
  for (int i = 1; i <= n; i++){
    t[i][0] = 0;
    for (int Y = 1; Y <= W; Y++){
      t[0][Y] = 0;
      a = t[i-1][Y];
      if (w[i] > Y) b = 0;
      else          b = t[i-1][Y - w[i]] + v[i];
      t[i][Y] = max(a,b);
    }
  }
  mostra_matriz(t, n, W);
  resultado = t[n][W];
  desaloca_matriz(t, n+1);
  return resultado;
}

int main(){
   int n = 4, W = 5;

  int w[5] = {0, 4, 2, 1, 3};
  int v[5] = {0, 500, 400, 300, 450};

  int resultado = calcula_valor_mochila_booleana(w, v, n, W);
  printf("resultado = %d\n", resultado);

}
