#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void base2(int numero, int *array){
  int aux = 3;
  int n= 0;
  while(numero > 0){
    aux = numero%2;

    if(aux == 1 ){
      array[n] = 1; 
      printf("divisao = %d/2\n Resto = %d\n",numero,aux);
    }if( aux == 0){      
      array[n] = 0;
      printf("divisao = %d/2\nResto = %d\n",numero,aux);
    }
    numero = numero/2;
    n = n+1;
     
  }
  printf("\nSeu numero em binario =");
  for(int i = n-1; i >= 0 ; i--){
    printf("%d",array[i]);
  }
  printf("\n");
}

void base8(int numero){
  int array[32];
  int aux;
  int n= 0;
  while(numero > 0){
    aux = numero%8;
    
    printf("\ndivisao = %d/8\nResto = %d",numero,aux);
    array[n] = aux;
    n = n+1;
    numero = numero/8;


  }
  printf("\nSeu numero em octal = ");
  for(int i = n-1; i >= 0 ; i--){
    printf("%d",array[i]);
  }
}

int main(void) {
  int numero;
  int array[32];
  
  printf("Digite um numero e ele sera transformado em         binario, octal e hexadecimal\n");

  scanf("%d",&numero);
  printf("\nBINARIO:\n\n");
  base2(numero, array);
  printf("\nOCTAL\n");
  base8(numero);

  

  

    
  
  
}