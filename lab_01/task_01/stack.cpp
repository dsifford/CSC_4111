#include <iostream>
#include "stack.h"

template<class T>
Stack<T>::Stack() {
	length = 0;
	top = NULL;
}

template<class T>
Stack<T>::~Stack() {
	Node<T> *node = top;
	while (node->next && node->next->next) {
		node = node->next;
	}
	while (node->prev) {
		delete node->next;
		node = node->prev;
	}
	top = NULL;
	delete node;
}

template<class T>
void Stack<T>::push(T value) {
	struct Node<T> *node = new Node<T> {
		.value = value,
		.prev = NULL,
		.next = NULL,
	};
	if (length == 0) {
		top = node;
	}
	else {
		Node<T> *t = top;
		t->prev = node;
		node->next = t;
		top = node;
	}
	length += 1;
}

template<class T>
void Stack<T>::printElements() const {
	Node<T> *node = top;
	while (node != NULL) {
		std::cout << "Node: " << node->value << std::endl;
		node = node->next;
	}
}

template Stack<int>::Stack();
template Stack<int>::~Stack();
template void Stack<int>::push(int value);
template void Stack<int>::printElements() const;
