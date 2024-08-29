#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int base2(float numero1, int *array){
  int aux = 3;
  int n= 0;
  int numero = (int)trunc(numero1);
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

void base8(float numero1){
  int array[32];
  int aux;
  int n= 0;
  int numero = (int)trunc(numero1);
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

void base16(float numero1){
  char array[32];
  int aux;
  char numeroAlterado;
  int n= 0;
  int numero = (int)trunc(numero1);

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


void BCD(float numero1){
  int array[128];
  int aux;
  int n= 0;
  int numero = (int)trunc(numero1);

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

void a2(int *array, int n, float numero){
  int posi = 0;
  int arrayA2[32];
  int c = 0;

  if(numero < 0){
    printf("\nNumero Negativo recebe 1\n ");
    arrayA2[0] = 1;
  }else if(numero > 0){
    printf("\nNumero Positivo recebe 0\n ");
    arrayA2[0] = 0;
  }
  for(int i = 0 ; i <= n ; i++){
      if(posi == 0){
        arrayA2[c+1] = array[i];
        printf("\nainda nao achou o 1 para realizar a troca\n");
        printf("\nA2 esta recebendo %d do binario sem troca\n" ,array[i]);
      }else if(posi ==1){
        if(array[i] == 1){
          printf("\nA2 esta recebendo %d do binario esta sendo trocado por 0\n" ,array[i]);
          arrayA2[c+1] = 0;
        }else{
          printf("\nA2 esta recebendo %d do binario esta sendo trocado por 1\n" ,array[i]);
          arrayA2[c+1] = 1;
        }


        
       
      }
    if(array[i] == 1 && posi <= 0 ){
      posi += 1;
      printf("\nprimeiro um achado a troca sera realizada\n");
    }
      c++;
    }
  printf("\nSeu numero em complemento A2 = ");
  printf("%d.",arrayA2[0]);

  for(int i = c-1; i >= 1 ; i--){
    printf("%d",arrayA2[i]);
    }
  printf("\n");
} 

void FloatDouble(float numero, int *array,int n){
  float numeroaux = (float)trunc(numero);
  int c = 0,f = 0;
  int arrayFl[32];
  int arrayFr[27];

  float numeroFrancionado = numero - numeroaux; 

  if(numero < 0 ){
    arrayFl[0] = 1;
  }else{
    arrayFl[0] = 0;
  }

  for(int i = 0 ; i <= n ; i++){
      arrayFl[c+1] = array[i];
      c++;
    }

  while(numeroFrancionado > 0 && f <= 32){
    numeroFrancionado = numeroFrancionado*2;
    
    int bit = (int)trunc(numeroFrancionado);

    arrayFr[f++] = bit;
    numeroFrancionado = numeroFrancionado- bit;
  }
  if( f >= 32 ){
    while(numeroFrancionado > 0 && f <= 32){
      numeroFrancionado = numeroFrancionado*2;

      int bit = (int)trunc(numeroFrancionado);

      arrayFr[f++] = bit;
      numeroFrancionado = numeroFrancionado- bit;
    }
      printf("Representacao DOUBLE :");
      printf("%d",arrayFl[0]);
        printf(".");
      for(int i = c-1; i >= 1 ; i--){
        printf("%d",arrayFl[i]);
      }
      if( f > 0){
        printf(".");
      }
      for(int i = 0; i <= f-1 ; i++){
        printf("%d",arrayFr[i]);
      }
      printf("\n");
  }
    printf("%d",arrayFl[0]);
    printf(".");
  for(int i = c-1; i >= 1 ; i--){
    printf("%d",arrayFl[i]);
    }
  if( f > 0){
    printf(".");
  }
  for(int i = 0; i <= f-1 ; i++){
    printf("%d",arrayFr[i]);
    }
  
} 

int main(void) {
  float numero;
  int array[32];
  
  printf("Digite um numero e ele sera transformado em         binario, octal e hexadecimal\n");

  scanf("%f",&numero);
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
  
  printf("\nRepresentacao Float Double \n");
  FloatDouble(numero,array,n);
}