#include <stdio.h>
#include "doubly_linked_list.h"
#include "circular_doubly_linked_list.h"

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
	
	return 0;
}
















