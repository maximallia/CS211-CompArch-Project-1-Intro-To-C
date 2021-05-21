#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char** argv){


  for(int i = 1; i<argc; i++){
    int j = 0;
    while(argv[i][j]){
      j++;
    }
    printf("%c", argv[i][j-1]);
  }
  return 0;
}
