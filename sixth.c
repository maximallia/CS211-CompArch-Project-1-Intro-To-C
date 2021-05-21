#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int checkV(char ch);

int checkV(char ch){
  int flag = 1; // false
  if( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
      ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'){
    flag = 0; // true
  }
  return flag;
}


int main(int argc, char** argv){
 
  //int flag;
  for(int i = 1; i<argc; i++){
    int j = 0;
    int stop = 0;
    while(argv[i][j]){
      if(checkV(argv[i][j])==0 ){
	stop = j;
	break;
      }
      j++;
    }

    int stop2 = stop;
    while(argv[i][stop2]){
      printf("%c", argv[i][stop2]);
      stop2++;
    }
    j = 0;
    while(j != stop){
      printf("%c", argv[i][j]);
      j++;
    }
    if(stop == 0){
      printf("yay");
    }
    else{
      printf("ay");
    }
    printf(" ");
  }
  return 0;
}
