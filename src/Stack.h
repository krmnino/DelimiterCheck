#ifndef STACK
#define STACK

template<typename T> class Stack {
private:
	Node<T>* head;
	int size;
public:
	Stack() : size(0), head(nullptr) {};
	~Stack();
	void push(T);
	T pop();
	T peek();
	bool is_empty();
};
#endif // !STACK

