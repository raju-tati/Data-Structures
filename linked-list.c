#include<stdio.h>
#include<stdlib.h>

struct node {
		int value;
		struct node* next;
};

struct node* head;

void init() {
		head = NULL;
}

void insertFirst(int element) {
		struct node* newNode = malloc(sizeof(struct node));
		newNode->value = element;
		newNode->next = head;
		head = newNode;
}

void deleteFirst() {
		struct node* current = malloc(sizeof(struct node));
		current = head;
		head = head->next;
		free(current);
}

void deleteLast() {
		struct node* current = malloc(sizeof(struct node));
		struct node* previous = malloc(sizeof(struct node));

		current = head;
		while(current->next != NULL) {
				previous = current;
				current = current->next;
		}

		if(previous->next != NULL) {
				previous->next = NULL;
		}

		free(current);
}

void insertLast(int element) {
		struct node* newNode = malloc(sizeof(struct node));
		struct node* temp = malloc(sizeof(struct node));

		newNode->value = element;
		newNode->next = NULL;

		temp = head;
		while(temp->next != NULL) {
				temp = temp->next;
		}

		temp->next = newNode;
}

void print() {
		if(head == NULL) {
				printf("list is empty\n");
				return;
		}

		struct node *current = head;
		int count = 0;
		while(current != NULL) {
				printf("%d->\n", current->value);
				count++;
				current = current->next;
		}
		printf("number of nodes %d", count);
}

int main() {
		init();

		int value = 1;
		insertFirst(value);

		int value2 = 2;
		insertFirst(value2);

		int value3 = 3;
		insertLast(value3);

		deleteFirst();
		deleteLast();

		print();
}
