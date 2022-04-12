#include <iostream>
#include <cassert>
#include "newSequence.h"
#include <cassert>


int main()
{
    Sequence a(1000);   // a can hold at most 1000 items
    Sequence b(5);      // b can hold at most 5 items
    Sequence c;         // c can hold at most DEFAULT_MAX_ITEMS items
    unsigned long v = 29, x = 15, y = 39;
    for (int k = 0; k < 5; k++)
        assert(b.insert(v) != -1);
    // Failure if we try to insert a sixth item into b
    assert(b.insert(v) == -1);
    assert(c.size() == 0);
    assert(b.size() == 5);
    assert(b.empty() == false);
    assert(c.empty() == true);
    assert(a.empty() == true);
    assert(c.insert(v) == 0);
    assert(c.insert(0, x) == 0);
    assert(c.erase(1) == true);
    assert(c.erase(1) == false);


    // When two Sequences' contents are swapped, their capacities are
    // swapped as well:
    a.swap(b);
    assert(a.insert(v) == -1 && b.insert(v) != -1);
    Sequence d(a);
    d.erase(3);
    d = a;
    d.erase(3);
    assert(d.insert(x) == 0);
    assert(d.remove(v) == 4);
    assert(d.size() == 1);
    assert(d.empty() == false);
    assert(d.get(1, v) == false);
    assert(d.get(0, v) == true);
    std::cout << "I am v now: " << v << std::endl;
    assert(a.get(0, v) == true);
    std::cout << "I back to v now: " << v << std::endl;
    assert(a.set(3, y) == true);
    assert(a.set(5, y) == false);
    assert(a.find(v) == 0);
    assert(a.find(y) == 3);
    Sequence e(a);
    assert(e.remove(39) == true);
    std::cout << "All tests passed!" << std::endl;
}


