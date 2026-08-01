#include <stdio.h>
#include <stdlib.h>

#include "dinamic_queue.h"

// DATA AND STRUCT DEFINITION===========================================
typedef struct _queue {
	List* data;
} DinamicQueue;

// FUNCTIONS============================================================

// CONSTRUCTORS AND DESTRUCTORS-----------------------------------------
DinamicQueue* DinamicQueue_create(void) {
	DinamicQueue* DQ = calloc(1, sizeof(DinamicQueue));
	DQ->data = List_create();
	
	return DQ;
	}
	

void DinamicQueue_destroy(DinamicQueue** DQ_ref) {
	DinamicQueue* DQ = *DQ_ref;
	
	List_destroy(&DQ->data);
	free(DQ);
	*DQ_ref = NULL;
	
	}	
	
// MANIPULATORS---------------------------------------------------------	
ds_status DinamicQueue_enqueue(DinamicQueue* DQ, int value) {
	if(DQ == NULL) {
		return DS_NULL;
		}
	else {
		List_add_last(DQ->data, value);
		return DS_OK;
		}	
	}
	
ds_status DinamicQueue_dequeue(DinamicQueue* DQ) {
	if(DQ == NULL) {
		return DS_NULL;
		}
	else {
		List_remove_head(DQ->data);
		return DS_OK;
		}
	}
	
// INFO-----------------------------------------------------------------
ds_status DinamicQueue_print(const DinamicQueue* DQ) {
	if(DQ == NULL) {
		return DS_NULL;
		}
	else {	
		List_print(DQ->data);	
		return DS_OK;
		}
	}

int DinamicQueue_peek(const DinamicQueue* DQ) {
	if(DQ == NULL) {
		return -1;
		}
	int val = List_return_head(DQ->data);
	return val;	
	}
