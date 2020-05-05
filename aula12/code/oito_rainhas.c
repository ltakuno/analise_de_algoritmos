#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

#define N 4


void mostra_matriz(char tabuleiro[][N]){
   for (int i = 0; i < N; i++) {
     for (int j = 0; j < N; j++) {
        printf("%c ", tabuleiro[i][j]);     
     }
     printf("\n");
   }

   exit(1);
}

bool esta_salva(char tabuleiro[][N], int linha, int coluna){
   int i, j;
   // verificar a linha	
   for (i = 0; i < coluna; i++) 
	  if (tabuleiro[linha][i] == 'Q')
		 return false;
   
   // verificar a diagonal 
   for (i = linha, j = coluna; i >= 0 && j >= 0; i--, j--)
	   if (tabuleiro[i][j] == 'Q')
		   return false;
 
   // verifica a diagonal /
   for (i = linha, j = coluna; i < N && j > 0; i++, j--)
	   if (tabuleiro[i][j] == 'Q')
		   return false;
   return true;
}

void oito_rainhas(char tabuleiro[][N], int coluna) {
   if (coluna == N) mostra_matriz(tabuleiro);
   else { 
      for (int i = 0; i < N; i++) {
          if (esta_salva(tabuleiro, i, coluna)){
	     tabuleiro[i][coluna] = 'Q';
             oito_rainhas(tabuleiro, coluna + 1);
	     tabuleiro[i][coluna] = '-';
	  }
      }
   }

}  

int main(int argc, char *argv[]) {
   char tabuleiro[N][N];
   memset(tabuleiro, '-', sizeof tabuleiro);
   oito_rainhas(tabuleiro, 0);
   return 0;
}
