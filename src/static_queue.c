#include <stdio.h>
#include <stdlib.h>
#include "static_queue.h"

// DATA AND STRUCT DEFINITION===========================================

typedef struct _static_queue {
	int *data;
	long capacity;
	long size;
	long begin;
	long end;	
} StaticQueue;

// FUNCTIONS============================================================

// CONSTRUCTORS AND DESTRUCTORS-----------------------------------------
StaticQueue* StaticQueue_create(long capacity) {
	StaticQueue* SQ = calloc(1, sizeof(StaticQueue));
	SQ->data = calloc(capacity, sizeof(int));
	SQ->capacity = capacity;
	SQ->size = 0;
	SQ->begin = 0;
	SQ->end = 0;
	
	return SQ;
	}

void StaticQueue_destroy(StaticQueue** SQ_ref) {
	StaticQueue* SQ = *SQ_ref;
	
	free(SQ->data);
	free(SQ);
	*SQ_ref = NULL;	
	}

// MANIPULATORS---------------------------------------------------------
ds_status StaticQueue_enqueue(StaticQueue* SQ, int value) {
	if(StaticQueue_IsFull(SQ)) {
		return DS_FULL;
		}
	else {
		SQ->data[SQ->end] = value;
		SQ->end = (SQ->end + 1) % SQ->capacity;
		SQ->size++;
		return DS_OK;
		}
	}
	
ds_status StaticQueue_dequeue(StaticQueue* SQ) {
	if(SQ == NULL) {
		return DS_NULL;
		}
	else {
		if(StaticQueue_IsEmpty(SQ)) {
			return DS_EMPTY;
			}	
		else{
			SQ->data[SQ->begin] = 0;
			SQ->begin = (SQ->begin + 1) % SQ->capacity;
			SQ->size--;
			return DS_OK;
			}
		}
	}


// INFO-----------------------------------------------------------------
ds_status StaticQueue_peek(const StaticQueue* SQ) {
	if(SQ == NULL) {
		return DS_NULL;;
		}
	else {
		if(StaticQueue_IsEmpty(SQ)) {
			return DS_EMPTY;
			}
		else {
			printf("Val: %d", SQ->data[SQ->begin]);
			return DS_OK;
			}
		}
	}
	
ds_status StaticQueue_print(const StaticQueue* SQ) {
	if(SQ == NULL) {
		return DS_NULL;;
		}
	else {
		printf("Begin: %ld | End: %ld\n", SQ->begin, SQ->end);
		for(long s=0 , i=SQ->begin; s < SQ->size; s++, i=(i+1) % SQ->capacity) {
			printf("%d | ", SQ->data[i]);
			}
		return DS_OK;
		}
	}
	
int StaticQueue_IsEmpty(const StaticQueue* SQ) {
	return (SQ->size <= 0);
	}
	
int StaticQueue_IsFull(const StaticQueue* SQ) {
	return (SQ->size >= SQ->capacity);
	}
