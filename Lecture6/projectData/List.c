//This is an implementation of the List.h file
#include "List.h"
#include "status.h"
#include <stdlib.h>
#include <stdio.h>


/** Empty List creation by dynamic memory allocation (O(1)).
 * @param comp comparison function between elements (ala strcmp())
 * @param pr display function for list elements
 * @return a new (empty) list if memory allocation OK
 * @return 0 otherwise
 */
List*	newList	(compFun comp,prFun pr) {
  List* l = (List*)malloc(sizeof(List));
  if (!l) return 0;
  l->head = 0;
  l->comp = comp;
  l->pr = pr;
  return l;
}

/** destroy the list by deallocating used memory (O(N)).
 * @param l the list to destroy */
void 	delList	(List* l){
    Node* n = l->head;
    while (n) {
        Node* next = n->next;
        free(n);
        n = next;
    }
    free(l);
}

/** get the Nth element of the list (O(N)).
 * @param l the list
 * @param n the index of the element in list
 * @param res (out) the searched element
 * @return OK if element found
 * @return ERRINDEX if index out of list bounds
 */
status 	nthInList	(List* l, int n, void* res){
    Node* node = l->head;
    while (n > 0 && node) {
        node = node->next;
        n--;
    }
    if (n != 0 || !node) return ERRINDEX;
    *(void**)res = node->val;
    return OK;
}

/** Insert element at a given position in the list (O(N)).
 * @param l the list to store the element in
 * @param n the position of the insertion point
 * @param e the element to insert
 * @return ERRINDEX if position is out of list bounds
 * @return ERRALLOC if memory allocation failed
 * @return OK otherwise
 */

status 	addListAt	(List* l, int n, void* e){
    Node* node = l->head;
    Node* prev = 0;
    while (n > 0 && node) {
        prev = node;
        node = node->next;
        n--;
    }
    if (n != 0) return ERRINDEX;
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return ERRALLOC;
    newNode->val = e;
    newNode->next = node;
    if (prev) {
        prev->next = newNode;
    } else {
        l->head = newNode;
    }
    return OK;
}

/** remove the element located at a given position in list (O(N)).
 * @param l the list to remove the element from
 * @param n the position of the element to remove
 * @param res (out) the removed element
 * @return ERRINDEX if position is out of list bounds
 * @return OK otherwise
 */
status 	remFromListAt	(List* l, int n, void* res){
    Node* node = l->head;
    Node* prev = 0;
    while (n > 0 && node) {
        prev = node;
        node = node->next;
        n--;
    }
    if (n != 0 || !node) return ERRINDEX;
    if (prev) {
        prev->next = node->next;
    } else {
        l->head = node->next;
    }
    *(void**)res = node->val;
    free(node);
    return OK;
}

/** remove given element from given list (O(N)).
 * implies the user has given a comparison function.
 * @param l the list to remove the element from
 * @param e the element to remove
 * @return ERRABSENT if element is not found in list
 * @return ERRUNABLE if no comparison function has been provided
 * @return OK otherwise
 */
status remFromList(List* l, void* e) {
    Node* node = l->head;
    Node* prev = 0;
    while (node) {
        if (l->comp(node->val, e) == 0) {
            if (prev) {
                prev->next = node->next;
            } else {
                l->head = node->next;
            }
            free(node);
            return OK;
        }
        prev = node;
        node = node->next;
    }
    return ERRABSENT;
}

/** display list elements as "[ e1 ... eN ]" (O(N)).
 * The display of the element is delegated to the prFun function
 * @param l the list to display.
 * @return ERRUNABLE if no comparison function has been provided
 */
status displayList(List* l) {
    if (!l->pr) return ERRUNABLE;
    Node* node = l->head;
    printf("[ ");
    while (node) {
        l->pr(node->val);
        printf(" ");
        node = node->next;
    }
    printf("]\n");
    return OK;
}

/** sequencially call given function with each element of given list (O(NxF)).
 * @param l the list
 * @param f the function
 */
void forEach(List* l, void (*f)(void*)) {
    Node* node = l->head;
    while (node) {
        f(node->val);
        node = node->next;
    }
}
/*compute and return the number of 
elements in given list (O(1))
* @param l the list
* @return the number of elements in given list
*/
int lengthList(List* l) {
    Node* node = l->head;
    int length = 0;
    while (node) {
        length++;
        node = node->next;
    }
    return length;
}

/** add given element to given list according to compFun function (O(N)).
 * @param l the list (supposedly sorted according to compFun function)
 * @param e the element to add
 * @return ERRALLOC if memory allocation failed
 * @return ERRUNABLE if no comparison function has been provided
 * @return OK otherwise
 */
status addList(List* l,void* e){
    Node* node = l->head;
    Node* prev = 0;
    while (node) {
        if (l->comp(node->val, e) > 0) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            if (!newNode) return ERRALLOC;
            newNode->val = e;
            newNode->next = node;
            if (prev) {
                prev->next = newNode;
            } else {
                l->head = newNode;
            }
            return OK;
        }
        prev = node;
        node = node->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return ERRALLOC;
    newNode->val = e;
    newNode->next = 0;
    if (prev) {
        prev->next = newNode;
    } else {
        l->head = newNode;
    }
    return OK;
}

/** tests whether the list contains given element (O(N)).
 * @param l the list
 * @param e the searched element
 * @return 0 if element is not found in list
 * @return 1 if element is at the head of the list (no predecessor)
 * @return (a pointer to) the predecessor of the search element otherwise
 */
Node*	isInList	(List* l, void* e){
    Node* node = l->head;
    Node* prev = 0;
    while (node) {
        if (l->comp(node->val, e) == 0) {
            if (prev) {
                return prev;
            } else {
                return (Node*)1;
            }
        }
        prev = node;
        node = node->next;
    }
    return 0;
}

