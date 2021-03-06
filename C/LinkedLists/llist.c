/* llist.c -- Implementation for the doubly-linked list assignment
 *
 * Name: Dave Hubbard
 * Email address: dehubbar@asu.edu
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/* We get the definition of LList and all of the function declarations
   out of the llist.h header file */
#include "llist.h"

/* llist_create takes an integer value and assigns it to a new node.*/
LList_t *llist_create(int val)
{
    LList_t *newNode = (LList_t*)malloc(sizeof(LList_t));
    if (newNode != NULL){
	newNode->value = val;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
    }
    return NULL;
}

/*
 * Free memory allocated for the given node. 
 */
void llist_delete(LList_t *ele)
{
    if(ele != NULL){
	free(ele);
    }
}

/*
 *Checks for and returns the position of the head of the list. If the list is
  empty, NULL is returned. 
 */
LList_t *llist_head(LList_t *ele)
{
   
    if(ele != NULL){
	LList_t *curr = ele;	
	while(curr->prev != NULL){
	    curr = curr->prev;
	}
	return curr;
    }	    
    return NULL;
}

/*                           -llist_tail-
 * Returns the position of the last available element in the list.
 */
LList_t *llist_tail(LList_t *ele)
{
      if(ele != NULL){
	LList_t *curr = ele;	
	while(curr->next != NULL){
	    curr = curr->next;
	}
	return curr;
      }
    return NULL;
}

/*                            -llist_lookup-
 * Returns the position of the element that contains the given value, starting
 from a specified element. If the value is not found, returns NULL.
*/
LList_t *llist_lookup(LList_t *ele, int val)
{
    if(ele != NULL){	
	LList_t *curr = ele;
	while(curr->next != NULL){
	    if(curr->value == val){
		return curr;
	    }
	    curr = curr->next;
	}
	if(curr->value == val){
	    return curr;
	}
    }
    return NULL;
}

/*
 * Enters a node before the current element into the linked list.
 */
LList_t *llist_insert_before(LList_t *ele, int val)
{
    LList_t *newNode = llist_create(val);
    if(newNode != NULL && ele != NULL){

	newNode->next = ele;
        newNode->prev = ele->prev;
	ele->prev = newNode;
	if(newNode->prev != NULL){
	    LList_t *curr = ele;
	    curr = newNode->prev;
	    curr->next = newNode;
	}	
	return newNode;
    }
    
    if(ele == NULL){
	return newNode;
    }
    return NULL;
}

/*
 * Enters a node after the current element.
 */
LList_t *llist_insert_after(LList_t *ele, int val)
{
     LList_t *newNode = llist_create(val);
    if(newNode != NULL && ele != NULL){

	newNode->prev = ele;
        newNode->next = ele->next;
	ele->next = newNode;
	if(newNode->next != NULL){
	    LList_t *curr = ele;
	    curr = newNode->next;
	    curr->prev = newNode;
	}	
	return newNode;
    }
    
    if(ele == NULL){
	return newNode;
    }
    return NULL;
}

/*
 * Removes and deallocates memory for the node with the given value. No
   value found returns the current element.
 */
LList_t *llist_remove(LList_t *list, int val)
{
  if(list != NULL){
    LList_t *toRemove = llist_lookup(list,val);

    if(toRemove != NULL && toRemove->prev == NULL){
	if(toRemove->next == NULL){
	    llist_delete(toRemove);
	    return NULL;
	}else{
	    LList_t *curr = toRemove;
	    curr = curr->next;
	    curr->prev = NULL;
	    llist_delete(toRemove);
	    return curr;
	}
    }

    if(toRemove != NULL && toRemove->prev != NULL){
	if(toRemove->next != NULL){
	    LList_t *temp = toRemove;
	    temp = temp->next;
	    temp->prev = toRemove->prev;
	    temp = toRemove->prev;
	    temp->next = toRemove->next;
	    llist_delete(toRemove);
	    return temp;
	}else{
	     LList_t *temp = toRemove;
	    temp = toRemove->prev;
	    temp->next = NULL;
	    llist_delete(toRemove);
	    return temp;
	}
    }
  
    if(toRemove == NULL){
	return list;
    }
  }
    return NULL;
}

/*
 * Deletes the list from the current element to the end of the list.
 */
void llist_delete_list(LList_t *list)
{
    if(list != NULL){
	LList_t *curr = list;
   
	if(list->prev != NULL){
	    LList_t *newTail = list->prev;
	    while(curr->next != NULL){
		LList_t *temp = curr;
		curr = curr->next;
		llist_delete(temp);
	    }
	    llist_delete(curr);
	    newTail->next = NULL;
	}else{
	     while(curr->next != NULL){
		LList_t *temp = curr;
		curr = curr->next;
		llist_delete(temp);
	    }
	    llist_delete(curr);
	}
    }
}

/*
 * end of llist.c
 */
