#include<stdio.h>
#include<stdlib.h>

#define INFINITO 32767

int **aloca_matriz(int linhas, int colunas){
  int **m = (int **)calloc(linhas, sizeof(int *));
  for (int i = 0; i < linhas; i++)
    m[i] = (int *) calloc(colunas, sizeof(int));
  return m;
}

void desaloca(int linhas, int **m){
  for (int i = 0; i < linhas; i++)
    free(m[i]);
  free(m); 
}

void mostra_matriz(int **m, int linhas, int colunas){
  for(int i=0; i <= linhas; i++){
    for(int j=0; j <= colunas; j++){
       printf("%d ", m[i][j]);
    }
    printf("\n");
  }
}

int calcula_total_moedas(int P, int n, int c[]){
  int **m = aloca_matriz(n+1, P+1); 
  int resultado = 0;	
  for (int i = 0; i <= n; i++) m[i][0] = 0;
  for (int i = 1; i <= P; i++) m[0][i] = INFINITO;
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= P; j++){
      if (c[i] > j) m[i][j] = m[i-1][j];
      else {
        if (m[i-1][j] < m[i][j-c[i]] + 1) m[i][j] = m[i-1][j];
	else m[i][j] = m[i][j-c[i]] + 1;
      } 
    }
  }
    
  resultado = m[n][P];
  mostra_matriz(m, n, P);
  desaloca(n, m);

  return resultado;
}

int main(){
  int P = 8, n = 3;
  int c[4] = {0,2,4,6};


  int total = calcula_total_moedas(P, n, c);
  printf("total de moedas: %d\n", total);

  return 0;
}


