#include<stdio.h>
#include<stdlib.h>

int checkOdd(int size);
int checkSum(int** mat, int size);
void printResult(int flag);
void printMat(int** mat, int size);//check mat

int checkOdd(int size){
  int flag = 1;
  if(size%2 == 1){
    flag = 0;
    return flag;
  }
  return flag;
}


void printMat(int** mat, int size){
  for(int i = 0; i < size; i++){
    for(int j = 0; j< size; j++){
      printf("%d\t", mat[i][j]);
    }
    printf("\n");
  }
}


void printResult(int flag){
  if( flag == 0 ){
    printf("magic");
  }
  else{
    printf("not-magic");
  }
}

int checkSum(int** mat, int size){
  //int sizeSq = size * size;
  int sumM = 0;
  int flag = 0;

  int total = 0;
  //row sum
  for(int i = 0; i < size; i++){
    for(int j=0; j < size; j++){
      sumM += mat[i][j];
    }
    //printf("%d\t", sumM);
    if(total == 0){ //beginning total = 0, after total used to check
      total = sumM;
    }
    if(total != sumM){
      flag = 1;
      return flag;
    }
    sumM = 0;
  }
  //printf("\n");

  //col sum
  for(int j = 0; j < size; j++){
    for(int i = 0; i < size; i++){
      sumM += mat[i][j];
    }
    //printf("%d\t", sumM);
    if(total != sumM){
      flag = 1;
      return flag;
    }
    sumM = 0;
  }

  //printf("\n");

  sumM = total;
  total = 0;

  //diagonal sum
  int total2 = 0;
  for(int k = 0; k < size; k++){
    total += mat[k][k];
    total2 += mat[size-k-1][size-k-1]; // for idx start from 0
    //printf("%d\t", total2);
  }
  //printf("\n");
  //printf("1: %d\t2: %d\t", total, total2);
  if(total != sumM || total2 != sumM){
    flag = 1;
    return flag;
  }

  return flag; // flag == 0, is magic
}

int main(int argc, char** argv){
  FILE* fp;
  fp=fopen(argv[1], "r");
  if(fp == NULL){
    printf("not-magic");
    return 0;
  }
  //int row = 0;
  //int col = 0;
  int size = 0;
  int fileNum;
  
  fscanf(fp, "%d\n", &size);
  if(checkOdd(size) != 0){
    printf("not-magic");
    return 0;
  }
    
  int** mat = malloc(size * sizeof(int*));
  for(int i = 0; i < size; i++){
    mat[i] = malloc(size * sizeof(int));
    for(int j = 0; j < size; j++){
      fscanf(fp, "%d\t", &fileNum);
      mat[i][j] = fileNum;
    }
  }
  //printMat( mat, size);
  //printf("\n");

  int flag = checkSum(mat, size);
  printResult(flag);
  return 0;
}

