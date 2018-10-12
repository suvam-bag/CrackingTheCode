/*Sorted search, No size: You are given an array-like data structure Listy which lacks a size method. It does, however have an elementAt(i) method that returns 
the element at index i in O(1) time. If i is beyond the bounds of the data structure, it returns -1 (For this reason the data structure only supports positive integers). Given a Listy which contains sorted, positive integers, find the index at which an element x occurs. If x occures multiple times, you may return any index. 

Soln - Binary search - O(logN)
Problem - Binary search requires length of array
Soln - We increase idx exponentially until we get -1
Note - the binary search shouldn't fall outside the binaries
*/


int search(Listy list, int value) {
	int idx = 1;
	while (list.elementAt(idx) != -1 && list.elementAt(idx) < value) {
		idx *= 2; //1,2,4,8,16.....O(logN)
	}
	return binarySearch(list, value, idx/2, idx);
}

int binarySearch(Listy list, int value, int low, int high) {
	int mid;
	while (low <= high) {
		mid = (low+high)/2;
		int middle = list.elementAt(mid);
		//check mid is not out of bounds
		if (middle > value || middle == -1) {
			high = mid - 1; //left half
		}
		else if (middle < value) {
			low = mid + 1; //right half
		}
		else {
			return mid; //mid = value
		}
	}
	return -1; //not found
}