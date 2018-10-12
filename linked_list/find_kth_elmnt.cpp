
/*Return Kth to Last : Implement an algorithm to find the kth to last element of a singly linked list */

#include <iostream>
#include <utility>

using namespace std;

struct node {
	int data;
	node *next;
};

//Soln - Iterative

class Iterative {
private: 
	node *head, *tail;
public:
	//inseet node in the tail
	virtual	void insert_end(int val) { //void insert_end()
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

	//display linked list
	virtual	void display() {
		node *temp = new node;
		temp = head;
		while (temp != NULL) {
			cout << temp->data << "\t";
			temp = temp->next; //increment by one position
		}
		cout << "\n";
	}

	int kthToNth(int k) {
		node *p1 = new node;
		node *p2 = new node;

		p1=p2=head;

		for (int i=0; i < k; i++) { //O(k)
			if (p1 != NULL) 
				p1 = p1->next; //p1 is at k
		}

		//Since p1 is looping from k to N
		//p2 will end at (N-k)
		while (p1 != NULL) { //loop from k to N
			p1 = p1->next;
			p2 = p2->next;

		}
		return p2->data;
	}

};

int main() {
	Iterative obj;
	obj.insert_end(2);
	obj.insert_end(3);
	obj.insert_end(4);
	obj.insert_end(5);
	obj.insert_end(6);
	obj.insert_end(7);
	obj.display();
    int elmnt;
    elmnt = obj.kthToNth(4);
    cout << elmnt << "\n";
	return 0;
}


