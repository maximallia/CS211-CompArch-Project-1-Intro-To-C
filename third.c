#include<stdio.h>
#include<stdlib.h>

struct node{
  int nodeNum;
  struct node* next;
};

struct node* ht[1000];

int hashSlot(int fileNum, int size); 
//char* insert(int fileNum, int size);
//char* search(int targetNum, int size);
void free_list(int arr[]);

int hashSlot(int fileNum, int size){
  int key = fileNum % size;
  return key;
}


int insert(int fileNum, int size){
  struct node* temp = malloc(sizeof(struct node));

  int key = hashSlot(fileNum, size);
  key = abs(key);
  int flag = 0;//flag = 1 return inserted, 2 return duplicate

  struct node* ptr = NULL;
  struct node* preptr = NULL;

  temp->nodeNum = fileNum;

  if(ht[key] == NULL){
    //printf("Outside\t");
    ht[key] = temp;
    ht[key]->next = NULL;
    flag = 1;
    return flag;
    //return "inserted";
  }

  ptr = ht[key];
  preptr = ptr;

  while(ptr != NULL){
    //printf("loop\t");
    if( ptr->nodeNum == fileNum){
      //printf("firstIf\t");
      flag = 2;
      return flag; //duplicate
      //return "duplicate";
    }
    preptr = ptr;
    ptr = ptr->next;

    /*if(ptr == NULL){
      printf("secondIf\t");
      preptr->next = temp;
      //&flag = 1;
      //return &flag; //inserted
      return "inserted";
    } can't use READ memory access
  */
    //printf("End\t");
  }
  preptr-> next = temp;
  temp->next = NULL;
  flag = 1;
  return flag;
  //return "inserted";
}

int search(int targetNum, int size){
  int key = hashSlot(targetNum, size);
  key = abs(key);
  int flag = 0; //flag = 3 absent, flag = 4 present

  if(ht[key] == NULL){
    flag = 3 ;
    return flag;
    //return "absent"; //absent
  }

  struct node* ptr = ht[key];

  while( ptr != NULL){
    if( ptr->nodeNum == targetNum){
      flag = 4;
      return flag; //present
      //return "present";
    }
    ptr = ptr->next;
  }

  flag = 3; // not in while, absent
  return flag;
  //return "absent";
}
  

char* result(int flag){
  if( flag == 1){
    return "inserted";
  }
  else if( flag == 2 ){
    return "duplicate";
  }
  else if( flag == 4){
    return "present";
  }
  else if( flag == 3){
    return "absent";
  }
  return "error";
}


int main(int argc, char** argv){
  
  FILE* fp;
  fp=fopen(argv[1], "r");
  if(fp == NULL){
    printf("error\n");
    return 0;
  }

  int size = 1000;
  int flag = 0;
  char action;
  int fileNum;
  //int i = 1;
  while(fscanf(fp, "%c\t%d\n", &action, &fileNum) != EOF){
    //printf("%d\t", i);
    if( action == 'i'){
      flag = insert(fileNum, size);
      //printf("%s\n", insert(fileNum, size));
      printf("%s\n", result(flag));
    }
    else if( action == 's'){
      flag = search(fileNum, size);
      printf("%s\n", result(flag));
      //printf("%s\n", search(fileNum, size));
    }
    //i++;
  }

  return 0;
}
