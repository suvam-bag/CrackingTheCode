/*Partition: Write code to partition a linked list around a value x, such that
all nodes less than x come before all nodes greater than or equal to x. 
If x is contained within the list, the values of x only need ti be after the elements less than x. The partition element x can appear anywhere in the 
"right partition"; it does not need to appear between the left and right partitions*/

/*Segmentation fault - 
What the F is going on ?*/

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


	//insert in beginning
	void insert_start(int val) {
		node *temp_s = new node;
		temp_s->data = val;
		temp_s->next = head; //current head moves down by 1 position
		head = temp_s; //new node becomes head
	}

	void insert_end(int val) {
		node *temp_e = new node;
		temp_e->data = val;
		temp_e->next = NULL;
		if (head==NULL) {
			head = temp_e;
			tail = temp_e;
			temp_e = NULL;
		}
		else {
			cout << "55\n";
			tail->next = temp_e;
			cout << "63\n";
			tail = temp_e;
		}
	}

	void partition(node *Node, int x) {
		node *temp = NULL;
		while (Node->next != NULL) {	
			temp = Node->next;	
			if (Node->data < x) {
				cout << "65\n";
				insert_start(Node->data);
				cout << "67\n";
			}
			else {
				cout << "70\n";
				insert_end(Node->data);
				cout << "72\n";
			}
			Node = temp;
		}
		tail->next = NULL;

	}

	//display linked list
	void display(node *head) {
		node *temp = new node;
		temp = head;
		while (temp != NULL) {
			cout << temp->data << "\t";
			temp = temp->next; //increment by one position
		}
		cout << "\n";
	}

};

int main() {
	list obj;
	int n = 7;
    int a[] = {1,2,3,5,9,7,6};
    node *head = obj.init(a, n);
    obj.partition(head, 9);
    obj.display(head);
	return 0;
}