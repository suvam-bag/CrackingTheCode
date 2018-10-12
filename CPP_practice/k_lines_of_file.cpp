/*Last K lines: Write a method to print the last K lines of an input file using c++*/

//Soln 1 - Read the no of lines (N) and print (N-K) to Nth line. But this requires reading the file twice. 
//Soln 2 - Keep track of K lines read in a circular array.

#include <iostream>
#include <fstream>

using namespace std;

class lastK {
public:
	void printLastK(char *fileName) {
		const int K=10;
		ifstream file(fileName); //Input stream class to operate on files.
		string L[K];
		int size=0;

		//read file line by line into circulsr array
		//peek() so an EOF following a line ending is not considered a separate line
		while (file.peek() != EOF) {
			getline(file, L[size % K]);
			size ++;
		}

		/*compute start of a circular array, and the size of it*/
		int start = size > K ? (size % K) : 0;
		int count = min(K, size);

		/*print elements in the order they were read*/
		for (int i=0; i<count; i++) {
			cout << L[(start + i) % K] << "\n";
		}

	}
};

int main() { 
	lastK lastk;
	lastk.printLastK("sample.txt");
	return 0;
}