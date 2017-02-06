class Node {
public:
	Node* next;
	int data;

	Node(int new_data);
};

class LinkedList{
public:
	Node* head;

	LinkedList();
	~LinkedList();

	void appendToTail(int new_data);
	void printLinkedList(const Node& some_node);
};
