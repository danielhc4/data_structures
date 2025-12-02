#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node * next;
} node_t;

void insert_node(node_t * c_node, int value) {
    node_t * head = c_node;
    node_t * current = head;
    while(current->next != head) {
        current = current->next;
    }
    node_t * next_node = malloc(sizeof(node_t));
    next_node->value = value;
    next_node->next = c_node;
    current->next = next_node;
}

void remove_node(node_t ** c_node, int pos) {
    if (*c_node == NULL) return;
    node_t * current = * c_node;
    node_t * prev = NULL;
    if (current->next == *c_node) {
        free(current);
        *c_node = NULL;
        return;
    }
    int count = 0;
    node_t * prev_current = *c_node;
    while(count < pos - 1) {
        prev_current = prev_current->next;
        count = count + 1;
    }
    node_t * tmp = prev_current->next;
    prev_current->next = prev_current->next->next;
    free(tmp);
}

void print_list(node_t * head) {
    if(head == NULL) return;
    node_t * current = head;
    int i = 0;
    printf("--Beginning of list--\n");
    do {
        printf("Position: %d Value: %d\n", i, current->value);
        i++;
        current = current->next;
    }
    while(current != head);
    printf("-----End of list-----\n");
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

    printf("Circular Linked List\n");

    printf("Declare pointer c_node of type node_t\n\n");
    node_t * c_node = malloc(sizeof(node_t));

    printf("Initialize first node c_node with value 1\n\n");
    c_node->value = 1;
    c_node->next = c_node;

    printf("Insert 5 nodes to the list\n\n");
	printf("Insert node with value 2 after the first node\n");
    insert_node(c_node, 2);
    printf("Insert node with value 8 after the last inserted node and the first node\n");
    insert_node(c_node, 8);
    printf("Insert node with value 6 after the last inserted node and the first node\n");
    insert_node(c_node, 6);
    printf("Insert node with value 7 after the last inserted node and the first node\n");
    insert_node(c_node, 7);
    printf("Insert node with value 4 after the last inserted node and the first node\n");
    insert_node(c_node, 4);
    printf("Insert node with value 9 after the last inserted node and the first node\n");
    insert_node(c_node, 9);
    printf("Insert node with value 5 after the last inserted node and the first node\n");
    insert_node(c_node, 5);
    printf("Insert node with value 3 after the last inserted node and the first node\n");
    insert_node(c_node, 3);
    printf("Insert node with value 10 after the last inserted node and the first node\n\n");
    insert_node(c_node, 10);

    printf("Print list\n\n");
	print_list(c_node);
	printf("\n");

    printf("Remove 3 nodes from the list\n\n");
	printf("Remove node at position 2 from the list\n");
    remove_node(&c_node, 2);
    printf("Remove node at position 4 from the list\n");
    remove_node(&c_node, 4);
    printf("Remove node at position 7 from the list\n\n");
    remove_node(&c_node, 7);

    printf("Print list\n\n");
	print_list(c_node);
	printf("\n");

    release_list(c_node);

    return 0;
}
