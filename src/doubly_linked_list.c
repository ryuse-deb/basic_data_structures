#include <stdio.h>
#include <stdlib.h>

#include "doubly_linked_list.h"
//#include "ds_status.h"

// DATA AND STRUCTS=====================================================

typedef struct _doubly_node {
	int val;
	struct _doubly_node* prev;
	struct _doubly_node* next;
} Node;

typedef struct _doubled_linked_list {
	struct _doubly_node* head;
	struct _doubly_node* tail;
	size_t size;
} List;


// CONSTRUCTORS AND DESTRUCTORS==========================================
List* List_create(void) {
	List* list = calloc(1, sizeof(List));
	
	if(list == NULL) {
		return NULL;
		}
	
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	
	
	return list;
}

Node* ListNode_create(int value) {
	Node* node = calloc(1, sizeof(Node));
	
	if(node == NULL) {
		return NULL;
		}
	
	node->prev = NULL;
	node->next = NULL;
	node->val = value;
	
	return node;
}

void List_destroy (List** list_ref) {
	if(list_ref == NULL) {
		return;
		}
	if(*list_ref == NULL) {
		return;
		}
	
	List* list = *list_ref;
	Node* n = list->head;
	Node* aux = NULL;
	
	while(n != NULL) {
		aux = n;
		n = n->next;
		free(aux);		
	}
	free(list);
	*list_ref = NULL;
}

// MANIPULATORS=========================================================
ds_status List_add_head(List * list, int value) {	
	if(list == NULL) {
		return DS_NULL;
		}
	else {
		Node* n = ListNode_create(value);
		
		if(n == NULL) {
			return DS_ALLOC_ERROR;
			}
		
		if(list->head == NULL) {
			list->tail = n;
			}
		//list->head->prev = n;
		else {
			n->next = list->head;
			list->head->prev = n;
			}
		list->head = n;
		list->size++;
		return DS_OK;
	}
}

ds_status List_add_last(List* list, int value) {
	if(list == NULL) {
		return DS_NULL;
		}
	else {
		Node* n = ListNode_create(value);
		
		if(n == NULL) {
			return DS_ALLOC_ERROR;
			}		
		
		if(list->head == NULL) {
			list->head = n;
			list->tail = n;
		}
		else {
			list->tail->next = n;
			n->prev = list->tail;
			list->tail = n;
		}
		list->size++;
		return DS_OK;
	}
}

ds_status List_remove_head(List* list) {
	Node* n = list->head;
	
	if(list == NULL) {
		return DS_NULL;
		}
	
	else {
		if(List_IsEmpty(list)) {
			return DS_EMPTY;
			}
		else{
			if(list->head == list->tail) {
				list->head = NULL;
				list->tail = NULL;
				}
			else {		
				list->head = list->head->next;
				list->head->prev = NULL;
				}
			free(n);
			list->size--;
			return DS_OK;
			}
		}
}

ds_status List_remove_tail(List* list) {
	Node* n = list->tail;
		
	if(list == NULL) {
		return DS_NULL;
		}
		
	else {
		if(List_IsEmpty(list)) {
			return DS_EMPTY;
			}
		else {
			
			if(list->head == list->tail) {
				list->head = NULL;
				list->tail = NULL;
				}
			else {		
				list->tail = list->tail->prev;
				n->prev->next = NULL;
				}
			free(n);
			list->size--;
			return DS_OK;
		}
	}
}

ds_status List_remove_first_found(List* list, int value) {
	Node* n = list->head;
	
	if(list == NULL) {
		return DS_NULL;
		}
	
	else {	
		if(List_IsEmpty(list)) {
			return DS_EMPTY;
			}
		else {
			while(n != NULL && n->val != value) {
				n = n->next;
				}
			
			if(n == NULL) {
				return DS_NOT_FOUND;
				}
			
			else {
				if (n->prev != NULL) { //Se houver alguem antes de n
					n->prev->next = n->next;
					}
				else { //Se não houver
					list->head = n->next;
					if(list->head != NULL) {
						list->head->prev = NULL;
						}
					}
				if (n->next != NULL) { //Se houver alguem depois de n
					n->next->prev = n->prev;
					}
				else { //Se não houver
					list->tail = n->prev;
					}
				free(n);
				list->size--;	
				return DS_OK;		
				}
		}
	}
}

ds_status List_remove_all_found(List* list, int value) {
	Node* n = list->head;
	Node* aux = NULL;
	
	if(list == NULL) {
		return DS_NULL;
		}
	else {
		if(List_IsEmpty(list)) {
			return DS_EMPTY;
			}
		else {
			while(n != NULL) {
				while(n != NULL && n->val != value) {
					n = n->next;
					}
				
				if(n == NULL) {
					continue;
					}
				
				if (n->prev != NULL) { //Se houver alguem antes de n
					n->prev->next = n->next;
					}
				else { //Se não houver
					list->head = n->next;
					if(list->head != NULL) {
						list->head->prev = NULL;
						}
					}
				if (n->next != NULL) { //Se houver alguem depois de n
					n->next->prev = n->prev;
					}
				else { //Se não houver
					list->tail = n->prev;
					}
				aux = n->next;
				free(n);
				n = aux;
				list->size--;
				}
			return DS_OK;
			}
		}
	}

// INFO=================================================================
ds_status List_print(List * list) {
	if(list==NULL) {
		return DS_NULL;;
	}
	
	else {
		if(List_IsEmpty(list)) {
			return DS_EMPTY;
		}
		else {
			Node* n = list->head;
			
			while(n != NULL) {
				printf(" %d |", n->val);
				n = n->next;
				}
			return DS_OK;
			}
		}
	}
	
int List_IsEmpty(List* list) {
	return (list->head == NULL);
	}
