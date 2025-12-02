#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int value;
	struct Node * next;
} node_t;

void print_list(node_t * head) {
	node_t * current = head;
	int i = 0;
	printf("--Beginning of list--\n");
	while(current != NULL) {
		printf("Position: %d Value: %d\n", i, current->value);
		i++;
		current = current->next;
	}
	printf("-----End of list-----\n");
}

void push_node(node_t * head, int val) {
	node_t * current = head;
	while(current->next != NULL) {
		current = current->next;
	}
	current->next = malloc(sizeof(node_t));
	current->next->value = val;
	current->next->next = NULL;

}

void pop_node(node_t * head) {
	node_t * current = head;
	while(current->next->next != NULL) {
		current = current->next;
	}
	free(current->next);
	current->next = NULL;
}

void insert_node(node_t ** head, int value, int pos) {
	if(pos == 0) {
		push_node(*head, value);
	}
	else {
		int count = 0;
		node_t * current = (*head);
		while(count < pos - 1) {
			current = current->next;
			count = count + 1;
		}
		node_t * next_node = current->next;
		node_t * new_node = NULL;
		new_node = malloc(sizeof(node_t));
		new_node->value = value;
		new_node->next = next_node;
		current->next = new_node;
	}
}

void remove_node(node_t ** head, int pos) {
	int count = 0;
	if(pos == 0) {
		pop_node(*head);
	}
	else {
		node_t * current = (*head);
		while(count < pos - 1) {
			current = current->next;	
			count = count + 1;
		}
		node_t * d_node = current->next;
		current->next = d_node->next;
		free(d_node);
	}
}

void release_list(node_t * head) {
    if(head == NULL) return;
    node_t * current = head->next;
    node_t * temp = NULL;

    do {
        head->next = current->next;
        * temp = * current;
        current = current->next;
        free(temp);
    } while (current != head);

}

int main() {

	printf("Linked List\n\n");

	printf("Declare pointer c_node of type node_t\n\n");
	node_t * c_node;
	
	printf("Initialize first node c_node with value 3\n\n");
	c_node = malloc(sizeof(node_t));
	c_node->value = 3;
	c_node->next = NULL;

	printf("Perform 10 push to the list\n\n");
	printf("Push node with value 5\n");
	push_node(c_node, 5);
	printf("Push node with value 2\n");
	push_node(c_node, 2);
	printf("Push node with value 7\n");
	push_node(c_node, 7);
	printf("Push node with value 12\n");
	push_node(c_node, 12);
	printf("Push node with value 8\n");
	push_node(c_node, 8);
	printf("Push node with value 15\n");
	push_node(c_node, 15);
	printf("Push node with value 1\n");
	push_node(c_node, 1);
	printf("Push node with value 17\n");
	push_node(c_node, 17);
	printf("Push node with value 9\n");
	push_node(c_node, 9);
	printf("Push node with value 11\n\n");
	push_node(c_node, 11);

	printf("Print list\n\n");
	print_list(c_node);
	printf("\n");

	printf("Pop 3 nodes from the list\n\n");
	pop_node(c_node);
	pop_node(c_node);
	pop_node(c_node);

	printf("Print list\n\n");
	print_list(c_node);
	printf("\n");

	printf("Insert 5 nodes to the list\n\n");

	printf("Insert node with value 23 at position 4\n");
	insert_node(&c_node, 23, 4);
	printf("Insert node with value 11 at position 6\n");
	insert_node(&c_node, 11, 6);
	printf("Insert node with value 14 at position 2\n");
	insert_node(&c_node, 14, 2);
	printf("Insert node with value 9 at position 7\n");
	insert_node(&c_node, 9, 7);
	printf("Insert node with value 3 at position 1\n");
	insert_node(&c_node, 3, 1);

	printf("Print list\n\n");
	print_list(c_node);
	printf("\n");

	printf("Remove 3 nodes from de list\n\n");
	printf("Remove node at position 6 from the list\n");
	remove_node(&c_node, 6);
	printf("Remove node at position 2 from the list\n");
	remove_node(&c_node, 2);
	printf("Remove node at position 9 from the list\n");
	remove_node(&c_node, 9);

	printf("Print list\n\n");
	print_list(c_node);
	printf("\n");

	release_list(c_node);

	return 0;

}
