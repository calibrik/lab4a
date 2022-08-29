#ifndef TREE_H
#define TREE_H

#include "node.h"
enum StatusProgram {
  OK,
  NOTHING_TREE,
  INCORRECT_KEY,
};

struct Tree
{
	struct Node *head;
};



struct Tree* create_tree();
int add_tree(struct Tree *tree, unsigned int key, char* info);
void display_r(struct Node *node,int chert);
int display_tree(struct Tree* tree);
void delete_r(struct Node *node);
struct Node* search_par_tree (struct Tree *tree,unsigned int key);
struct Node* search_tree (struct Tree *tree,struct Node *par, unsigned key);
int del_key_tree (struct Tree *tree,unsigned int key);
int search_diapozon (unsigned min,unsigned max,struct Tree* tree);
void post_order(struct Node *node, unsigned min, unsigned max);
int delete_tree(struct Tree* tree);
void vivod_vector (struct Node ***vector,struct Node *node,int *size);
void get_max_tree(struct Tree* tree,struct Node ***vector,int *size);
void search_key_tree(struct Tree *tree,struct Node ***vector, int *size, unsigned key);

#endif
