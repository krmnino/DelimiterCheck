#ifndef NODE
#define NODE

template<typename T> class Node {
private:
	T data;
	Node* next;
public:
	Node(T d) : data(d), next(nullptr) {}
	~Node() {};
	void set_data(T);
	void set_next(Node*);
	T get_data();
	Node* get_next();
};

#endif // !NODE
