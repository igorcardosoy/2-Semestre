#include "lse.h"

int main(int argc, char const* argv[])
{
  List my_data;

  list_init(&my_data);
  // my_data = list_init2(); 

  // list_insert_end(my_data, 10);
  // list_insert_end(my_data, 20);
  // list_insert_end(my_data, 30);

  // list_insert_begin(my_data, 40);

  // int index = 0;
  // while (!list_is_empty(my_data))
  // {
  //   printf("Info[%d]: %d\n", index, list_delete_begin(my_data));
  //   index++;
  // }

  list_insert_ascendent(my_data, 10);
  list_insert_ascendent(my_data, 5);
  list_insert_ascendent(my_data, 15);
  list_insert_ascendent(my_data, 1);
  list_insert_ascendent(my_data, 20);
  
  while (!list_is_empty(my_data))
  {
    printf("Info: %d\n", list_delete_begin(my_data));
  }

  return 0;
}
