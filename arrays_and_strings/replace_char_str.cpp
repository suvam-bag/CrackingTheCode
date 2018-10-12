/*Replace all spaces in a string with "%20". You may assume that the sufficient 
space to hold the additional characters, thst you are given the true length of the string.*/

//optimal soln - O(N) - find the extended length of the string after compensating for the length
//a_bcd
//a02/bcd

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void urlity(string &str, int len) {
	int numOfSpaces = 0;
	for (int i=0; i<len; i++) {
		if (str[i] == ' ') {
			numOfSpaces++;
		}
	}
	int extendedLen = len + 2*numOfSpaces;
	int i = extendedLen - 1;
	for (int j=len-1; j<=0; j--) {
		if (str[j] != ' ') {
			str[i--] = str[j];
		}
		else {
			str[i--] = '0';
			str[i--] = '2';
			str[i--] = '/';
		}
	}
}

int main() {
	string str("a_bcd");
	int N = str.length();
	//char str[] = {"abc_defg_hijk"};
	//int N = sizeof(str)/sizeof(str[0]);
	urlity(str, N);
	for (int i=0; i<N; i++) {
		cout << str[i];
	}
	cout << "\n";
	return 0;
}

