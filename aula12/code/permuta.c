#include<stdio.h>

void mostra_vetor(int v[], int n){
    for (int i = 0; i < n; i++) { 
       printf("%d", v[i]);
    } 
    printf("\n");
}

void permuta(int v[], int i, int a[], int n, int x[]){
   if (i == n){
      mostra_vetor(v, n);
   } else { 
      for (int j = 0; j < n; j++) {
	 if (x[j] == 0) {     
            x[j] = 1;		 
            v[i] = a[j];
	    permuta(v, i + 1, a, n, x);
            x[j] = 0;
	 }
      } 
   }
}

int main(int argc, char *argv){

   int a[3] = {1, 2, 3};
   int n = 3;
   int v[3];
   int x[3] = {0,0,0};   
   permuta(v, 0, a, n, x);
}
