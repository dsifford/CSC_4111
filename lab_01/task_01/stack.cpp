#include <iostream>
#include <stdexcept>

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
	if (length == CAPACITY) {
		throw std::length_error("Stack is full");
	}
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
T Stack<T>::pop() {
	if (length == 0) {
		throw std::length_error("Stack is empty");
	}
	Node<T> *node = top;
	top = node->next;
	top->prev = NULL;
	T value = node->value;
	delete node;
	length--;
	return value;
}

template<class T>
int Stack<T>::isEmpty() const {
	return length == 0;
}

template<class T>
int Stack<T>::numOfElements() const {
	return length;
}

template<class T>
void Stack<T>::printElements() const {
	Node<T> *node = top;
	std::cout << "+--------+" << std::endl
			  << "|  TOP   |" << std::endl;
	while (node != NULL) {
		std::cout << node->value << std::endl;
		node = node->next;
	}
	std::cout << "| BOTTOM |" << std::endl
			  << "+--------+" << std::endl;
}

template Stack<int>::Stack();
template Stack<int>::~Stack();
template void Stack<int>::push(int value);
template int Stack<int>::pop();
template int Stack<int>::isEmpty() const;
template int Stack<int>::numOfElements() const;
template void Stack<int>::printElements() const;
