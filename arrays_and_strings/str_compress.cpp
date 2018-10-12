/*String compress
aabccccaaa a2b1c4a3  - O(N) */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class compress {
public:
	string strCompress(string &s) {
		string str;
		int count = 1;
		for (int i=0; i<s.length(); i++) {
			if (s[i] == s[i+1]) {
				count += 1;
			}
			else {
				str += s[i];
				str += to_string(count);
				count = 1;
			}
		}
		if (str.length() >= s.length()) {
			return s;
		}
		else {
			return str;
		}
	}
};

int main() {
	string str("aabccccaaa");
	compress cmprs;
	string s;
	s = cmprs.strCompress(str);
	cout << s << "\n";
	return 0;
}