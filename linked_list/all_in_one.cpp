/* Node1 - {data1, next1} - head
Node2 (address = head->next) = {data2, next2}
Node3 (address = Node2->next) = {NULL, some address} - tail*/

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

	//display linked list
	void display() {
		node *temp = new node;
		temp = head;
		while (temp != NULL) {
			cout << temp->data << "\t";
			temp = temp->next; //increment by one position
		}
	}

	int list_size() {
		int count = 0;
		node* temp = new node; 
		while (temp != NULL) 
		{ 
		  ++count; 
		  temp = temp->next; 
		}
		return count;
	}

	//insert in beginning
	void insert_start(int val) {
		node *temp = new node;
		temp->data = val;
		temp->next = head; //current head moves down by 1 position
		head = temp; //new node becomes head
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

	//insert node at a specific position
	void insert_pos(int pos, int val) {
		node *pre = new node;
		node *temp = new node;
		node *cur = new node;
		cur = head;
		for (int i=1; i < pos; i++) { //observe the loop logic
			pre = cur;
			cur = cur->next;
		} //at the end of the loop, cur->next is pointing to temp[pos+1]
		temp->data = val;
		pre->next = temp;
		temp->next = cur;
	}

	//delete the first element
	void delete_start() {
		node *temp = new node;
		temp = head; //make temp the current head
		head = head->next; //previous head becomes next element
		delete temp; //delete the first element
	}

	//delete last element
	void delete_end() {
		node *cur = new node;
		node *pre = new node;
		cur = head; //start
		while (cur->next != NULL) { //last element = NULl
			pre = cur;
			cur = cur->next; //iterate
		} //ends at pre = (last element - 1)
		tail = pre;
		pre->next = NULL;
		delete cur;
	}

	//delete at a specific position
	void delete_pos(int pos) {
		 node *pre = new node;
		 node *cur = new node;
		 cur = head;
		 for (int i=1; i<pos; i++) {
		 	pre = cur;
		 	cur = cur->next;
		 }
		 pre->next = cur->next;
	}

};


int main() {
	list obj;
	obj.insert_end(25);
	obj.insert_end(50);
	obj.insert_end(90);
	obj.insert_end(40);
	cout<<"\n--------------------------------------------------\n";
	cout<<"---------------Displaying All nodes---------------";
	cout<<"\n--------------------------------------------------\n";
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"-----------------Inserting At End-----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.insert_end(55);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"----------------Inserting At Start----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.insert_start(50);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"-------------Inserting At Particular--------------";
	cout<<"\n--------------------------------------------------\n";
	obj.insert_pos(5,60);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"----------------Deleting At Start-----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.delete_start();
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"-----------------Deleing At End-------------------";
	cout<<"\n--------------------------------------------------\n";
	obj.delete_end();
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"--------------Deleting At Particular--------------";
	cout<<"\n--------------------------------------------------\n";
	obj.delete_pos(4);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	return 0;
}