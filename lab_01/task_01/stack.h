#ifndef STACK_H
#define STACK_H

#include <cstddef>

template <typename T>
struct Node {
	T value;
	Node<T> *prev;
	Node<T> *next;
};

template<class T>
class Stack {
	public:
		static const size_t CAPACITY = 50;

		Stack();
		~Stack();
		/**
		 * Pushes an element into the stack.
		 */
		void push(T value);

		/**
		 * Pops an element from the stack and returns its value.
		 */
		T pop();

		/**
		 * Returns 1 if the stack is empty, 0 otherwise.
		 */
		int isEmpty() const;

		/**
		 * Returns the number of elements in the stack.
		 */
		int numOfElements() const;

		/**
		 * Print out the current stack to the console.
		 */
		void printElements() const;

	private:
		Node<T> *top;
		size_t length;
};

#endif
