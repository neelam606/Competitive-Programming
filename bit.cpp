
#include <bits/stdc++.h>
using namespace std;

bool getBit(int num, int i)
{
	return ((num & (1 << i)) != 0);
}

int setBit(int num, int i)
{
	return num | (1 << i);
}

int clearBit(int num, int i)
{

	int mask = ~(1 << i);

	// Return the update value
	return num & mask;
}

int main()
{
	int N = 70;

	cout << "The bit at the 3rd position from LSB is: "
		<< (getBit(N, 3) ? '1' : '0')
		<< endl;

	cout << "The value of the given number "
		<< "after setting the bit at "
		<< "LSB is: "
		<< setBit(N, 0) << endl;

	cout << "The value of the given number "
		<< "after clearing the bit at "
		<< "LSB is: "
		<< clearBit(N, 0) << endl;

	return 0;
}
