/*Sorted Matrix Search: Given MxN matrix in which each row and each column is sorted 
in ascending order, write a method to find an element

Solutions - 
1. Brute force - O(N^2)
2. Binary search in each row - O(Mlog(N)) - M rows, N columns
3. Optimal - 
...a. If the start of a column is > x, x is to the left of col
...b. If the start of a row is > x, x is up the row
...c. If the end of a column is < x, x is to the right of col
...d. If the end of a row is < x, x is down the row

Iteratively apply this soln 


15 20 40 85
20 35 80 95
30 55 95 105
40 80 100 120

x=55

Lets try steps 3.a and 3.d
*/

#include <iostream>

using namespace std;

class searchMatrix {
public:
	const static int rowM = 4;
	const static int colM = 4;
	bool search(int matrix[rowM][colM], int x) {
		int row = 0; //start of col
		int col = colM - 1; //end of row
		while (row < rowM && col >= 0) {
			if (matrix[row][col] == x) {
				return true;
			}
			else if (matrix[row][col] > x) {
				col--;
			}
			else {
				row++;
			}
		}
		return false;
	}
};

int main(){
	int matrix[4][4] = {{15, 20, 40, 85},{20, 35, 80, 95},{30, 55, 95, 105},{40, 80, 100, 120}};
	int element = 55;
	searchMatrix srchMtrx;
	if(srchMtrx.search(matrix, element)){
		cout << "element found" << "\n";
	}
	return 0;
}

