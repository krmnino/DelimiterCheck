#include "Stack.h"

template<typename T> Stack<T>::~Stack<T>() {
	Node<T>* curr = this->head;
	while (curr != nullptr) {
		Node<T>* prev = curr;
		curr = curr->get_next();
		delete prev;
	}
}

template<typename T> void Stack<T>::push(T data) {
	Node<T>* n = new Node<T>(data);
	n->set_next(this->head);
	this->head = n;
	this->size++;
}

template<typename T> T Stack<T>::pop() {
	if (this->is_empty()) {
		return NULL;
	}
	Node<T>* n = this->head;
	this->head = this->head->get_next();
	this->size--;
	return n->get_data();
}

template<typename T> T Stack<T>::peek() {
	if (this->is_empty()) {
		return NULL;
	}
	return this->head->get_data();
}

template<typename T> bool Stack<T>::is_empty() {
	if (this->size == 0 && this->head == nullptr) {
		return true;
	}
	return false;
}
