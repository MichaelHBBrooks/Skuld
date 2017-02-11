class Node {
public:
	Node* next;
	int data;

	Node(int new_data);
	Node();
};

class LinkedList{
public:
	Node* head;

	LinkedList();
	~LinkedList();

	void appendToTail(int new_data);
	void printLinkedList(const Node& some_node);
};
