/* One away: There are 3 types of edits that can be performed on strings. Insert a char, remove a char, replace a char.
Given 2 strings, write a function to check if they are one edit (or zero edits away) 
Ex - 
pale, ple -> true
pale, pales -> true
pale, bale -> true
pale, bake -> false
*/

//sol1 - brute force - O(N^2)
//sol2 - sort and search - O(NlogN)
//sol3 - optimal - O(N)

#include <iostream>
#include <string>
#include <algorithm>

#define MAX 1000;

using namespace std;

class oneAway {
public: 
	bool isOneAway(string s1, string s2) {
		string a,b;
		a = s1.length() >= s2.length() ? s1 : s2;
		b = s1.length() < s2.length() ? s1 : s2;
		int len1, len2;
		len1 = a.length();
		len2 = b.length();
		if (abs(len1-len2)>1)
			return false;
		bool flag = false;
		for (int i=0,j=0;i<len1 && j<len2;) {
			if (a[i]!=b[j]) {
				if (flag)
					return false;
				flag=true;
				if (len1 == len2)
					i++,j++;
				else 
					i++;
			}
			else
				i++,j++;
		}
		return true;
	}

};

int main() {
	string str1("pale");
	string str2("ple");
	oneAway oneaway;
	if (oneaway.isOneAway(str1, str2)){
		cout << "one edit away" << "\n";
	}
	else {
		cout << "not one edit away" << "\n";
	}
	return 0;
}