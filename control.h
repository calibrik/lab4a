#ifndef CONTROL_H
#define CONTROL_H

#include "tree.h"


struct Control
{
	struct Tree* tree;
};

struct Control* create_control();
const char* show_status(int index);
void add (struct Control *control);
void display (struct Control *control);
void delete_control (struct Control *control);
void del_key (struct Control *control);
void obhod (struct Control *control);
void display_key(struct Control *control);
void get_max (struct Control *control);
void search_key (struct Control *control);

#endif
