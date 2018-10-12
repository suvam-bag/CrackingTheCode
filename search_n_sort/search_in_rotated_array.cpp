/*Search in rotated array: Given a sorted array of n integers that has been rotated 
an unknown no of times, write code t find an element in the array. You may assume
that the array was sorted in descending order 

Ex - {20,15,13,10,7,4,1}
case 1: Rotation by N to bring back to the original
case 2: Rotation clockwise by 2: {4,1,20,15,13,10,7}    //right is ordered
case 3: Rotatio anticlockwise by 2: {13,10,7,4,1,20,15} //left is ordered

Binary search - 
mid = N/2
case 1: mid = a[mid] = 10
case 2: mid = a[mid] = 15
case 3: mid = a[mid] = 4 

if array is {2,2,2,3,4,2} then you have to search both

element to search

Average - O(logN)
When there are many duplicates, sserahc both left and right - O(n)
*/

#include <iostream>

int search(int a[], int left, int right, int x) {

	int mid = (left+right)/2;
	if (x==a[mid]) { //found element
		return mid;
	}
	if (right < left) {
		return -1;
	}

	//Either left or right is ordered depending on direction of rotation
	//find out which side is normally ordered to search 
	if (a[left] > a[mid]) { //left is ordered
		if (x <= a[left] && x > a[mid]) {
			return search(a, left, mid-1, x); //search left
		}
		else{
			return search(a, mid+1, right, x); //search right
		}
	}
	else if (a[left] < a[mid]) { //right is ordered
		if (x >= a[right] && x < a[mid]) {
			return search(a, mid+1, right, x); //search right
		}
		else {
			return search(a, left, mid-1, x); //search left
		}
	}
	else if (a[left] == a[mid]) { //left or right half is all repeats
		if (a[mid] != a[right]) { //right is different
			return search(a, mid+1, right, x);
		}
		else{ //search both halves
			int result = search(a, left, mid-1, x); //search left
			if (result == -1){
				return search(a, mid+1, right, x); //search right
			}
			else{
				return -1;
			}
		}
	}

	return -1;
}

int main(){
	int a[] = {4,1,20,15,13,10,7};
	int left = 0;
	int right = sizeof(a)/sizeof(a[0])-1;
	int result = 0;
	int x = 25;
	result = search(a,left,right,x);
	if (result != -1) {
		std::cout << "idx of element" << result << "\n"; 
	}
	else {
		std::cout << "element not found" << "\n";
	}
	return 0;
}
