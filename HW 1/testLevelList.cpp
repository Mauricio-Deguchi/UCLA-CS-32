#include <iostream>
#include <cassert>
#include "LevelList.h"


int main()
{
	LevelList l;
	assert(l.add(15) == false);
	assert(l.add(30) == true);
	assert(l.add(400) == true);
	assert(l.add(401) == false);
	assert(l.add(77) == true);
	assert(l.add(78) == true);
	assert(l.add(77) == true);
	assert(l.remove(77) == true);
	assert(l.size() == 4);
	assert(l.maximum() == 400);
	assert(l.minimum() == 30);
	assert(l.remove(400) == true);
	assert(l.maximum() == 78);
	LevelList h = l;
	LevelList n;
	assert(h.size() == 3);
	assert(h.maximum() == 78);
	assert(h.minimum() == 30);
	assert(h.remove(400) == false);
	assert(h.remove(78) == true);
	assert(h.size() == 2);
	assert(l.size() == 3);

	n = l;
	assert(n.size() == 3);
	assert(n.maximum() == 78);
	assert(n.minimum() == 30);
	assert(n.remove(400) == false);
	assert(n.remove(78) == true);
	assert(n.size() == 2);
	assert(l.size() == 3);
	assert(n.remove(77) == true);
	assert(n.remove(30) == true);
	assert(n.size() == 0);
	for (int i = 0; i < DEFAULT_MAX_ITEMS; i++)
		assert(n.add(100) == true);
	assert(n.size() == 180);
	assert(n.add(100) == false);
	assert(n.remove(100) == true);
	assert(n.size() == 179);
	std::cout << "All LevelList Tests Passed!" << std::endl;

}


