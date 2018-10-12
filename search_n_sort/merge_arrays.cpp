/*Sorted Merge: You are given two sorted arrays, A and B, where A has a large enough buffer at the end to hold B. Write a method to merge B into A in sorted order*/
/* Trick - start from the end */
/* O(b) */

//this soln would work in C, for C++, use vectors//

#include <iostream>

class sortedMerge {
public:
	void mrg(int a[], int b[], int lastA, int lastB) {
		int idxA = lastA-1;
		int idxB = lastB-1;
		int idxMerged = idxA+idxB-1;

		//merge a and b starting from last element of each 
		while (idxB >= 0) {
			if (idxA >=0 && a[idxA] > b[idxB]) {
				a[idxMerged] = a[idxA];
				idxA--;
			}
			else{
				a[idxMerged] = b[idxB];
				idxB--;
			}
			idxMerged--;
		}
	}
};

int main() {
	int a[] = {0};
	int b[4] = {2,9,1,5};
	int lastA = 10;
	int lastB = 3;
	sortedMerge srtMrg;
	srtMrg.mrg(a,b,lastA,lastB);
	for (int i=0; i<lastA-1;i++){
		std::cout << a[i] << ', ';
	}
	return 0;
}