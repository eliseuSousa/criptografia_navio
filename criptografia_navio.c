#include <stdio.h>

void inverterBit(int indice, char *buffer) {
  if(buffer[indice] == '0') {
      buffer[indice] = '1';
  } 
  else {
    buffer[indice] = '0';
  }
}

void ordenarBuffer(char *buffer) {
  char bufferAux[4];
  for(int i = 0; i < 8; i++) {
    if(i < 4) {
      bufferAux[i] = buffer[i];
    } else {
      buffer[i - 4] = buffer[i];
      buffer[i] = bufferAux[i -4];
    }
  }
}

int potencia(int base, int expoente) {
    int resultado = 1;

    for (int i = 0; i < expoente; i++) {
        resultado *= base;
    }

    return resultado;
}

int bin2dec(char *buffer) {
  int resultado = 0;
  int indice = 7;
  for(int i = 0; i < 8; i++) {
    if(buffer[i] == '1') {
      resultado += potencia(2, indice);
    }
    indice--;
  }

  return resultado;
}

int main() {

  char mensagemCriptografada[] = "10010110 11110111 01010110 00000001 00010111 00100110 01010111 00000001 00010111 01110110 01010111 00110110 11110111 11010111 01010111 00000011";

  char buffer[8];
  
  int count = 0; 

  while (count < sizeof(mensagemCriptografada)) {

    for(int i = 0; i < 9; i++) {

      if(mensagemCriptografada[i] != ' ') {

        buffer[i] = mensagemCriptografada[count];

        if(i == 6 || i == 7) {
          inverterBit(i, buffer);
        }
    
      }
      count++;
    }
    
    ordenarBuffer(buffer);
    printf("%c", bin2dec(buffer));
  }  
}