/*Implement a function to see if the linked list is a palindrome*/

#include <iostream>
using namespace std;


struct node{
	int data;
	node *next;
};

class list {
private:
	node *head, *tail;
public:
	void insert_end(int val) {
		node *temp = new node;
		temp->data = val;
		temp->next = NULL;
		if (head == NULL) {
			head = temp;
			tail = temp;
			temp = NULL;
		}
		else {
			tail->next = temp;
			tail = temp;
		}
	}

	void reverse(node * & head) {
		node *newHead = NULL;
		node *nextNode = NULL;
		node *curr = head;

		//if (head != NULL || (head && (head->next != NULL))) {
			while (curr->next != NULL) {
				//cout << curr->data;
				nextNode = curr->next;
				curr->next = newHead;
				newHead = curr;
				curr = nextNode;
				//cout << curr->data;
			}
			curr->next = newHead;
			//cout << newHead->data;
			//cout << curr->data;
			head = curr;
		//}
	}

	bool isPalindrome() {
	  // if list is empty or just contains one node.
	  if ( head == nullptr || head->next == nullptr ) {
	    return true;
	  }

	  //step1 figure out middle node.
	  node * ptr1 = head;
	  node * ptr2 = head;
	  node * middleNode = nullptr;

	  while( ptr2 && ptr1 && ptr1->next) {
	    ptr1 = ptr1->next->next;
	    ptr2 = ptr2->next;
	  }

	  //in case of odd number of nodes, skip the middle one
	  if ( ptr1 && ptr1->next == nullptr ) {
	    ptr2 = ptr2->next;
	  }


	  //reverse the second half of the list
	  reverse(ptr2);

	  middleNode = ptr2;
	  // now compare the two halves
	  ptr1 = head;

	  while( ptr1 && ptr2 && ptr1->data == ptr2->data ) {
	    ptr1 = ptr1->next;
	    ptr2 = ptr2->next;
	  }

	  //reverse the list again.
	  reverse(middleNode);

	  if ( ptr2 == nullptr ) {
	    return true;
	  } else {
	    return false;
	  }
	}
	

	void display() {
		node *temp = new node;
		temp = head;
		while (temp) {
			cout << temp->data << "\t";
			temp = temp->next;
		}
		cout << "\n";
	}

	

};

int main() {
	list* obj = new list();
	obj->insert_end(1);
	obj->insert_end(2);
	obj->insert_end(2);
	obj->insert_end(1);
	cout<<"\n--------------------------------------------------\n";
	cout<<"---------------Displaying All nodes---------------";
	cout<<"\n--------------------------------------------------\n";
	obj->display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"-----------------reverse-----------------";
	cout<<"\n--------------------------------------------------\n";
	//obj->reverse();
	cout<<"\n--------------------------------------------------\n";
	cout<<"---------------Displaying All nodes---------------";
	cout<<"\n--------------------------------------------------\n";
	//obj->display();
	if (obj->isPalindrome()) {
		cout << "list is palindrome\n";
	}
	return 0;
}