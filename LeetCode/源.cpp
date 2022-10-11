#include <iostream>
using namespace std;


int main()
{
	unsigned int value = 1024;
	bool* condition1 = (bool*)&value;
	bool condition2 = *((bool*)(&value));
	cout << *condition1 << ' ' << condition2;
}