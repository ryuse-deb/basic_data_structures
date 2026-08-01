#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "ds_status.h"

//STRUCTS AND DATATYPES
typedef struct _doubly_node Node;

typedef struct _doubled_linked_list List;

//FUNCTIONS SIGNATURES
List* List_create(void);
Node* ListNode_create(int);
void List_destroy(List**);
ds_status List_add_head(List *, int);
ds_status List_add_last(List*, int);
ds_status List_remove_head(List*);
ds_status List_remove_tail(List*);
ds_status List_remove_first_found(List*, int);
ds_status List_remove_all_found(List*, int);
ds_status List_print(List *);

#endif
