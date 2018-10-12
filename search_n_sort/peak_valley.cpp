/*Peaks and valleys

Input - {5,3,1,2,3} - unsorted array
Output - {5,1,3,2,3}


*/

#include <iostream>
#include <algorithm>


using namespace std;

/*Soln -1 O(NlogN)*/
//sort
//compare pairs

class sol_1 {
public:
	void peakValley(int array[], size_t arr_size) {
		int N = arr_size;
		sort(array, array+N);
		for (int i=0; i < N; i++) {
		cout << array[i];
		cout << "\n";
	}
		for (int i=1;i<N;i+=2) {
			swap(array, i-1, i);
		}
	}

	void swap(int array[], int left, int right) {
		int temp = array[left];
		array[left] = array[right];
		array[right] = temp;
	}
};

/*Soln - 2 - O(N)*/
//take a set of 3 nos at a time, place the highest in the middle

class sol_2 {
public:
	void peakValley(int arr[], size_t arr_size) {
		int N = arr_size;
		for (int i=1;i<N;i+=2) {
			int largestIdx = maxIdx(arr, i-1, i, i+1);
		
		if (largestIdx != i)
			swap(arr, i, largestIdx);
		}	
	}

	void swap(int arr[], int left, int right) {
		int temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
	}

	int maxIdx(int arr[], int a, int b, int c) {
		int max = maxElement(arr[a], maxElement(arr[b], arr[c]));
		if (a == max) { return a;}
		else if (b == max) { return b;}
		else { return c;}	
	}

	int maxElement(int a, int b) {
		return (a > b) ? a : b;
	}
};

int main() {
	int arr[] = {5,3,1,2,3};
	int N = sizeof(arr)/sizeof(arr[0]);
	sol_1 sol;
	sol.peakValley(arr, N);
	for (int i=0; i < N; i++) {
		cout << arr[i];
		cout << "\n";
	}
}