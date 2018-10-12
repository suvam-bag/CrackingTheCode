/* Sparse search - Given a sorted array of strings with empty strings interparsed, find the location of a string

Ex - Input: ball, {"at", "", "", "ball", "", "", "", "car"}
Output - 3

Tip - Binary search but take care of the empty strings - O(logN)
shift pointer when empty string found, see below
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class searchParse {
public:
	int binarySearch(string strArray[], string str, int first, int last) {
		if (first > last) {
			return -1;
		}
		if (str == "") {
			return -1;
		}

		int mid = (first+last)/2;

		//if mid is empty, find closest non-empty string
		if (strArray[mid] == "") {
			int left = mid - 1;
			int right = mid + 1;
			while(true) {
				if (left < first && right > last) {
					return -1;
				}
				else if (right <= last && strArray[right] != "") {
					mid = right;
					break;
				}
				else if (left >= first && strArray[left] != ""){
					mid = left;
					break;
				}
				right++;
				left--;
			}
		}

		if (str.compare(strArray[mid]) == 0) {
			return mid;
		}
		else if (str.compare(strArray[mid]) > 0) {//search right
			return binarySearch(strArray, str, mid+1, last);
		}	
		else {
			return binarySearch(strArray, str, first, mid-1);
		}
	}

};

int main(){
	string strArray[] = {"at", "", "", "ball", "", "", "car"};
	int idxValue = 0;
	string str = "car";
	searchParse srchPrse;
	//idxValue = srchPrse.search(strArray, str);
	int N = sizeof(strArray)/sizeof(strArray[0]);
	idxValue = srchPrse.binarySearch(strArray, str, 0, N-1);
	cout << "pos of string is, " << idxValue << "\n";
	return 0;
}