#include <stdio.h>
#include <stdlib.h> // Include this header for malloc function
#include "Node.h"

void print_list(node* head) {
    node* current = head;

    printf("Linked List: ");
    while (current != NULL) {
        printf("%d %s %d -> ", current->roll, current->name, current->age);
        current = current->next;
    }
    printf("NULL\n");
}

void print_circular_list(node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    node* current = head;
    printf("Circular Linked List: ");
    do {
        printf("%d %s %d -> ", current->roll, current->name, current->age);
        current = current->next;
    } while (current != head);
    printf("... (circular)\n");
}

node* create_none_circular_list()
{
    int n;
    node* head = NULL;

    printf("\n How many elements to enter?");
    scanf_s("%d", &n);
    getchar(); // Consume the newline character left in the input buffer

    char inputLine[256]; // Assuming a maximum line length of 255 characters

    for (int k = 0; k < n; k++)
    {
        printf("Enter roll, name, and age (separated by spaces): ");
        fgets(inputLine, sizeof(inputLine), stdin);

        // Create a new node and initialize its members
        node* newNode = (node*)malloc(sizeof(node));
        if (newNode == NULL) {
            // Handle memory allocation error
            // You might want to add appropriate error handling code here
            break;
        }

        sscanf_s(inputLine, "%d %s %d", &newNode->roll, newNode->name, sizeof(newNode->name), &newNode->age);
        newNode->next = NULL;

        // Insert the new node at the beginning of the list
        if (head == NULL) {
            head = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    return head;
}

node* create_circular_list()
{
    int n;
    node* head = NULL;

    printf("\n How many elements to enter?");
    scanf_s("%d", &n);
    getchar(); // Consume the newline character left in the input buffer

    char inputLine[256]; // Assuming a maximum line length of 255 characters

    for (int k = 0; k < n; k++)
    {
        printf("Enter roll, name, and age (separated by spaces): ");
        fgets(inputLine, sizeof(inputLine), stdin);

        // Create a new node and initialize its members
        node* newNode = (node*)malloc(sizeof(node));
        if (newNode == NULL) {
            // Handle memory allocation error
            // You might want to add appropriate error handling code here
            break;
        }

        sscanf_s(inputLine, "%d %s %d", &newNode->roll, newNode->name, sizeof(newNode->name), &newNode->age);
        newNode->next = NULL;

        // Insert the new node at the beginning of the list
        if (head == NULL) {
            head = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    // Link the last node to the head to create a circular list
    if (head != NULL) {
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = head;
    }

    return head;
}


void free_list(node* head) {
    node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void free_circular_list(node* head) {
    if (head == NULL) return;



    node* current = head;
    node* next;
    do {
        next = current->next;
        free(current);
        current = next;
    } while (current != head);
}
