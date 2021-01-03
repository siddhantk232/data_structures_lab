#include <stdio.h>
#include <stdlib.h>

// compiled using:
// gcc (GCC) 10.2.0
// 3. WAP to insert an element in the beginning of a linear linked-list.
// 4. WAP that removes an element from the beginning of a linear linked-list.
// 5. WAP that removes an element from the end of a linear linked-list.
// 6. WAP to delete an element after the given element in a linear linked-list.

// linked list node 
struct Node { 
    int data; 
    struct Node* next; 
};

void insert_element_at_the_beginning(struct Node** ll, int element);
struct Node* remove_element_from_beginning(struct Node* ll);
struct Node* remove_element_from_end(struct Node* ll);
void remove_element_after_given_value(struct Node** node, int value);


void printList(struct Node* ll) {
  while (ll != NULL) {
    printf("%d ", ll->data);
    ll = ll->next;
  }
  printf("\n");
}

int main() {
  struct Node* head = malloc(sizeof(struct Node));
  head->data = 3;

  // 3 

  insert_element_at_the_beginning(&head, 5);
  insert_element_at_the_beginning(&head, 9);
  insert_element_at_the_beginning(&head, 12);

  // 12 -> 9 -> 5 -> 3
  head = remove_element_from_beginning(head);
  // 9 -> 5 -> 3
  
  head = remove_element_from_end(head);

  // 9 -> 5 
  remove_element_after_given_value(&head, 9);

  // 5 
  printList(head);
}

void insert_element_at_the_beginning(struct Node** ll, int element) {
  // create a new node, with the provided element
  struct Node* head = malloc(sizeof(struct Node));

  head->data = element;
  head->next = *ll;

  // make new head
  *ll = head;
}

struct Node* remove_element_from_beginning(struct Node* ll) {
  struct Node *temp = ll;

  // move head to next
  ll = ll->next;

  free(temp);

  return ll;
}

struct Node* remove_element_from_end(struct Node* ll) {
  // return NULL is ll is empty of length of ll is 1
  if (ll == NULL || ll->next == NULL)
    return NULL;

  struct Node* second_last  = ll;

  while(second_last->next->next != NULL) 
    second_last = second_last->next;
    
  free(second_last->next);
  second_last->next = NULL;

  return ll;
}

void remove_element_after_given_value(struct Node** node, int value) {
  struct Node* temp = *node;

  while(temp != NULL && temp->data != value) {
    temp = temp->next;
  }

  if (temp == NULL) return;

  temp->next = temp->next->next;

  free(temp->next);
}



