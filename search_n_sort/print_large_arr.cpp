/*Find duplicates: You have an array with all the numnbers from 1 to N, where N is at most 
32,000. The array may have duplicate entries and you do not know what N is.
With only 4 kB of memory available, how would you print all duplicates in the array?

Soln - Create a bit vector with 32000 bits, where each bit represents one integer.
Using a BV, ietarte through the array flagginf each element v by setting bit v to 1.
*/

#include <iostream>

using namespace std;

class BitSet {
public:

	int size = 32000;
	int bitset[];
	//bitset = new int[(size >> 5) + 1]; //divide by 32

	bool get(int pos) {
		int wordNum = (pos >> 5); //divide by 32
		int bitNum = (pos & 0x1F); //mod 32
		return (bitset[wordNum] & (1 << bitNum)) != 0;
	}

	void set(int pos) {
		int wordNum = (pos >> 5); //divide by 32
		int bitNum = (pos & 0x1F); //mod 32
		bitset[wordNum] |= 1 << bitNum;
	}

	void checkDuplicates(int array[]) {
		int N = sizeof(array);
		cout << N << "\n";
		for (int i=0; i < N; i++) {
			int num = array[i];
			int num0 = num - 1; //bitset starts at 0, numbers start at 1
			if (get(num0)) {
				cout << num << "\n";
			}
			else {
				set(num0);
			}
		}
	}
};

int main() {
	int arr[] = {0,1,2,3,3,5,6,9,10};
	BitSet bs;
	bs.checkDuplicates(arr);
	return 0;
}