#include "tree.h"

struct Tree* create_tree()
{
	struct Tree* tree=calloc(1,sizeof(struct Tree));
	return tree;
}

int add_tree(struct Tree *tree, unsigned int key, char* info)
{
	struct Node* node=create_node(key,info);
	if (!tree->head) 
	{
		tree->head=node;
		return OK;
	}
	else
	{
		struct Node* curr=tree->head;
		while (1)
		{
			if (node->key<curr->key)
			{ 
				if (curr->left) curr=curr->left;
				else 
				{
					curr->left=node;
					return OK;
				}
			}
			if (node->key>curr->key)
			{
				if (curr->right) curr=curr->right;
                                else    
                                {       
                                        curr->right=node;
                                        return OK;
                                }
			}
			if (node->key==curr->key)
			{
				while (curr->right && curr->right->key==key) curr=curr->right;
				if (!curr->right) curr->right=node;
				else
				{
					node->right=curr->right;
					curr->right=node;
				}
				return OK;
			}
		}
	}
}
void display_r(struct Node *node,int chert)
{
	if (node->right) display_r(node->right,chert+1);
	for (int i=0;i<chert;++i) printf("-");
	display_node(node);
	if (node->left) display_r(node->left,chert+1);
}
int display_tree(struct Tree* tree)
{
	if (!tree->head) return NOTHING_TREE;
	printf("\n");
	display_r(tree->head,0);
	printf("\n");
	return OK;
}
void delete_r(struct Node *node)
{
  if (node->right) delete_r(node->right);
  if (node->left) delete_r(node->left);
  delete_node(node);

}
struct Node* search_par_tree (struct Tree *tree,unsigned int key)
{
	if (!tree->head) return NULL;
	struct Node* curr=tree->head;
        while (1)
        {
        	if (key<curr->key)
                { 
                	if (curr->left)
			{
				if (curr->left->key==key) return curr;
				curr=curr->left;
			}
                        else return NULL;
                }
                if (key>curr->key)
                {
                        if (curr->right)
			{
				if (curr->right->key==key) return curr;
				curr=curr->right;
			}
                        else return NULL;
                }
		if (key==curr->key)
		{
			return NULL;
		}
		
        }
}
struct Node* search_tree (struct Tree *tree,struct Node *par, unsigned key)
{
	if (!tree->head) return NULL;
	struct Node *res=NULL;
	if (tree->head->key==key) return tree->head;
	if (!par) return NULL;
	if (key<par->key) res=par->left;
	else res=par->right;
	return res;
}
int delete_tree(struct Tree* tree)
{
	if (tree->head) delete_r(tree->head);
	free(tree);
	return OK;
}
void vivod_vector (struct Node ***vector,struct Node *node,int *size)
{
  if (*size!=0||*vector!=NULL) return;
  int len=10;
  if (!node) return;
  *vector=malloc(sizeof(struct Node*)*10);
  while (node)
  {
    (*vector)[*size]=node;
    *size+=1;
    if (*size==len)
    {
      len+=10;
      *vector=realloc(*vector,sizeof(struct Node)*len);
    }
    if (node->right && node->key==node->right->key) node=node->right;
    else break;
  }
  *vector=realloc(*vector,sizeof(struct Node*)*(*size));
}


void get_max_tree(struct Tree *tree,struct Node ***vector,int *size)
{
    if (!tree->head) return;
    struct Node *curr=tree->head;
    struct Node *max=tree->head;
    while (curr->right)
    {
        curr=curr->right;
        if (curr->key>max->key) max=curr;
    }
     vivod_vector(vector,max,size);
}

void search_key_tree(struct Tree *tree,struct Node ***vector, int *size, unsigned key)
{
  if (!tree->head) return;
  struct Node *res=search_par_tree(tree,key);
  res=search_tree(tree,res,key);
  vivod_vector(vector,res,size);
}

int del_key_tree (struct Tree *tree,unsigned int key)
{
	if (!tree->head) return NOTHING_TREE;
	struct Node *par_trash=search_par_tree(tree,key);
	struct Node *trash=search_tree(tree,par_trash,key);
	if (trash==NULL) return INCORRECT_KEY;
	if (trash->right&&!trash->left)
	{
		if (trash==tree->head)	tree->head=trash->right;
		else 
		{
			if (key>=par_trash->key) par_trash->right=trash->right;
			else par_trash->left=trash->right;
		}
		delete_node(trash);
		return OK;
	
	}
	if (trash->left&&!trash->right)
	{
    if (trash==tree->head)  tree->head=trash->left;
		else
		{
			if (key>=par_trash->key) par_trash->right=trash->left;
			else par_trash->left=trash->left;
		}
		delete_node(trash);
		return OK;
	                  
        }
	if (!trash->right && !trash->left)
	{
		if (trash!=tree->head)
		{
			if (key<par_trash->key) par_trash->left=NULL;
			else par_trash->right=NULL;
		}
		else tree->head=NULL;
		delete_node(trash);
		return OK;
	}
	struct Node *lox_right=trash->right;
	struct Node *lox_left=trash->left;
	struct Node *par_lox_right=trash;
	struct Node *par_lox_left=trash;
	while (lox_right->left)
	{
		par_lox_right=lox_right;
		lox_right=lox_right->left;
	}
	while (lox_left->right)
	{
		par_lox_left=lox_left;
		lox_left=lox_left->right;
	}
	unsigned key_swap;
	char *info_swap=NULL;
	if (trash->key-lox_left->key>lox_right->key-trash->key) 
	{
		key_swap=trash->key;
		trash->key=lox_right->key;
		lox_right->key=key_swap;
		info_swap=trash->info;
		trash->info=lox_right->info;
		lox_right->info=info_swap;

		if (par_lox_right==trash) trash->right=lox_right->right;
		else par_lox_right->left=lox_right->right;
		delete_node(lox_right);
	}
	else
	{
		key_swap=trash->key;
		trash->key=lox_left->key;
		lox_left->key=key_swap;
		info_swap=trash->info;
		trash->info=lox_left->info;
		lox_left->info=info_swap;

		if (par_lox_left==trash) trash->left=lox_left->left;
		else par_lox_left->right=lox_left->left;
		delete_node(lox_left);

	}
	return OK;
}

void post_order(struct Node *node, unsigned min, unsigned max)
{
    if (!node) return;
    if (node->key<min) post_order(node->right,min,max);
    else if (node->key>max) post_order(node->left,min,max);
    else
    {
        post_order(node->right,min,max);
        post_order(node->left,min,max);
        display_node(node);
    }
}

int search_diapozon (unsigned min,unsigned max,struct Tree* tree)
{
    if (!tree->head) return NOTHING_TREE;
    struct Node *curr=tree->head;
    while (curr->key<min || curr->key>max)
    {
        if (curr->key<min) curr=curr->right;
        else curr=curr->left;
        if (curr==NULL) return INCORRECT_KEY;
    }
    post_order(curr, min,max);
    return OK;
}









