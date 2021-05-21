#include<stdio.h>
#include<stdlib.h>

struct node{
  int nodeNum;
  struct node * next;
};

struct node* head = NULL;

void insertSort(int fileNum);
void delete(int fileNum);
int count();
void free_list();



void insertSort(int fileNum){
  struct node* ptr = head;
  struct node* preptr = head;
  struct node* newnode =(struct node*) malloc(sizeof(struct node));

  newnode->nodeNum = fileNum;

  if(head == NULL){// newnode->nodeNum < head->nodeNum){
    //printf("a\n");
    newnode->next = head;
    newnode->next = NULL;
    head = newnode;
    //return head;
    return;
  }
  else if(newnode->nodeNum < head->nodeNum){
    //printf("a2\n");
    newnode->next = head;
    head = newnode;
    return;
  }
  else{
    while( ptr != NULL){
      //printf("while\t");
      if(newnode->nodeNum < ptr->nodeNum){
	//printf("b\n");
	newnode->next = ptr;
	preptr->next = newnode;
	return;
      }
      else if(newnode->nodeNum == ptr->nodeNum){
	//printf("bb\n");
	return;
      }
      else if(newnode->nodeNum > ptr->nodeNum && ptr->next == NULL){
	//printf("bbb\n");
	newnode->next = ptr->next;
	ptr->next = newnode;
	return;
      }
      //printf("d\n");
      //printf("\n");
      preptr = ptr;
      ptr = ptr->next;
    }
  }
  return;
}
   
void delete(int fileNum){
  struct node* ptr = head;

  if( head == NULL){
    return;
  }
  if( head->nodeNum == fileNum){
    ptr = ptr->next;
    head = ptr;
    return;
  }
  while( ptr->next != NULL){  
    if( ptr->next->nodeNum == fileNum && ptr->next->next == NULL){
      ptr->next = NULL;
      return;
    }

    if( ptr->next->nodeNum == fileNum){
      ptr->next = ptr->next->next;
      return;
    }
    ptr = ptr->next;
  }
  return;
}


void printlist(){
  struct node* temp = head;
  while(temp != NULL){
    printf("%d\t", temp->nodeNum);
    temp = temp->next;
  }
  return;
}


int count(){
  struct node* temp = head;
  int numOfNum = 0;

  while(temp!= NULL){
    numOfNum++;
    temp = temp->next;
  }
  return numOfNum;
}

void free_list(){
  struct node* oldlist = head;
  while(oldlist != NULL){
    struct node* newlist = oldlist;
    oldlist = oldlist->next;
    free(newlist);
  }
}


int main(int argc, char** argv){

  int numOfNum = 0;
  char action;
  int fileNum;

  FILE *fp = fopen(argv[1], "r");

  if(fp == NULL){
    printf("error\n");
    return 0;
  }

  while( fscanf(fp, "%c %d\n", &action, &fileNum) != EOF){
    if(action == 'i'){
      insertSort(fileNum);
    }
    if(action == 'd'){
      delete(fileNum);
    }
  }
  numOfNum = count();
  printf("%d\n", numOfNum);
  printlist();
  free_list();
  fclose(fp);
  return 0;
}

