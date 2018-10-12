/*Shallow vs Deep Copy
Shallow copy copies all the member values from one object to another. - risky, create and delete objects
A deep copy does all this and also deep copies any pointer objects
*/
#include <iostream>

struct Test {
	char *ptr;
};

void shallow_copy(Test &src, Test &dst) {
	dst.ptr = src.ptr;
}

void deep_copy(Test &src, Test &dst) {
	dst.ptr	= (char*)malloc(strlen(src.ptr)+1);
	strcopy(dest.ptr, src.ptr);
}

