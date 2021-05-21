#include<stdio.h>
#include<stdlib.h>


int check_prime(int n){

  int check = 0;

  for(int i = 2; i < n/2; i++){
    if( n % i == 0){
      check = 1;
      return check;
    }
  }
  return check;
}


int main(int argc, char** argv){

  if(argc != 2){
    printf("insufficient argument");
    exit(0);
  }

  FILE* fp = fopen(argv[1], "r");
  if(fp == NULL){
    printf("file does not exist\n");
    exit(0);
  }

  int num = 0;
  if(fscanf(fp, "%d", &num) == EOF){
    printf("empty file\n");
    exit(0);
  }

  for(int i = 0; i < num; i++){
    int check = 0;
    int temp = 0;
    fscanf(fp, "%d\n", &temp);
    //printf("The number is %d\n", temp);
    while(temp != 0){
      check = check_prime(temp);
      if(check == 1){
	printf("no\n");
	break;
      }
      temp /= 10;
      //printf("%d\n", temp);
    }
    if( check == 0){
      printf("yes\n");
    }
  }
  fclose(fp);
  return 0;
}
