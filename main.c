#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void base2(int numero, int *array){
  int aux;
  int n= 0;
  while(numero > 0){
    aux = numero%2;
    numero = numero/2;

    if(aux == 1 ){
      array[n] = 1; 
      printf("%d\n",aux);
    }if( aux == 0){      
      array[n] = 0;
      printf("%d\n",aux);
    }
    n = n+1;
     
  }
  printf("Seu numero em binario e\n");
  for(int i = n-1; i >= 0 ; i--){
    printf("%d",array[i]);
  }
}

int main(void) {
  int numero;
  int array[32];
  
  printf("Digite um numero e ele sera transfomado em         binario, octal e hexadecimal\n");

  scanf("%d",&numero);

  base2(numero, array);

  

  

    
  
  
}