#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int value;
	struct Node * next;
	struct Node * prev;
} node_t;

void print_list_forward(node_t * head) {
	node_t * current = head;
	int i = 0;
	printf("--Beginning of list--\n");
	while(current != NULL) {
		printf("Position: %d, Value: %d \n", i, current->value);
		i++;
		current = current->next;
	}
	printf("-----End of list-----\n");

}

void print_list_backward(node_t * tail) {
	node_t * current = tail;
	int i = 0;
	printf("--Beginning of list--\n");
	while(current != NULL) {
		printf("Position: %d, Value: %d \n", i, current->value);
		i++;
		current = current->prev;
	}
	printf("-----End of list-----\n");
}

void push_node(node_t * head, int value) {
	node_t * current = head;
	while(current->next != NULL) {
		current = current->next;
	}
	current->next = malloc(sizeof(node_t));
	current->next->next = NULL;
	current->next->prev = current;
	current->next->value = value;

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
		node_t * prev_current = *head;
		while(count < pos - 1) {
			prev_current = prev_current->next;
			count = count + 1;
		}
		node_t * node = malloc(sizeof(node_t));
		node->value = value;
		node->next = prev_current->next;
		node->prev = prev_current;
		prev_current->next->prev = node;
		prev_current->next = node;
		while(prev_current->prev != NULL) {
			prev_current = prev_current->prev;
		}
		*head = prev_current;
	}
}

void remove_node(node_t ** head, int pos) {
	if (*head == NULL) return;
	node_t * current = * head;
    node_t * prev = NULL;
    if (current->next == *head) {
        free(current);
        *head = NULL;
        return;
    }
	int count = 0;
    node_t * prev_current = *head;
    while(count < pos - 1) {
        prev_current = prev_current->next;
        count = count + 1;
    }
	node_t * tmp = prev_current->next;
	node_t * next_current = prev_current->next->next;
	prev_current->next = next_current;
	next_current->prev = prev_current;
	free(tmp);
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

node_t * get_tail(node_t * head) {
	node_t * current = head;
	while(current->next != NULL) {
		current = current->next;
	}
	return current;
}

int main() {

	printf("Double Linked List\n");

	printf("Declare pointer c_node of type node_t\n\n");
	node_t * c_node = malloc(sizeof(node_t));

	printf("Initialize first node c_node with value 1\n\n");
	c_node->value = 5;
	c_node->next = NULL;
	c_node->prev = NULL;

	printf("Perform 7 push to the list\n\n");
	printf("Push node with value 2\n");
	push_node(c_node, 2);
	printf("Push node with value 3\n");
	push_node(c_node, 8);
	printf("Push node with value 4\n");
	push_node(c_node, 11);
	printf("Push node with value 5\n");
	push_node(c_node, 4);
	printf("Push node with value 6\n");
	push_node(c_node, 9);
	printf("Push node with value 7\n");
	push_node(c_node, 7);
	printf("Push node with value 8\n\n");
	push_node(c_node, 3);

	printf("Print list\n\n");
	print_list_forward(c_node);
	printf("\n");

	printf("Insert 6 nodes to the list\n\n");
	printf("Insert node with value 8 at position 5\n");
	insert_node(&c_node, 8, 5);
	printf("Insert node with value 7 at position 2\n");
	insert_node(&c_node, 7, 2);
	printf("Insert node with value 14 at position 5\n");
	insert_node(&c_node, 14, 5);
	printf("Insert node with value 3 at position 7\n");
	insert_node(&c_node, 3, 7);
	printf("Insert node with value 9 at position 3\n");
	insert_node(&c_node, 9, 3);
	printf("Insert node with value 10 at position 4\n\n");
	insert_node(&c_node, 10, 4);

	printf("Print list\n\n");
	print_list_forward(c_node);
	printf("\n");

	printf("Remove 3 nodes from the list\n\n");
	printf("Remove node at position 6 from the list\n");
	remove_node(&c_node, 6);
	printf("Remove node at position 8 from the list\n");
	remove_node(&c_node, 8);
	printf("Remove node at position 9 from the list\n");
	remove_node(&c_node, 9);

	printf("Print list\n\n");
	print_list_forward(c_node);
	printf("\n");

	printf("Pop 5 nodes from the list\n\n");
	pop_node(c_node);
	pop_node(c_node);
	pop_node(c_node);
	pop_node(c_node);
	pop_node(c_node);

	printf("Print list\n\n");
	print_list_forward(c_node);
	printf("\n");

	node_t * c_tail = get_tail(c_node);

	printf("Print list backward\n\n");
	print_list_backward(c_tail);
	printf("\n");

	release_list(c_node);

	return 0;
}
