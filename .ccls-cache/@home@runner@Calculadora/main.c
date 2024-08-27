#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int base2(int numero, int *array){
  int aux = 3;
  int n= 0;
  if(numero < 0){
    numero = numero*-1;
  }
  while(numero > 0 ){
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
  return n;
}

void base8(int numero){
  int array[32];
  int aux;
  int n= 0;
  if(numero < 0){
    numero = numero*-1;
  }
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
  printf("\n");
}

void base16(int numero){
  char array[32];
  int aux;
  char numeroAlterado;
  int n= 0;
  if(numero < 0){
    numero = numero*-1;
  }
  while(numero > 0){
    aux = numero%16;

    if(aux < 10 ){
      array[n] = '0' + aux;
      printf("divisao = %d/16 \n resto = %d\n",numero, aux);
    }
    else{
      array[n] = 'A' + (aux-10);
      printf("divisao = %d/16 \n resto = %d\n",numero, aux);
    }
    n = n+1;
    numero = numero/16;


  }
  printf("\nSeu numero em hexadecimal = ");
  for(int i = n-1; i >= 0 ; i--){
    printf("%c",array[i]);
  }
  printf("\n");
}


void BCD(int numero){
  int array[128];
  int aux;
  int n= 0;
  if(numero < 0){
    numero = numero*-1;
  }
  while(numero > 0){
    
    aux = numero%10;

    switch(aux){
      case 0:
        
        array[n++] = 0;
        array[n++] = 0;
        array[n++] = 0;
        array[n++] = 0;
        break;
      case 1:
        array[n++] = 1;
        array[n++] = 0;
        array[n++] = 0;
        array[n++] = 0;
        break;
      case 2 :
        array[n++] = 0;
        array[n++] = 1;
        array[n++] = 0;
        array[n++] = 0;
        break;
      case 3:
        array[n++] = 1;
        array[n++] = 1;
        array[n++] = 0;
        array[n++] = 0;
        break;
      case 4:
        array[n++] = 0;
        array[n++] = 0;
        array[n++] = 1;
        array[n++] = 0;
        break;
      case 5:
        array[n++] = 1;
        array[n++] = 0;
        array[n++] = 1;
        array[n++] = 0;
        break;
      case 6:
        array[n++] = 0;
        array[n++] = 1;
        array[n++] = 1;
        array[n++] = 0;
        break;
      case 7:
        array[n++] = 1;
        array[n++] = 1;
        array[n++] = 1;
        array[n++] = 0;
        break;
      case 8:
        array[n++] = 0;
        array[n++] = 0;
        array[n++] = 0;
        array[n++] = 1;
        break;
      case 9:
        array[n++] = 1;
        array[n++] = 0;
        array[n++] = 0;
        array[n++] = 1;
        break;
    }
    printf("divisao = %d/10 \n resto = %d\n",numero, aux);
    numero = numero/10;

  }
  printf("\nSeu numero em BCD = ");
  for(int i = n-1; i >= 0 ; i--){
    printf("%d",array[i]);
  }
  printf("\n");
}

void a2(int *array, int n, int numero){
  int posi = 0;
  int arrayA2[32];
  int c = 0;

  if(numero < 0){
    arrayA2[0] = 1;
  }else if(numero > 0){
    arrayA2[0] = 0;
  }
  for(int i = 0 ; i <= n ; i++){
      if(posi == 0){
        arrayA2[c+1] = array[i];
      }else if(posi ==1){
        if(array[i] == 1){
          arrayA2[c+1] = 0;
        }else{
          arrayA2[c+1] = 1;
        }
       
      }
    if(array[i] == 1){
      posi = 1;
    }
      c++;
    }
  for(int i = 0; i <= c-1 ; i++){
    printf("%d",arrayA2[i]);
    }
  
} 

int main(void) {
  int numero;
  int array[32];
  
  printf("Digite um numero e ele sera transformado em         binario, octal e hexadecimal\n");

  scanf("%d",&numero);
  printf("\nBINARIO:\n\n");
  int n = base2(numero, array);
  printf("\nOCTAL\n");
  base8(numero);
  printf("\nHEXADECIMAL\n");
  base16(numero);
  printf("\nBCD\n\n");
  BCD(numero);

  printf("\nComplemento A2\n");
  a2(array,n,numero);
      
  
}