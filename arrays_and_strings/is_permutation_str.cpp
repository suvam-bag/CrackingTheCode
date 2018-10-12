/*Given 2 strings, find out if one is a permutation of the other*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

 
class findPerm {
public:
	//O(N^2)
	bool bruteForce(string &str1, string &str2) {
		if (str1.length() != str2.length()) {
			return false;
		}
		/*double for loop*/
		return true;
	}

	//O(NlogN)
	bool sortComp(string &str1, string &str2) {
		if (str1.length() != str2.length()) {
			return false;
		}
		sort(str1.begin(), str1.end());
		sort(str2.begin(), str2.end());
		if (str1.compare(str2) == 0) {
			return true;
		}
		return false;
	}

	//O(N)
	bool optimal(string &str1, string &str2) {
		if (str1.length() != str2.length()) {
			return false;
		}
		int count[256] = {0};
		for (int i=0; i<str1.length(); i++) {
			int val = str1[i];
			count[val]++;
		}
		for (int i=0; i<str2.length(); i++) {
			int val = str2[i];
			count[val]--;

			if (count[val] < 0) {
				return false;
			}
		}
		return true;
	}
};

int main() {
	string str1("hello");
	string str2("oelhl");
	findPerm fndprm;
	if (fndprm.bruteForce(str1, str2)) { cout << "str1 is a permutation of str2"; cout << "\n";}
	if (fndprm.sortComp(str1, str2)) { cout << "str1 is a permutation of str2"; cout << "\n";}
	if (fndprm.optimal(str1, str2)) { cout << "str1 is a permutation of str2"; cout << "\n";}
}