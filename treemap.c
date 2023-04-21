#include "treemap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode TreeNode;

struct TreeNode {
  Pair *pair;
  TreeNode *left;
  TreeNode *right;
  TreeNode *parent;
};

struct TreeMap {
  TreeNode *root;
  TreeNode *current;
  int (*lower_than)(void *key1, void *key2);
};

int is_equal(TreeMap *tree, void *key1, void *key2) {
  if (tree->lower_than(key1, key2) == 0 && tree->lower_than(key2, key1) == 0)
    return 1;
  else
    return 0;
}

TreeNode *createTreeNode(void *key, void *value) {
  TreeNode *new = (TreeNode *)malloc(sizeof(TreeNode));
  if (new == NULL)
    return NULL;
  new->pair = (Pair *)malloc(sizeof(Pair));
  new->pair->key = key;
  new->pair->value = value;
  new->parent = new->left = new->right = NULL;
  return new;
}

TreeMap *createTreeMap(int (*lower_than)(void *key1, void *key2)) {
  TreeMap *temp = (TreeMap *)malloc(sizeof(TreeMap));
  temp->root = NULL;
  temp->current = temp->root;
  temp->lower_than = lower_than;
  return temp;
}

void insertTreeMap(TreeMap *tree, void *key, void *value) {
  if(tree->root==NULL){
    tree->root->pair->key=key;
    tree->root->pair->value=value;
    return;
  }
  if(searchTreeMap(tree, key)==NULL){
    TreeNode* temp = createTreeNode(key, value);
    temp->parent=tree->current;
    if(tree->lower_than(key, tree->current->pair->key)){
      tree->current->left=temp;
    }
    else{
      tree->current->right=temp;
    }
      
    
  }
}

TreeNode *minimum(TreeNode *x) { return NULL; }

void removeNode(TreeMap *tree, TreeNode *node) {}

void eraseTreeMap(TreeMap *tree, void *key) {
  if (tree == NULL || tree->root == NULL)
    return;

  if (searchTreeMap(tree, key) == NULL)
    return;
  TreeNode *node = tree->current;
  removeNode(tree, node);
}

Pair *searchTreeMap(TreeMap *tree, void *key) {
  tree->current=tree->root;
  TreeNode *aux = tree->current;
  int resultado; 
  while (aux != NULL) {
    if(is_equal(tree, key, aux->pair->key)==1){
      tree->current=aux;
      return aux->pair;
    }  
    
    resultado = tree->lower_than(key,aux->pair->key);
    if(resultado==1){
      aux=aux->left;
    }
    else{
      aux=aux->right;
    }
    
    
  }
  tree->current=aux;
  return NULL;
}

Pair *upperBound(TreeMap *tree, void *key) { return NULL; }

Pair *firstTreeMap(TreeMap *tree) {
  if(!tree) return NULL;
  tree->current = tree->root;
  return tree->current->pair;
}

Pair *nextTreeMap(TreeMap *tree) {
  
  return NULL; 
}
