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
int delete(int filNum);//0=fail,1=success


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

int delete(int fileNum){
  struct treenode* ptr = root;
  struct treenode* preptr = root;

  int flag = 0;//0=fail, 1=success;

  if(root == NULL){
    return flag;
  }

  if(root->nodeNum == fileNum && root->left==NULL && root->right==NULL){
    root = ptr->right;
    //root = ptr;
    flag = 1;
    return flag;
  }

  while(ptr != NULL){
    if(ptr->nodeNum < fileNum){
      preptr = ptr;
      ptr = ptr->left;
    }
    else if(ptr->nodeNum > fileNum){
      preptr = ptr;
      ptr = ptr->right;
    }
    else if(ptr->nodeNum == fileNum){
      //condition 1
      if(ptr->right==NULL && ptr->left==NULL){
	if(preptr->left == ptr){
	  preptr->left = NULL;
	  flag = 1;
	}
	else if(preptr->right == ptr){
	  preptr->right = NULL;
	  flag = 1;
	}
	break;
      }
      //condition 2.1 *************PROBLEM
      if(ptr->left!=NULL && ptr->right==NULL){
	struct treenode* temp = ptr->left;
	if(ptr == root){
	  root = temp;
	  //ptr = NULL;
	  //ptr = preptr;
	  flag = 1;
	}
	if(preptr->left == ptr){
	  preptr->left = temp;
	  //ptr = preptr->left;
	  flag = 1;
	}
	else if(preptr->right == ptr){
	  preptr->right = temp;
	  //ptr = preptr->right;
	  flag = 1;
	}
	break;
      }
      //condition 2.2 ***************PROBLEM
      if(ptr->left==NULL && ptr->right!=NULL){
	struct treenode* temp = ptr->right;
	if(ptr == root){
	  root = temp;
	  //ptr = NULL;
	  //ptr = preptr;
	  flag = 1;
	}
	if(preptr->left == ptr){
	  preptr->left = temp;
	  //ptr = preptr->left;
	  flag = 1;
	}
	else if(preptr->right == ptr){
	  preptr->right = temp;
	  //ptr = preptr->right;
	  flag = 1;
	}
	break;
      }
      //condition 3
      if(ptr->left!=NULL && ptr->right!=NULL){
	struct treenode* temp  = ptr->left;
	struct treenode* pretemp = temp;
	while(temp->right != NULL){
	  pretemp = temp;
	  temp = temp->right;
	}
	ptr->nodeNum = temp->nodeNum;
	temp = temp->left;
	pretemp->right = temp;
	temp = NULL;
	flag = 1;
	
	break;
      }
    }
  }
  return flag;//0=fail,1=success
}


  

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
    else if(action=='d'){
      result = delete(fileNum);
      if(result == 1){
	printf("success\n");
      }
      else{
	printf("fail\n");
      }
    }
  }
  //printTree(root);
  fclose(fp);
  return 0;
}
