/* Contador de palavras
 *
 * Este programa recebera uma serie de caracteres representando palavras em sua
 * entrada. Ao receber um caractere fim de linha ('\n'), deve imprimir na tela o
 * numero de palavras separadas que recebeu e, apos, encerrar.
 */

#include <stdio.h>

int numEspacos(char *frase){
  int i=1;
  int contador=0;
  while(frase[i]!='\0'){
    if((frase[i]==' ' && frase[i-1] !=' ') || (frase[i]=='\n' && frase[i-1] !=' ') ){
      contador++;
    }
    i++;
  }
  return contador;
}

int numEntrePontos(char *frase){
  int i=1;
  int contador=0;
  while(frase[i]!='\0'){
    if(((frase[i-1] !=' ' && frase[i-1] !='.' && frase[i-1] !=',' ) && (frase[i]=='.' || frase[i]==','|| frase[i]=='-') && (frase[i+1] !=' '&& frase[i+1] !='.'&& frase[i+1] !=','&& frase[i+1] !='-'&& frase[i+1] !='\0')) || ((frase[i-1] !=' '&& frase[i-1] !=',' && frase[i-1] !='-') && (frase[i]=='.' || frase[i]==','|| frase[i]=='-') && (frase[i+1] !=' ' && frase[i+1] !='.' && frase[i+1] !=',' && frase[i+1] !='-' && frase[i+1] !='\0'))){
      contador++;
    }
    i++;
  }
  return contador;
}

int temErro(char *frase){
  int i=1;
  int contador=0;
  while(frase[i]!='\0'){
    if((frase[i-1]=='.' && frase[i]==',' && frase[i+1]=='.') || (frase[i-1]==',' && frase[i]=='.' && frase[i+1]==',') || (frase[i-1]=='.' && frase[i]=='-' && frase[i+1]=='.')){
      contador=contador +1;
    }
    
    if(frase[i]=='.' && frase[i+1]=='\0'){
      contador=contador +1;
    }
    
    i++;
  }
  
  return contador;
}

int ehNumero(char c){
  int retorno=0;
  if(c=='0' || c=='1' || c=='2' || c=='3' || c=='4' || c=='5' || c=='6' || c=='7' || c=='8' || c=='9'){
    retorno=1;
  }
  return retorno;
}

int entreNumeros(char *frase){
  int i=1;
  int contador=0;
  while(frase[i]!='\0'){
    if((ehNumero(frase[i-1])==1 && (frase[i]==',' || frase[i]=='.') && ehNumero(frase[i+1])==1)){
      contador++;
    }
    
    if(frase[i]=='.' && frase[i+2]=='\0'){
      contador=contador +1;
    }
    i++;
  }
  return contador;
}




int main() {

  char c, frase[500];
  int numeroDePalavras =0, i=0, espacos=0, entrePontos=0, erro=0, erroNumeros=0;

  c = 1;

  while(c != '\n'){
    scanf("%c", &c);
    frase[i]=c;
    i++;
  }
  
  frase[i]='\0';
  
  
  espacos = numEspacos(frase);
  entrePontos = numEntrePontos(frase);
  erro = temErro(frase);
  erroNumeros = entreNumeros(frase);
  
  
  numeroDePalavras =espacos + entrePontos - erro - erroNumeros;
 
  printf("%i\n",numeroDePalavras);
  return 0;
}
