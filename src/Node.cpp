#include "Node.h"

template<typename T> void Node<T>::set_data(T d) {
	this->data = d;
}

template<typename T> void Node<T>::set_next(Node* n) {
	this->next = n;
}

template<typename T> T Node<T>::get_data() {
	return this->data;
}

template<typename T> Node<T>* Node<T>::get_next() {
	return this->next;
}
