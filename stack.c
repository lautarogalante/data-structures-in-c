#include "stdbool.h"
#include "stdio.h"
#include <stdlib.h>
#include "limits.h"

struct Stack {
	size_t size;
	int *stack;
	size_t top;
};

struct Stack* new_stack(size_t size) {
	struct Stack* s = malloc(sizeof(struct Stack));
	s->stack = malloc(size * sizeof(int));
	if (s == NULL || s->stack == NULL) {
		perror("Allocation Error.");		
		free(s);
		return NULL;
	}
	s->size = size;
	s->top = 0;
	return s;
}

void push(struct Stack* s, int element) {
	if (s->top < s->size) {
		s->stack[s->top] = element;
		s->top++;
	}else {
		printf("Stack Overflow\n");
	}
}

bool is_empty(struct Stack* s) {
	return s->top == 0;
}

int pop(struct Stack *s) {
	if(is_empty(s)){
		return INT_MIN;
	}
	s->top--;
	return s->stack[s->top];
}


bool is_full(struct Stack* s) {
	return s->top == s->size;
}

void clear(struct Stack* s) {
	s->top = 0;
}

void destroy(struct Stack** s) {
	free((*s)->stack);
	free(*s);
	*s = NULL;
}

int peek(struct Stack *s) {
	if (is_empty(s)) {
		return INT_MIN;
	}
	return s->stack[s->top-1];
}

int size(struct Stack* s){
	return s->top;
}

int main() {
	struct Stack* s = new_stack(10);
	for(int i = 0; i < 10; i++) {
		push(s, i*2);
	}
	push(s, 23);
	printf("Is Full: %d\n", is_full(s));
	printf("Size: %d\n", size(s));
	printf("Last Element: %d\n", peek(s));
	for(int i = 0; i < 10; i++) {
		pop(s);
	}
	if(pop(s) == INT_MIN) {
		printf("The Stack is Empty.\n");
	}
	printf("Is Empty: %d\n", is_empty(s));
	destroy(&s);
	if (s == NULL) {
		printf("The Stack is free\n");
	}
	return 0;
}
