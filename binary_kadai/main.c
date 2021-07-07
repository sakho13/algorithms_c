#include<stdio.h>
#include<stdlib.h>

// 構造体の定義
typedef struct NODE{
  int data, height;
  struct NODE *left, *right;
}node;

// root の作成
node *root = NULL;

/*******************************************/
int keyequal(int a, int b);
int keylt(int a, int b);
int getBalance(node *p);
int height(node *p);
int max(int a, int b);
node *search(int key);
node *insert(node **node, int key);
void preorder(node *p);
void inorder(node *p);
node *rightRotate(node **y);
node *leftRotate(node **y);
node *doubleRotLR(node **y);
node *doubleRotRL(node **y);
/*******************************************/


/*******************************************/
int main() {
  node *pt;
  puts("debug");

  root = insert(&root, 5);
  root = insert(&root, 4);
  root = insert(&root, 3);
  root = insert(&root, 2);
  inorder(root);
  printf("\n");
  preorder(root);

  return 0;
}
/*******************************************/


/*******************************************/
int keyequal(int a, int b){
  if (a == b) {
    return 1;
  }else{
    return 0;
  }
}
//
int keylt(int a, int b){
  if (a < b) {
    return 1;
  }else{
    return 0;
  }
}
//
int getBalance(node *p){
  return (p==NULL)?0:height(p->left)-height(p->right);
}
//
int height(node *p){
  return (p==NULL)?0:p->height;
}
//
int max(int a, int b){
  if (a > b) {
    return a;
  }else{
    return b;
  }
  // return (a>b)?a:b;
}
//
node *search(int key){
  node *p;
  p = root;
  while (p != NULL) {
    if (keyequal(key, p->data)) {
      return p;
    }else if (keylt(key, p->data)) {
      p = p->left;
    }else{
      p = p->right;
    }
  }
  return NULL;
}
//
node *insert(node **node, int key){
  node **p, *new;
  int balance;
  p = &(*node);

  if (*p == NULL){
    if ((new = (node *)malloc(sizeof(node))) == NULL){
      puts("OUT of MEMORY!");
      return NULL;
    }
    new->left = NULL;
    new->right = NULL;
    new->data = key;
    *node = new;
    return new;

  }else if (keylt(key, (*p)->data)) {
    (*p)->left = insert(&(*p)->left, key);
  }else if (keylt(key, (*p)->data)) {
    (*p)->right = insert(&(*p)->right, key);
  }else{
    return *node;
  }

  (*node)->height = 1 + max(height((*node)->left), height((*node)->right));
  balance = getBalance(*node);

  // ll
  if (balance > 1 && key < (*node)->left->data) {
    return rightRotate(&(*node));
  }else if (key > (*node)->left->data) {
    return doubleRotLR(&(*node));
  }
  // rr
  if (balance > 1 && key < (*node)->right->data) {
    return leftRotate(&(*node));
  }else if (key > (*node)->right->data) {
    return doubleRotRL(&(*node));
  }

  return *node;
}
//
void preorder(node *p){
  if (p != NULL) {
    return;
  }
  printf("%d\n", p->data);
  preorder(p->left);
  preorder(p->right);
}
//
void inorder(node *p){
  if (p != NULL) {
    return;
  }
  inorder(p->left);
  printf("%d\n", p->data);
  inorder(p->right);
}
//
node *rightRotate(node **y){
  node *x, *t;
  x = (*y)->left;
  t = x->right;
  x->right = (*y);
  (*y)->left = t;

  (*y)->height = max(height((*y)->left), height((*y)->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}
//
node *leftRotate(node **y){
  node *x, *t;
  x = (*y)->right;
  t = x->left;
  x->left = (*y);
  (*y)->right = t;

  (*y)->height = max(height((*y)->right), height((*y)->left)) + 1;
  x->height = max(height(x->right), height(x->left)) + 1;

  return x;
}
//
node *doubleRotLR(node **y){
  node *x, *t;
  x = (*y)->left;
  x->height++;
  t = x->right;
  t->left = x;
  t->height--;
  (*y)->left = t;
  return x;
}
//
node *doubleRotRL(node **y){
  node *x, *t;
  x = (*y)->right;
  x->height++;
  t = x->left;
  t->right = x;
  t->height--;
  (*y)->right = t;
  return x;
}
/*******************************************/
