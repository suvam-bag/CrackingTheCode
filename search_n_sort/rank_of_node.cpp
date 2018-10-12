/*

					20(4)
				   /    \
			   15(3)     25(2)
				 /       /
			  10(1)     23(0)    
			   /  \      \
			5(0)  13(0)   24(0)

*/



int rank_of(NODE *tree, int val) {
	int rank = 0;
	while(tree) {
		if (val < tree->val) {
			tree = tree->left;
		}
		else if(val > tree->val) {
			rank += 1 + size(tree->left) //root + left subtree
			tree = tree->right;
		}
		else {
			return rank + size(tree->left);
		}
	}
	return -1;
}

