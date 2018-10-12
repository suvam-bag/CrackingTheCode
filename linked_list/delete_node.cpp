/*Implement an algorithm to delete a node in the middle (i.e - any node but 
the first and the last node, not necessarily the exact middle) of a singly 
linked list, given only access to that node*/\


#include <iostream>
using namespace std;

//declare single linked list struct
struct node {
	int data;
	node *next;
};

class list {
private:
	node *head, *tail;
public:
	//constructor
	list() {
		head=NULL;
		tail=NULL;
	}

	//inseet node in the tail
	void insert_end(int val) { //void insert_end()
		node *temp = new node; //create temp node
		temp->data = val;
		temp->next = NULL; //new node in the end becomes tail pointing to NULL
		if (head==NULL) {  //zero current elements
			head=temp;
			tail=temp;
			temp=NULL;
		}
		else {
			tail->next = temp; //exisiting tail moves up by one position
			tail = temp; //new element becomes tail
		}
	}

	node* init(int a[], int n){
	    node *head, *p;
	    for(int i=0; i<n; ++i){
	        node *nd = new node();
	        nd->data = a[i];
	        if(i==0){
	            head = p = nd;
	            continue;
	        }
	        p->next = nd;
	        p = nd;
	    }
	    return head;
	}

	//delete at a specific position
	bool delete_node(node *Node) {
		 if (Node == NULL || Node->next == NULL) {
		 	return false;
		 }

		node *temp = new node;
		temp = Node->next;
		//temp->data = temp->data;
		temp->next = Node->next;
		return true;

	}
};

int main() {
	list obj;
	int n = 4;
    int a[] = {25,50,50,40};
    node *head = obj.init(a, n);

    if (obj.delete_node(head)){ cout << " head deleted\n"; }
	return 0;
}