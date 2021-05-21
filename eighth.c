#include<stdio.h>
#include<stdlib.h>

struct treenode{
  int nodeNum;
  struct treenode* left;
  struct treenode* right;
};

struct treenode* root = NULL;

int insert(int fileNum);//2=inserted,3=duplicate
int search(int fileNum);//0=present, 1=absent



int search(int fileNum){//height0=absent, height=present
  //int flag = 0;//int height = 0;
  struct treenode* ptr = root;
  int height = 0;

  if(ptr == NULL){
    //printf("absent\n");
    return 0;
  }
  
  while( ptr != NULL){
    height++;
    if( ptr->nodeNum > fileNum){
      ptr = ptr->right;
    }
    else if(ptr->nodeNum < fileNum){
      ptr = ptr->left;
    }
    else if( ptr->nodeNum == fileNum){
      return height;
    }
  }
  return 0;
}

int insert(int fileNum){// similar to search for height
  struct treenode* newnode = malloc(sizeof(struct treenode));
  struct treenode* preptr = root;
  struct treenode* ptr = root;

  newnode->nodeNum = fileNum;
  newnode->left = NULL;
  newnode->right = NULL;

  //int flag = 2;

  int height = 0;


  if(root == NULL){
    //printf("a");
    newnode->right = root;
    root = newnode;
    height++;
    return height;
  }


  while(ptr != NULL){
    height++;
    //printf("while");
    if(ptr->nodeNum < newnode->nodeNum){
      //printf("b");
      preptr = ptr;
      ptr = ptr->left;
    }
    else if(ptr->nodeNum > newnode->nodeNum){
      //printf("bb");
      preptr = ptr;
      ptr = ptr->right;
    }
    else if( ptr->nodeNum == fileNum){
      //printf("bbb");
      return 0;//duplicate
    }
    //printf("height:\t%d\n", height);
  }
  if(preptr->nodeNum < newnode->nodeNum){
    //printf("d");
    preptr->left = newnode;
  }
  else if(preptr->nodeNum > newnode->nodeNum){
    //printf("dd");
    preptr->right = newnode;
  }
  height++;
  return height;//inserted
}


/*void result(int flag){
  if(flag == 0){
    printf("present ");
  }
  else if(flag == 1){
    printf("absent ");
  }
  else if(flag == 2){
    printf("inserted ");
  }
  else if(flag == 3){
    printf("duplicate ");
  }
  }*/


/*void printTree(struct treenode* root){
  if(root == NULL) return;
  printf(" value: %d\n", root->nodeNum);
  printTree(root->left);
  printTree(root->right);
}
*/

int main(int argc, char** argv){

  char action;
  int fileNum;

  FILE* fp = fopen(argv[1], "r");

  if(fp==NULL){
    printf("error\n");
    return 0;
  }
  int result = 0;
  while(fscanf(fp, "%c\t%d\n", &action, &fileNum) !=EOF){
    //printf("%c %d\t", action, fileNum);
    if( action=='i'){
      result = insert(fileNum);
      if(result != 0){
	printf("inserted %d\n", result);
      }
      else{
	printf("duplicate\n");
      }
    }
    else if(action=='s'){
      result = search(fileNum);
      if(result != 0){
	printf("present %d\n", result);
      }
      else{
	printf("absent\n");
      }
    }
  }
  //printTree(root);
  fclose(fp);
  return 0;
}
