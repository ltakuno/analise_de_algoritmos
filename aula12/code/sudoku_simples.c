#include<stdio.h>


void mostra_matriz(int m[4][4]){
   for (int i = 0; i < 4; i++) {
	  for (int j = 0; j < 4; j++) {
	     printf("%d ",m[i][j]); 
	  } 
	  printf("\n");
   }
}

int valor_valido(int valor, int m[4][4], int l, int c) {
   for (int i = 0; i < 4; i++) {
      if (m[l][i] == valor || m[i][c] == valor)
	      return 0;
   }
   return 1;
}



void sudoku(int m[4][4], int l, int c){
   if (c == 4){
      l = l + 1;
      c = 0;
   }

   if (l == 4)
      mostra_matriz(m);
   else {
      if (m[l][c] > 0)
         sudoku(m, l, c+1);
      else {
         for (int i = 1; i <= 4; i++){
	    if (valor_valido(i, m, l, c)){
	       m[l][c] = i;
	       sudoku(m, l, c + 1);
	    }
         }
      }
   }
} 

int main(int argc, char *argv[]) {

   int m[4][4] = {{0, 2, 4, 0}, 
	          {1, 0, 0, 3}, 
		  {4, 0, 0, 2}, 
		  {0, 1, 3, 0}};
   
   sudoku(m, 0, 0);
   return 0;
}
