/**
 * Given a directed graph, design an algorithm to find out whether there is a route between two
 * nodes.
 *
 * Programmer response:
 * A directed graph? I don't remember what that is. This is why I'm refreshing my memory with these
 * interview questions...
 * Two Google searches later, I remember what these "digraphs" look like and I have a basic idea of
 * how to implement one.
 *
 * Now that I have the DigraphNode class created, I have to ask: am I looking for a bidirectional
 * route between two nodes or just one direction? This will impact the algorithm.
 *
 * I'm relying on other data structures quite a bit here. A map for visited nodes. A queue for
 * generating a list of nodes to visit. And a vector to store the adjacent nodes.
 */

#include<iostream>
#include<map>
#include<queue>
#include<vector>

class DigraphNode{
public:
	DigraphNode(int new_data_){
		data_ = new_data_;
	}

	void insert(DigraphNode* new_node_){
		neighbors_.push_back(new_node_);
	}

	void printNode(){
		std::cout << "Node: " << data_ <<  std::endl
				<< "Node's neighbors: ";
		for(auto itr : neighbors_){
			std::cout << itr->data_ << ' ';
		}
		std::cout << std::endl;
	}

	int data_;
	std::vector<DigraphNode*> neighbors_;
};

bool routeExists(DigraphNode* node_start_, DigraphNode* node_end_);

int main(){
	DigraphNode a(1);
	DigraphNode b(2);
	DigraphNode c(3);
	DigraphNode d(4);
	DigraphNode e(5);
	DigraphNode f(6);
	DigraphNode g(7);

	a.insert(&b);
	a.insert(&e);
	b.insert(&c);
	c.insert(&d);
	d.insert(&a);

	a.printNode();

	std::cout << "Does a route exist between a and c? " << std::boolalpha << routeExists(&a,&c) << std::endl;
	std::cout << "Does a route exist between a and g? " << std::boolalpha << routeExists(&a,&g) << std::endl;

	return 0;
}

bool routeExists(DigraphNode* node_start_, DigraphNode* node_end_){
	//  Some basic checks at the start.
	if(node_start_ == NULL){
		return false;
	}else if(node_end_ == NULL){
		return true;
	}else if(node_start_ == node_end_){
		return true;
	}
	//  We need to visit each child once. And since each child can lead off to other children, a
	//  list will need to be made. The queue makes it a breadth first search, but a depth first
	//  search could be useful depending on the graph.
	std::map<DigraphNode*,bool> visited_nodes;
	visited_nodes[node_start_] = true;
	std::queue<DigraphNode*> suspects;
	for(auto itr : node_start_->neighbors_){
		suspects.push(itr);
	}
	while(!suspects.empty()){
		DigraphNode* node = suspects.front();
		if(node == node_end_){
			return true;
		}
		suspects.pop();
		visited_nodes[node] = true;

		for(auto itr: node->neighbors_){
			if(visited_nodes[itr] == false){
				suspects.push(itr);
			}
		}
	}

	return false;
}
