#include <stdio.h>
#include <stdlib.h>
#include "ds_status.h"

// DATA AND STRUCT DEFINITION===========================================
typedef struct _circ_node {
	int val;
	struct _circ_node* prev;
	struct _circ_node* next;
} CNode;

typedef struct _circ_list {
	struct _circ_node* head;
	struct _circ_node* tail;
	size_t size;
} CircList;


// FUNCTIONS============================================================

// CONSTRUCTORS AND DESTRUCTORS-----------------------------------------
CircList* CircList_create(void) {
	CircList* list = calloc(1, sizeof(CircList));
	list->size = 0;
	
	return list;
	}

CNode* Node_create(int value) {
	CNode* node = calloc(1, sizeof(CNode));
	node->val = value;
	node->next = node;
	node->prev = node;
	
	return node;
	}

void Node_destroy(CNode** node_ref) {
	CNode* node = *node_ref;
	free(node);
	*node_ref = NULL;
	}

void CircList_destroy(CircList** list_ref) {
//Utiliza o size
	CircList* list = *list_ref;
	CNode* cnode = list->head;
	CNode* aux = NULL;
	
	for(int i = 0; i < (int)list->size; ++i) {
		aux = cnode->next;
		free(cnode);
		cnode = aux;
		}
	free(list);
	*list_ref = NULL;
	
	}

// MANIPULATORS---------------------------------------------------------

ds_status CircList_add_head(CircList* list, int value) {
	if(list == NULL) {
		return DS_NULL;
		}
	
	else{
		CNode* node = Node_create(value);
		
		if(list->head == NULL) {
			list->head = node;
			list->tail = node;
			}	
		
		else{
			node->next = list->head;
			list->head->prev = node;
			list->head = node;
			
			//Parte do loop
			list->tail->next = node;
			node->prev = list->tail;
			}
		list->size++;
		return DS_OK;
		}
	}

ds_status CircList_add_tail(CircList* list, int value) {
	if(list == NULL) {
		return DS_NULL;
		}
	else{
		CNode* node = Node_create(value);
	
		if(list->head == NULL) {
			list->head = node;
			list->tail = node;
			}
		
		else {
			list->tail->next = node;
			node->prev = list->tail;
			list->tail = node;
			
			node->next = list->head;
			list->head->prev = node;
			}
		list->size++;
		return DS_OK;
		}
	}

ds_status CircList_remove_head(CircList* list) {
	if(list == NULL) {
		return DS_NULL;
		}
	else{		
		if(list->head == NULL) {
			return DS_EMPTY;
			}
		else{
			CNode* node = list->head;
			
			if(list->head == list->tail) {
				list->head = NULL;
				list->tail = NULL;
				}
			else {
				list->head = node->next;
				list->head->prev = list->tail;
				list->tail->next = node->next;
				}
			free(node);
			list->size--;
			return DS_OK;
			}
		}
	}

ds_status CircList_remove_tail(CircList* list) {
	if(list == NULL) {
		return DS_NULL;
		}
	else{
		if(list->head == NULL) {
			return DS_EMPTY; //Lista vazia
			}
		else{
			CNode* node = list->tail;
			
			if(list->head == list->tail) { //1 nó apenas
				list->head = NULL;
				list->tail = NULL;
				}
			else { //Mais de um nó
				list->tail = list->tail->prev;
				list->tail->next = list->head;
				list->head->prev = list->tail;	
				}
			free(node);
			list->size--;
			return DS_OK;
			}
		}
	}

ds_status CircList_remove_first_found(CircList* list, int value) {
	if(list == NULL) {
		return DS_NULL;
		}
	else{
		if(list->head == NULL) {
			return DS_EMPTY;
			}
		else{
			CNode* node = list->head;
			
			for(int i = 0; i < (int)list->size; ++i) {
				if(node->val != value) {
					node = node->next;
					}
				else {
					/*
					 * Há 4 possibilidades, do nó estar:
					 * • A lista possuir apenas um nó;
					 * • Inicio;
					 * • Meio;
					 * • Final.
					*/
					
					//Se houver apenas um nó:
					if(list->size == 1){
						free(node);
						list->head = NULL;
						list->tail = NULL;
						}
					else { //Se houver mais de um nó
						node->prev->next = node->next;
						node->next->prev = node->prev;
						
						if(node == list->head) { //Se estiver na cabeça
							list->head = node->next;
							}
						if(node == list->tail) { //Se estiver na calda
							list->tail = node->prev;
							}

						free(node);
						}
					list->size--;
					return DS_OK;
					}
				}
			}
		}
	}
	
ds_status CircList_remove_all_found(CircList* list, int value) {
	if(list == NULL) {
		return DS_NULL;
		}
	else{		
		CNode* node = list->head;
		CNode* aux = NULL;
		int size = (int)list->size;	

		for(int i = 0; i < size; ++i) {
			if(node->val != value) {
				node = node->next;
				}
			else {
				/*
				 * Há 4 possibilidades, do nó estar:
				 * • A lista possuir apenas um nó;
				 * • Inicio;
				 * • Meio;
				 * • Final.
				*/
				
				//Se houver apenas um nó:
				if(list->size == 1){
					free(node);
					list->head = NULL;
					list->tail = NULL;
					break;
					}
				else { //Se houver mais de um nó
					node->prev->next = node->next;
					node->next->prev = node->prev;
					
					if(node == list->head) { //Se estiver na cabeça
						list->head = node->next;
						}
					if(node == list->tail) { //Se estiver na calda
						list->tail = node->prev;
						}
					aux = node->next;
					free(node);
					node = aux;
					}
				list->size--;
				}
		
			}
		return DS_OK;		
		}
	}

// PRINTERS-------------------------------------------------------------
ds_status CircList_print(CircList* list) {
	if(list == NULL) {
		return DS_NULL;
		}
	
	else{
		CNode* node = list->head;
		
		if(list->head == NULL) {
			return DS_EMPTY;
			}
		
		else{
			for(int i=0; i < (int)list->size; ++i) {
				printf("%d | ", node->val);
				node = node->next;
				}
			}
			return DS_OK;
		}
	}
	
int CircList_size(CircList* list) {
	if(list == NULL || list->head == NULL) {
		return -1;
		}
	return (int)list->size;	
	}
