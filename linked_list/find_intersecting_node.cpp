/*Finf the intersecting node*/

//Soln  - 
//A. Get length and size of each list
//B. If tails are different, no intersection, return immediately
//C. Set 2 pointers to start of each linked list
//D. On the longer linked list, advance its pointer by the diferernce in length
//E. Now traverse on each linked list until the pointers are the same. 


#include <iostream>
#include <cmath>

using namespace std;

struct node {
	int data;
	node *next;
};

class list {
public:
	node *tail;
	//display linked list
	void display(node * head) {
		node *temp = new node;
		temp = head;
		while (temp != NULL) {
			cout << temp->data << "\t";
			temp = temp->next; //increment by one position
		}
	}

	int list_size(node * head) {
		int count = 0;
		node* temp = new node; 
		temp = head;
		while (temp != NULL) 
		{ 
		  ++count; 
		  temp = temp->next; 
		}
		return count;
	}

	//inseet node in the tail
	void insert_end(node *head, int val) { //void insert_end()
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

	node * intersectionPoint( node *list1, node *list2) {
		int len1 = list_size(list1);
		int len2 = list_size(list2);
		node *ptr1 = NULL;
		node *ptr2 = NULL;

		//ptr1 for bogger list and ptr2 for smaller list
		if (len1 > len2) {
			ptr1 = list1;
			ptr2 = list2;
		}
		else {
			ptr1 = list2;
			ptr2 = list1;
		}
		int i = 0;
		while (i < abs(len1-len2) && ptr1) {
			ptr1 = ptr1->next;
			i++;
		} //ptr1 is at the idx of start of list2

		while (ptr1 && ptr2) {
			if (ptr1 == ptr2) 
				return ptr1;
			ptr1 = ptr1->next;
			ptr1 = ptr1->next;
		}
		return nullptr; //no intersection
	}
};

int main() {
	list obj;
	node *list1 = NULL;
	node *list2 = NULL;
	obj.insert_end(list1, 50);
	obj.insert_end(list1, 90);
	obj.insert_end(list1, 40);
	obj.insert_end(list1, 30);
	obj.display(list1);

	obj.insert_end(list2, 70);
	obj.insert_end(list2, 40);
	obj.insert_end(list2, 30);
	obj.display(list2);

	node *intNode = obj.intersectionPoint(list1, list2);
	cout << "intersection node is " << intNode->data << "\n";


	return 0;
}