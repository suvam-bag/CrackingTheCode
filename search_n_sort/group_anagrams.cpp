/* Group Anagrams: Write a Method to sport an array of strings so that all the
anagrams are next to each other
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class AnagramCompare {
public:
	bool compareTo(string a, string b) {
		if (a.length() != b.length()) {
			//cout << "length not equal" << "\n";
			return false;
		}
		else {
			sort(a.begin(), a.end());
			sort(b.begin(), b.end());
			if (a.compare(b) == 0) {
				//cout << a << ' ' << b << ' ' << "true" << "\n";
				return true;
			}
			else{
				//cout << "string are not same" << "\n";
				return false;
			}
		}
	}
};



int main(){
	AnagramCompare AngComp;
	string arr1[] = {"hello", "yogota", "sweet", "olleh", "etews"};
	string arr[] = {"hello", "yogota", "sweet", "olleh", "etews", "reoodjo", "cdbhv", "ogyota"};
	int N = sizeof(arr)/sizeof(arr[0]);
	int i=0;

	while (i < N) {
		int ct=1;
		for (int j=i+1; j<N; j++){
			if (AngComp.compareTo(arr[i], arr[j])) {
				swap(arr[j], arr[i+ct]);
				ct += 1;

			}			
		}
		i += ct;
	}

	for (int i=0; i<N; i++) {
		cout << arr[i] << "\n";
	}
	return 0;
}