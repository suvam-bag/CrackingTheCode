/*Copy Node - Write a method that takes a pointer to a Node structure as a parameter and returns a complete copy of the passed in data structure. 
The Node data structure contains two pointers to other Nodes. */

//Soln - The algorithm will maintain a mapping from a node address in the original structure to the corresponding node in the new structure.
//This mapping will allow us to discover previously copied nodes during a traditional DFS of the structure. Traversals often mark visited nodes
// - the mark can take many forms and does not necessarily need to be stored in the node.

#include <iostream>

using namespace std;

typedef map<Node*, Node*> NodeMap;
Node * copy_recursive(Node * cur, NodeMap & nodeMap) {
	if (cur == NULL) {
		return NULL;
	}


	NodeMap::iterator i = nodeMap.find(cur);
	if (i != nodeMap.end()) {
		//we have been before, return the copy
		return i -> second;
	}

	Node * node = new Node;
	nodeMap[cur] = node; //map current before traversing links
	node -> ptr1 = copy_recursive(cur->ptr1, nodeMap);
	node -> ptr2 = copy_recursive(cur->ptr2, nodeMap);
	return node;
}

Node *copy_structure(Node * root) {
	NodeMap nodeMap; // we will need an empty map
	return copy_recursive(root, nodeMap);
}