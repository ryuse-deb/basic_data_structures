#ifndef CIRCULAR_DOUBLY_LINKED_LIST_H
#define CIRCULAR_DOUBLY_LINKED_LIST_H

#include "ds_status.h"

//STRUCTS AND DATATYPES
typedef struct _circ_node CNode;

typedef struct _circ_list CircList;

//FUNCTIONS SIGNATURES

CircList* CircList_create(void);
CNode* CircNode_create(int);
void CircNode_destroy(CNode**);
void CircList_destroy(CircList**);

ds_status CircList_add_head(CircList*, int);
ds_status CircList_add_tail(CircList*, int);
ds_status CircList_remove_head(CircList* list);
ds_status CircList_remove_tail(CircList* list);
ds_status CircList_remove_first_found(CircList*, int);
ds_status CircList_remove_all_found(CircList*, int);

ds_status CircList_print(CircList*);
int CircList_size(CircList* list);

#endif
