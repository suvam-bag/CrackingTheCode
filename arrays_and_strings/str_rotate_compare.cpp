/*String rotation - Check is s2 is a roataion of s1 using only one substring call*/

//coln - concatenate s2+s1

// s1 - waterbottle
// s2 - erbottlewat

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class strRot {
public:
	bool isRot(string s1, string s2) {
		size_t len1 = s1.length();
		size_t len2 = s1.length();
		if (len1 == 0 || len1 != len2)
			return false;

		string str_concat = s1+s1;
		if (str_concat.find(s2) != string::npos) {
			return true;
		}
		else {
			return false;
		}

	}
};

int main() {
	string s1("waterbottle");
	string s2("erbottlewat");
	strRot strrot;
	if(strrot.isRot(s1,s2))
		cout << "s2 is a rotation of s1" << "\n";
	return 0;
}