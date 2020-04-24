#include <iostream>
#include "Node.h"

template<typename T> class Stack {
private:
	Node<T>* head;
	int size;
public:
	Stack() : size(0), head(nullptr) {};

	~Stack() {
		Node<T>* curr = this->head;
		while (curr != nullptr) {
			Node<T>* prev = curr;
			curr = curr->get_next();
			delete prev;
		}
	}
	void push(T data) {
		Node<T>* n = new Node<T>(data);
		n->set_next(this->head);
		this->head = n;
		this->size++;
	}

	T pop() {
		if (this->is_empty()) {
			return NULL;
		}
		Node<T>* n = this->head;
		this->head = this->head->get_next();
		this->size--;
		return n->get_data();
	}

	T peek() {
		if (this->is_empty()) {
			return NULL;
		}
		return this->head->get_data();
	}
	bool is_empty() {
		if (this->size == 0 && this->head == nullptr) {
			return true;
		}
		return false;
	}
};
