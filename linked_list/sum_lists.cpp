/*Sum Lists : 
Input : (7 -> 1 -> 6) + (5 -> 9 -> 2). That is, 617 + 295
Output : 2 -> 1 -> 9 i.e - 912*/

#include <iostream>
using namespace std;

struct node {
	int data;
	node *next;
	node (int d) : data{d}, next{nullptr} {}
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

	int length( node * head ) {
	  int len = 0;
	  while( head ) {
	    len++;
	    head = head->next;
	  }
	  return len;
	}

	//display linked list
	void display(node *head) {
		while (head) {
			cout << head->data << "\t";
			head = head->next; //increment by one position
		}
		cout << "\n";
	}

	//insert at tge beginning
	void insert(node * & head, int val) {
		node *temp = new node(val);
		temp->next = head;
		head = temp;
	}

	node *add_recursive(node *list1, node *list2, int carry) {
		if (list1 == nullptr && list2 == nullptr && carry == 0) {
			return nullptr;
		}
		int val = carry;
		if (list1) 
			val += list1->data;
		if (list2)
			val += list2->data;

		node *resultNode = new node(val % 10);
		resultNode->next = add_recursive( list1 ? (list1->next) : nullptr,
										  list2 ? (list2->next) : nullptr,
										  val > 9 ? 1 : 0);
		return resultNode;
	}
};

int main() {
	list obj1;
	node *list1 = nullptr;
	obj1.insert(list1, 6);
	obj1.insert(list1, 1);
	obj1.insert(list1, 7);
	obj1.display(list1);
	list obj2;
	node *list2 = nullptr;
	obj2.insert(list2, 2);
	obj2.insert(list2, 9);
	obj2.insert(list2, 5);
	obj2.display(list2);
	node *list3 = obj2.add_recursive(list1, list2, 0);
	obj2.display(list3);
	return 0;
}