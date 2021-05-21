#include<stdio.h>
#include<stdlib.h>

int checkMat(int col1, int row2);
void printMat(int** mat, int row, int col);


void printMat(int** mat, int row, int col){
  for(int i = 0; i< row; i++){
    for(int j = 0; j < col; j++){
      printf("%d\t", mat[i][j]);
    }
    printf("\n");
  }
}

int checkMat(int col1, int row2){
  int flag = 0; // 0 is continue, 1 is stop
  if(col1 != row2){
    flag = 1;
     //bad matrices
  }
  return flag;
}

int main(int argc, char** argv){
  FILE* fp;
  fp=fopen(argv[1], "r");
  if(fp == NULL){
    printf("bad-matrices");
    return 0;
  }

  int row1;
  int col1;
  int row2;
  int col2;
  int fileNum;

  fscanf(fp, "%d\t%d", &row1, &col1);

  int** mat1 = malloc(row1 * sizeof(int*));
  for(int i = 0; i < row1; i++){
    mat1[i] = malloc(col1 * sizeof(int));
    for(int j = 0; j < col1; j++){
      fscanf(fp, "%d ", &fileNum);
      mat1[i][j] = fileNum;
      //printf("%d\n", fileNum);
    }
  }
  //printMat(mat1, row1, col1);
  //printf("\n");

  fscanf(fp, "%d %d", &row2, &col2);
  int** mat2 = malloc(row2 * sizeof(int*));
  for(int i = 0; i < row2; i++){
    mat2[i] = malloc(col1 * sizeof(int));
    for(int j = 0; j < col2; j++){
      fscanf(fp, "%d ", &fileNum);
      mat2[i][j] = fileNum;
      //printf("%d\n", fileNum);
    }
  }
  //printMat(mat2, row2, col2);
  //printf("\n");

  if( checkMat( col1, row2) == 1){
    printf("bad-matrices");
    return 0;
  }
  //int inputI = 0;
  int** newMat = malloc(row1* sizeof(int*));
  for(int i = 0; i < row1; i++){
    newMat[i] = malloc( col2* sizeof(int));
    for(int j = 0; j < col2; j++){
      for(int input = 0; input < row2; input++){
	//if( inputI < row2){
	newMat[i][j] += mat1[i][input]* mat2[input][j]; // row2 == col1
	  //inputI++;
	  //}
      }
    }
  }
  printMat(newMat, row1, col2);
  
  fclose(fp);
  return 0;
}
