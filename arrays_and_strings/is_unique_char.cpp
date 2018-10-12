/*Determine if the string has unique characters*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;


class charUnique {
public:
	//Brute force - O(N*(N-1))
	vector<char> bruteForce(string str) {
		vector<char> v;
		for (int i=0; i<str.length(); i++) {
			int count = 0;
			for (int j=i+1; j<str.length(); j++) {
				if (str[i] == str[j]) {
					count += 1;
				}
			}
			if (count == 0) {
				v.push_back(str[i]);
			}
		}
		return v;
	}

	//sort and search - O(NlogN)
	//sort - quicksort
	 
	  
	void quickSort(string &str, int left, int right) {
      int i = left, j = right;
      int mid = str[(left + right) / 2];

      /* partition */
      while (i <= j) {
            while (str[i] < mid)
                  i++;
            while (str[j] > mid)
                  j--;
            if (i <= j) {
                  std::swap(str[i], str[j]);
                  i++; j--;
            }
      };

      /* recursion */
      if (left < j)
            quickSort(str, left, j);
      if (i < right)
            quickSort(str, i, right);
    }

    // A recursive binary search function. It returns  
	// location of x in given array arr[l..r] is present,  
	// otherwise -1 
	int binarySearch(string &arr, int l, int r, int x) { 

	   if (r >= l) 
	   { 
	        int mid = l + (r - l)/2; 
	  
	        // If the element is present at the middle  
	        // itself 
	        if (arr[mid] == x)   
	            return mid;
	  
	        // If element is smaller than mid, then  
	        // it can only be present in left subarray 
	        if (arr[mid] > x)  
	            return binarySearch(arr, l, mid-1, x); 
	  
	        // Else the element can only be present 
	        // in right subarray 
	        return binarySearch(arr, mid+1, r, x); 
	   } 
	  
	   // We reach here when element is not  
	   // present in array 
	   return -1; 
	} 

	//O(N)
	 vector<char> optimal(string &str) {
	 	vector<char> v;
		vector<bool> char_set(128);
		for (int i=0; i<str.length(); i++) {
			int val = str[i];
			if (!char_set[val]) {
				v.push_back(val);
			}
			char_set[val] = true;
		}
		return v;
	}	 

	

};


int main() {
	string str("hello");
	vector<char> v;
	charUnique chUnq;
	v = chUnq.bruteForce(str);
	for (auto i = v.begin(); i != v.end(); ++i) {
    	cout << *i << ' ';
    }
    cout << "\n";

    chUnq.quickSort(str, 0, str.length()-1);
    for (int i = 0; i<str.length(); i++) {
    	if (chUnq.binarySearch(str, i+1, str.length()-1, str[i]) == -1) {
    		cout << str[i] << ' ';
    	}
    }
    cout << "\n";
    vector<char> op;
    op = chUnq.optimal(str);
    for (auto i = op.begin(); i != op.end(); ++i) {
    	cout << *i << ' ';
    }
    cout << "\n";
	return 0;
}
