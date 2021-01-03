#include <stdio.h>
#include <stdlib.h>

// compiled using:
// gcc (GCC) 10.2.0
 
struct Node {
    int data;
    struct Node* next;
};
 
void reverse_linked_list(struct Node** head_ref) {
  struct Node* prev = NULL;
  struct Node* current = *head_ref;
  struct Node* next = NULL;

  while (current != NULL) {
    // Store next
    next = current->next;

    // Reverse current node's pointer
    current->next = prev;

    // Move pointers one position ahead.
    prev = current;
    current = next;
  }

  *head_ref = prev;
}

struct Node* concat_linked_lists(struct Node* a, struct Node* b) {
  struct Node* p = a;

  if (a == NULL || b == NULL) return NULL;

  while(p->next != NULL) {
    p = p->next;
  }

  p->next = b;
  return a;
}


 
void push_value(struct Node** head_ref, int new_data) {
  struct Node* new_node = malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = (*head_ref);
  *head_ref = new_node;
}
 
void printList(struct Node* head) {
  struct Node* temp = head;
  while (temp != NULL) {
    printf("%d  ", temp->data);
    temp = temp->next;
  }
}
 
int main() {
  struct Node* head = NULL;
  struct Node* another_head = NULL;
  push_value(&head, 20);
  push_value(&head, 4);
  push_value(&head, 15);
  push_value(&head, 85);
  push_value(&another_head, 12);
  push_value(&another_head, 1);
  push_value(&another_head, 8);

  printf("linked list\n");
  printList(head);
  reverse_linked_list(&head);
  printf("\n resulting linked list \n");
  printList(head);

  struct Node* concatenated = concat_linked_lists(head, another_head);

  printf("\n concatenated linked list \n");
  printList(concatenated);
  printf("\n");
}
