/*Write code to remove duplicates from an unsorted linked list*/

/* Soln - Store elements in hash table and check duplicates & remove iterating through linked list*/

#include <iostream>
using namespace std;

struct node {
	int data;
	node *next;
};



class list {
private:
	node *head, *tail;
	bool hash[100];
public:

	list() {
		head = NULL;
		tail = NULL;
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



	//display linked list
	void display(node *head) {
		node *temp = new node;
		temp = head;
		while (temp != NULL) {
			cout << temp->data << "\t";
			temp = temp->next; //increment by one position
		}
	}

	void remove(node *head) {
		if (head==NULL)
			return;
		node *pre = head;
		node *cur = pre->next;
		hash[head->data] = true; //make hash table
		while (cur) {
			if(hash[cur->data]){
	            node *t = cur;
	            pre->next = cur->next;
	            cur = pre->next;
	            delete t;
	        }
	        else{
	            hash[cur->data] = true;
	            pre = cur; cur = cur->next;
	        }
	

		}
	}

	//two pointers current wehich iterates through the linked list
	//and runner which checks all subsequesnt nodes for duplicates

	void remove1(node *head){
	    if(head==NULL) return;
	    node *p, *q, *c=head;
	    while(c){
	        p=c; q=c->next;
	        int d = c->data;
	        while(q){
	            if(q->data==d){
	                node *t = q;
	                p->next = q->next;
	                q = p->next;
	                delete t;
	            }
	            else{
	                p = q; q = q->next;
	            }
	        }
	        c = c->next;
	    }
	}
};

int main() { 
	list obj;
	int n = 4;
    int a[] = {25,50,50,40};
    node *head = obj.init(a, n);
	//node *head = obj.insert_start(25);
	//node *head = obj.insert_start(50);
	//node *head = obj.insert_start(50);
	//node *head = obj.insert_start(40);
	cout<<"\n--------------------------------------------------\n";
	cout<<"---------------Displaying All nodes---------------";
	cout<<"\n--------------------------------------------------\n";
	obj.display(head);
	cout<<"\n--------------------------------------------------\n";
	cout<<"-----------------Deleting duplicates-----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.remove(head);
	cout<<"\n--------------------------------------------------\n";
	cout<<"---------------Displaying All nodes---------------";
	cout<<"\n--------------------------------------------------\n";
	obj.display(head);
	cout<<"\n--------------------------------------------------\n";
	return 0;
}