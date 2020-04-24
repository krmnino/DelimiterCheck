template<typename T> class Node {
private:
	T data;
	Node* next;
public:
	Node(T data) : data(data), next(nullptr) {}

	~Node() {};

	void set_data(T data) {
		this->data = data;
	}

	void set_next(Node* n) {
		this->next = n;
	}
	T get_data() {
		return this->data;
	}

	Node* get_next() {
		return this->next;
	}
};