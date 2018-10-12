/*Reverse a string : Implemnt a function void reverse(char *str) in C++ which reverses a null terminated string */

#include <iostream>
#include <algorithm>

using namespace std;

class reverseString {
public:
	

	void reverse(char *str) {
		int N = strlen(str);
		if (N > 0) {
			int i=0, j=N-1;
			for (i=0; i<N/2; i++) {
				swap(str[i], str[j]);
				j--;
			}
		}	
	}
};

int main() {
	char str[] = {"hello\0"};
	reverseString rvrsStr;
	rvrsStr.reverse(str);
	for (int i = 0; i<strlen(str); i++) {
		cout << str[i];
	}
	cout << "\n";
	return 0;
}