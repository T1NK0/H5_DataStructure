#include <stdio.h>
#include "singleLinkedList.h"
#include "Node.h"



int main() {
	// Creates the linked lists.
	node* noneCircularListExample = create_none_circular_list();
	node* circularListExample = create_circular_list();



	// Print the non-circular linked list
	printf("Non-Circular ");
	print_list(noneCircularListExample);



	// Print the circular linked list
	printf("Circular ");
	print_circular_list(circularListExample);  // Brug en speciel funktion for cirkulære lister



	// Free the memory used by the linked lists when done
	free_list(noneCircularListExample);
	free_circular_list(circularListExample);  // Brug en speciel funktion for cirkulære lister



	return 0;
}