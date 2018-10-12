/*Zero matrix - Write an algorithm such that if an element is 0 in a MxN matrix, its entire row and col are set to 0*/
/* Sol1 - Brute force - O(MN) + O(N) + O(M) , space - O(M+N) */
/* Sol2 - By using the first row and column to store whether or not a row or column will be zeroed, we can reduce the space complexity to O(MN)*/

#include <iostream>

using namespace std;

class zeroMatrix {
public:
	void nullifyRow(int matrix[][3], int col, int row) { //M=row, N=col
		for (int i=0; i<col; i++) {
			matrix[row][i] = 0;
		}
	}

	void nullifyCol(int matrix[][3], int col, int row) { 
		for (int i=0; i<row; i++) {
			matrix[i][col] = 0;
		}
	}

	void nullifyMatrix(int matrix[][3], int col, int row) {
		//first row
		bool firstRow = false;
		for (int i=0; i<col; i++) {
			if (matrix[0][i] == 0) {
				firstRow = true;
				break;
			}
		}

		//rest of matrix
		for (int i=1; i<row; ++i) {
			bool nullifyThisRow = false;
			for (int j=0; j<col; ++j) {
				if (matrix[i][j] == 0) {
					matrix[0][j] = 0;
					nullifyThisRow = true;
				}
			}
			if (nullifyThisRow)
				nullifyRow(matrix, col, i);
		}

		//noe we know which column to nullify using information from the aboge steps
		//cols first
		for (int j=0; j<col; j++) {
			if (matrix[0][j] == 0) {
				nullifyCol(matrix, row, j);
			}
		}

		//first row
		if (firstRow)
			nullifyRow(matrix, col, 0);
	}
};

/*from cracking the code solutions*/
class zeroMatrix2 {
public:
	void nullifyRow( int matrix[][3], int N, int row ) {
	for ( int j = 0; j < N; ++j ) {
		matrix[row][j] = 0;
	}
}

void nullifyCol( int matrix[][3], int M, int col ) {
	for ( int i = 0; i < M; ++i ) {
		matrix[i][col] = 0;
	}
}


void nullifyMatrix( int matrix[][3], int M, int N ) {
	bool firstRow = false;

	//first row
	for( int i = 0; i < N; ++i ) {
		if ( matrix[0][i] == 0 ) {
			firstRow = true;
			break;
		}
	}

	//rest of the matrix
	for( int i = 1; i < M; ++i ) {
		bool nullifyThisRow = false;
		for ( int j = 0; j < N; ++j ) {
			if ( matrix[i][j] == 0 ) {
				matrix[0][j] = 0;
				nullifyThisRow = true;
			}
		}
		if (nullifyThisRow)
			nullifyRow(matrix, N, i);
	}

	//now we know which column to be nullify using information stored in previous step.
	//cols first
	for ( int j = 0; j < N; ++j ) {
		if ( matrix[0][j] == 0 ) {
			nullifyCol(matrix, M,  j);
		}
	}

	//now first row
	if ( firstRow ) {
		nullifyRow(matrix, N, 0);
	}

}
};

int main() {
	int matrix[3][3] = {{1,2,3},{4,0,6},{7,8,9}};
	

	zeroMatrix2 zmtrx;
	zmtrx.nullifyMatrix(matrix, 3, 3);
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			cout << matrix[i][j] << ", ";
		}
		cout << "\n";
	}
	cout << "\n";
	return 0;
}