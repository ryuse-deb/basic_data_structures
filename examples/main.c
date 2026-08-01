#include <stdio.h>

#include "doubly_linked_list.h"
#include "circular_doubly_linked_list.h"
#include "static_stack.h"
#include "dinamic_stack.h"
#include "static_queue.h"
#include "dinamic_queue.h"

int main(void) {

//TESTE DA LISTA DUPLAMENTE ENCADEADA===================================
	/*
	//TESTE DA LISTA DUPLAMENTE ENCADEADA
	List* list1 = List_create();
	
	List_add_head(list1, 5);
	List_add_head(list1, 10);
	List_add_head(list1, 15);
	List_add_head(list1, 20);
	List_add_head(list1, 25);
	List_add_head(list1, 15);
	List_add_head(list1, 20);
	List_add_head(list1, 30);
	List_add_last(list1, 30);
	List_add_last(list1, 20);
	List_add_last(list1, 40);
	List_add_last(list1, 5);
	List_add_last(list1, 50);
	
	List_print(list1);
	
	puts("");
	puts("Remove on head");
	List_remove_head(list1);
	List_print(list1);
	
	puts("");
	puts("Remove on tail");
	List_remove_tail(list1);
	List_print(list1);
	
	puts("");
	puts("Remove first found: 15");
	List_remove_first_found(list1, 15);
	List_print(list1);
	
	puts("");
	puts("Remove all found: 20");
	List_remove_all_found(list1, 20);
	List_print(list1);
	
	puts("");
	puts("List destroy");
	List_destroy(&list1);
	List_print(list1);
	
	*/
	
//TESTE DA LISTA CIRCULAR DUPLAMENTE ENCADEADA==========================
	/*
	CircList* list1 = CircList_create();
	
	CircList_add_head(list1, 10);
	CircList_add_head(list1, 35);
	CircList_add_head(list1, 20);
	CircList_add_head(list1, 45);
	CircList_add_head(list1, 20);
	CircList_add_tail(list1, 30);
	CircList_add_tail(list1, 45);
	CircList_add_tail(list1, 10);
	CircList_add_tail(list1, 10);
	CircList_add_tail(list1, 30);
	CircList_add_head(list1, 10);
	
	int size = CircList_size(list1);
	printf("Size of list: %d\n\n", size);	
	
	CircList_print(list1);
	puts("");
	
	CircList_remove_head(list1);
	CircList_remove_tail(list1);
	CircList_print(list1);
	puts("");
	
	CircList_remove_first_found(list1, 10);
	CircList_print(list1);
	puts("");
	
	CircList_remove_all_found(list1, 10);
	CircList_print(list1);
	puts("");
	
	CircList_destroy(&list1);
	CircList_print(list1);
	puts("");
	*/
	
// TESTE DA PILHA ESTÁTICA==============================================
	/*
	StaticStack* sstack1 = StaticStack_create(5);
	
	StaticStack_push(sstack1, 5);
	StaticStack_push(sstack1, 10);
	StaticStack_push(sstack1, 15);
	StaticStack_push(sstack1, 20);
	StaticStack_push(sstack1, 25);

	StaticStack_print(sstack1);
	puts("");

	int val = StaticStack_peek(sstack1);
	printf("peek: %d\n\n", val);
	
	StaticStack_pop(sstack1);
	StaticStack_pop(sstack1);
	StaticStack_print(sstack1);
	puts("");
	
	StaticStack_destroy(&sstack1);
	StaticStack_print(sstack1);
	*/

// DINAMIC STACK TEST===================================================
	/*
	DinamicStack* dstack1 = DinamicStack_create();
	
	DinamicStack_print(dstack1);
	
	DinamicStack_push(dstack1, 5);
	DinamicStack_push(dstack1, 10);
	DinamicStack_push(dstack1, 15);
	DinamicStack_push(dstack1, 20);
	DinamicStack_push(dstack1, 25);
	DinamicStack_push(dstack1, 30);
	DinamicStack_push(dstack1, 35);
	DinamicStack_push(dstack1, 40);
	DinamicStack_print(dstack1);
	puts("");

	DinamicStack_pop(dstack1);
	DinamicStack_print(dstack1);
	puts("");
	
	int val1 = DinamicStack_peek(dstack1);
	printf("peek: %d\n", val1);
	
	DinamicStack_destroy(&dstack1);
	DinamicStack_print(dstack1);
	puts("");

	*/
	
// STATIC QUEUE TEST====================================================
	/*
	StaticQueue* SQueue1 = StaticQueue_create(5);
	
	StaticQueue_enqueue(SQueue1, 5);
	StaticQueue_enqueue(SQueue1, 10);
	StaticQueue_enqueue(SQueue1, 15);
	StaticQueue_enqueue(SQueue1, 20);
	StaticQueue_enqueue(SQueue1, 25);
	StaticQueue_enqueue(SQueue1, 30);
	StaticQueue_print(SQueue1);
	puts("");
	
	StaticQueue_dequeue(SQueue1);
	StaticQueue_print(SQueue1);
	puts("");
	
	StaticQueue_destroy(&SQueue1);
	StaticQueue_print(SQueue1);
	puts("");
	*/
	
// DINAMIC QUEUE TEST===================================================
	/*
	DinamicQueue* DQueue1 = DinamicQueue_create();
	
	DinamicQueue_enqueue(DQueue1, 5);
	DinamicQueue_enqueue(DQueue1, 10);
	DinamicQueue_enqueue(DQueue1, 15);
	DinamicQueue_enqueue(DQueue1, 20);
	DinamicQueue_enqueue(DQueue1, 25);
	DinamicQueue_enqueue(DQueue1, 30);
	DinamicQueue_print(DQueue1);
	puts("");
	
	int val = DinamicQueue_peek(DQueue1);
	printf("peek: %d\n", val);
	
	DinamicQueue_dequeue(DQueue1);
	DinamicQueue_dequeue(DQueue1);
	DinamicQueue_print(DQueue1);
	puts("");
	
	DinamicQueue_destroy(&DQueue1);
	DinamicQueue_print(DQueue1);
	puts("");
	*/	

	return 0;
}
















