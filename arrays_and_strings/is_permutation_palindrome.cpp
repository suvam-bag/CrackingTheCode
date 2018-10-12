/*Palindrome permutation: Given a string, write a function to check if it is a permutation of a palindrome
Input : Tact Coa
Output: True (permutations: "taco cat", "atco cta", etc)
Complexity - O(N/2 * N!) */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class PalindromePermuation {
public:
	void swap(char *x, char *y) 
	{ 
	    char temp; 
	    temp = *x; 
	    *x = *y; 
	    *y = temp; 
	} 

	void permute(char *a, int l, int r) {
	   int i; 
	   int N = strlen(a);
	   if (l == r) {
	   	  if (palindrome(a)) {
	   	  	printArray(a);
	   	  	cout << "\n";
	   	  }
	   }
	     
	   else
	   { 
	       for (i = l; i <= r; i++) 
	       { 
	          swap((a+l), (a+i)); 
	          permute(a, l+1, r); 
	          swap((a+l), (a+i)); //backtrack 
	       }  
	   } 
	}

	bool palindrome(char *str) {
		int i=0;
		//int j = str.length()-1;
		int N = strlen(str);
		int j = N-1;
		if (N > 0) {
			while (i < j) {
				if (str[i] != str[j])
		        {
		            return false;
		        }
		        i++;
		        j--;
			}
			//for (int i=0; i<N; i++){
			//	cout << str[i] << ' ';
			//}
			return true;
		}
	}

	void printArray(char *str) {
	 	int N = strlen(str);
	 	for (int i=0; i<N; i++) {
	 		cout << str[i] << ' ';
	 	}
	}
};

int main() {
	char str[] = "tactcoa";
	//char str[] = "ABC";
	int N = strlen(str);
	PalindromePermuation plndrm;
	plndrm.permute(str, 0, N-1);
	return 0;
}