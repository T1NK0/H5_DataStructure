#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

#include "Node.h" // Include the header file where node structure is defined

// Function prototypes
void print_list(node* head);
void print_circular_list(node* head);
node* create_none_circular_list();
node* create_circular_list();
void free_list(node* head);
void free_circular_list(node* head);

#endif // SINGLELINKEDLIST_H
