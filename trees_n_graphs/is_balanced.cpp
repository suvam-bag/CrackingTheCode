#include <iostream>

using namespace std;

struct node {
 int data;
 node *left;
 node *right;
};

void addEdge(int v, int w); //func to add edge to graph


void inOrder(node *node)
{
	if (node == NULL)
		return;
	inOrder(node->left);
	cout<< node->data <<" ";
	inOrder(node->right);
}

node* createMinimalBST(int arr[], int low, int high)
{
    if (low > high) {
        return NULL;
    }
    int mid = (low + high) / 2;
    // Allocate memory for new node  
  	node* temp = new node; 
    temp->data = arr[mid];
    temp->left = createMinimalBST(arr, low, mid - 1);
    temp->right = createMinimalBST(arr, mid + 1, high);
    return temp;
}

node *createMinimalBST(int arr[], int N)
{
    if (N == 0)
        return NULL;
    return createMinimalBST(arr, 0, (N - 1));
}

int checkHeight(node* root) {
	if (root == nullptr) {
		return 0;
	}
	int leftHeight = checkHeight(root->left);
	if (leftHeight == -1) {
		return -1;
	}
	int rightHeight = checkHeight(root->right);
	if (rightHeight == -1) {
		return -1;
	}

	if (abs(leftHeight - rightHeight) > 1) {
		return -1;
	}
	else {
		return max(leftHeight, rightHeight) + 1;
	}
}

bool isBalanced(node* root) {

	return (checkHeight(root) == -1);
}

int main() {
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int N = sizeof(arr)/sizeof(arr[0]);
	node *root = new node;
	root = createMinimalBST(arr, N);
	inOrder(root);
	if (isBalanced) {
		cout << "tree is not balanaced\n";
	}
	return 0;
}