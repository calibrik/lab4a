#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "control.h"

int main()
{
	struct Control *control=create_control();

  void (*menu_item[])(struct Control*) = {NULL, add, display, del_key,display_key, obhod, get_max,search_key};
  const char *menu[] = {"0. EXIT", "1. ADD", "2. DISPLAY", "3. DELETE KEY","4. DISPLAY KEY","5. DISPLAY DIAPOZON","6. GET MAX","7. SEARCH KEY"}; 
  int a;
  while (1) {
    for (int i=0;i<8;++i)
    {
      printf("%s\n", menu[i]);
    }
    scanf("%d%*c", &a);
    if (a <= 0 || a > 7)
      break;
    menu_item[a](control);
  } 

  delete_control(control);
  return 0;
}
