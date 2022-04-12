#include <iostream>
#include <cassert>
#include "Sequence.h"



int main()
{
	Sequence a, b, c;
	unsigned long num1 = 1, num2 = 2, num3 = 3, numA;
	assert(a.empty() == true);
	assert(a.size() == 0);
	assert(a.insert(0, num1) == 0);
	assert(a.insert(num2) == 1);
	assert(a.insert(num1) == 0);
	assert(a.insert(1, num3) == 1);
	assert(a.size() == 4);
	assert(a.insert(4, num1)==4);
	for (int i = 0; i < DEFAULT_MAX_ITEMS; i++)
		assert(b.insert(i, num1) == i);
	assert(b.insert(num1) == -1);
	assert(b.insert(5, num1) == -1);
	assert(b.insert(-1, num1) == -1);
	assert(a.erase(0) == true);
	assert(a.erase(3) == true);
	assert(a.erase(3) == false);
	assert(a.insert(num1) == 0);
	assert(a.remove(num1) == 2);
	assert(a.remove(num2) == 1);
	for (int j = 1; j <= 4; j++)
		a.insert(num3);
	c = a;
	assert(a.remove(num3) == 5);
	assert(b.remove(num1) == 180);
	for (int k = 0; k < 5; k++)
		assert(c.set(k, k + 1) == true);
	for (int k = 0; k < 5; k++)
	{
		assert(c.get(k, numA) == true);
		assert(numA == k + 1);
	}
	for (int i = 0; i < 5; i++)
		assert(c.find(i + 1) == i);
	assert(c.find(6) == -1);
	assert(c.insert(3, 5) == 3);
	assert(c.find(5) == 3);
	Sequence d(c);
	a.swap(c);
	std::cout << "All Sequence Tests Passed!" << std::endl;

}


