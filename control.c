#include "handle.h"
#include "control.h"



void load_tree_file(struct Control *control) {
  char *filename = get_str("filename");
  FILE *file = fopen(filename, "r");
  free(filename);
  if (!file) {
    printf("File not found\n");
  }
  else {
    unsigned key;
    char info[30];
    while (!feof(file)) {
      if (fscanf(file, "%u\n%s\n", &key, info) == 2)
              add_tree(control->tree,key,info);
    }
    fclose(file);
  }
}
struct Control* create_control()
{
        struct Control *control=malloc(sizeof(struct Control));
        control->tree=create_tree();

  char choice;
  printf("Load from file? (y/n): ");
  scanf("%c%*c", &choice);
  if (choice == 'y')
    load_tree_file(control);

        return control;
}
const char* show_status(int index) {
  switch (index) {
    case OK:               return "Ok";
    case NOTHING_TREE:     return "Nothing in tree";
    case INCORRECT_KEY:    return "Incorrect key";
    default:               return "Unknown status";
  }
}

void add (struct Control *control)
{
  printf("Enter key: ");
  unsigned key=get_unsigned();
  while(key==-1) key=get_unsigned(); 
  char* info=get_str("info");
  printf("%s\n",show_status(add_tree(control->tree,key,info)));
  free(info);
}

void display (struct Control *control)
{
  printf("%s\n",show_status(display_tree(control->tree)));
}

void delete_control (struct Control *control)
{
  printf("%s\n",show_status(delete_tree(control->tree)));
  free(control);
}

void del_key (struct Control *control)
{
  printf("Enter key: ");
  unsigned int key=get_unsigned();
  printf("%s\n",show_status(del_key_tree(control->tree,key)));
}
void display_key(struct Control *control)
{
  printf("Enter key: ");
  unsigned int key=get_unsigned();
  while(key==-1) key=get_unsigned(); 
  struct Node* par=search_par_tree(control->tree,key);
  struct Node* res=search_tree(control->tree,par,key);
  if (!control->tree->head) printf("%s\n", show_status(NOTHING_TREE));
  else if (!res) printf("%s\n", show_status(INCORRECT_KEY));
  else if (res)
  {
    display_node(res);
    printf("%s\n", show_status(OK));
  }
}

void get_max (struct Control *control)
{
  if (!control->tree->head)
  {
    printf("Nothing in tree\n");
    return;
  }
  struct Node **vector=NULL;
  int size=0;
  get_max_tree(control->tree,&vector,&size); 
  for (int i=0;i<size;++i) display_node(vector[i]);
  free(vector);
}

void obhod (struct Control *control)
{
  printf("Enter min: ");
  unsigned min=get_unsigned();
  while(min==-1) min=get_unsigned(); 
  printf("Enter max: ");
  unsigned max=get_unsigned();
  while(max==-1) max=get_unsigned(); 
  if (min>max) printf("Incorrect input\n");
  else printf("%s\n",show_status(search_diapozon(min,max,control->tree)));  
}

void search_key (struct Control *control)
{
  if (!control->tree->head)
  {
    printf("Nothing in tree\n");
    return;
  }
  printf("Enter key: ");
  unsigned int key=get_unsigned();
  while(key==-1) key=get_unsigned(); 
  struct Node **vector=NULL;
  int size=0;
  search_key_tree(control->tree,&vector,&size,key);
  if (size==0)
  {
    printf("Incorrect key\n");
    return;
  }
 for (int i=0;i<size;++i) display_node(vector[i]);
 free(vector);
}
