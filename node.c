#include "node.h"
#include "handle.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct Node* create_node(unsigned int key, char *info) {
  struct Node *node = calloc(1,sizeof(struct Node));
  node->key  = key;
  node->info = str_dup(info);
	return node;
}
void delete_node(struct Node *node) {
  if (node) {
    free(node->info);
    free(node);
  }
}
void display_node(struct Node* node)
{
	printf("%u,%s\n",node->key,node->info);
}
