/* Rotate matrix  
Soln - Transpose + reverse - O(N(N-1)) + O(N/2) - O(N^2) */

#include <iostream>

using namespace std;

class rotateMatrix {
public:
	void transpose(int matrix[][3], int N){
		for (int i=0; i<N; i++){
			for (int j=i+1; j<N; j++) {
				if (i != j) 
					swap(matrix[i][j], matrix[j][i]);
			}
		}
	}

	void reverse(int row[], int N){
		for (int i=0; i<N/2; i++) {
			swap(row[i], row[N-i-1]);
		}
	}	

	void rotate(int matrix[][3], int N) {
		transpose(matrix, N);
		for (int i=0; i<N; i++) {
			reverse(matrix[i],N);
		}
	}
};

int main() {
	int matrix[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	rotateMatrix rotMtrx;
	rotMtrx.rotate(matrix, 3);
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			cout << matrix[i][j] << ", ";
		}
		cout << "\n";
	}
	cout << "\n";
	return 0;
}