#include "newSequence.h"
#include <iostream>

Sequence::Sequence()
// Create an empty sequence (i.e., one whose size() is 0).
{
	arrayObj = new ItemType[DEFAULT_MAX_ITEMS];
	m_size = DEFAULT_MAX_ITEMS;
	m_occupied = 0;
}

Sequence::Sequence(int x)
// creates a sequence that can hold at most 'x' items
{
	if (x >= 0)
	{
		m_size = x;
		arrayObj = new ItemType[x];
		m_occupied = 0;
	}
	else
	{
		exit(1);
	}
}


Sequence::Sequence(const Sequence& other)
// copy constructor
{
	m_occupied = other.m_occupied;
	m_size = other.m_size;
	arrayObj = new ItemType[m_size];
	for (int i = 0; i < m_occupied; i++)
	{
		arrayObj[i] = other.arrayObj[i];
	}
}



Sequence& Sequence::operator=(const Sequence& rhs)
// assignment operator
{
	if (this != &rhs)
	{
		Sequence temp(rhs);
		swap(temp);
	}
	return(*this);
}




Sequence::~Sequence()
// destructor of sequence types
{
	delete[] arrayObj;
}


bool Sequence::empty() const
// Return true if the sequence is empty, otherwise false.
{
	if (m_occupied == 0)
	{
		return true;
	}
	return false;
}




int Sequence::size() const
// Return the number of items in the sequence.
{
	return(m_occupied);
}




int Sequence::insert(int pos, const ItemType& value)
// Insert value into the sequence so that it becomes the item at
// position pos.  The original item at position pos and those that
// follow it end up at positions one greater than they were at before.
// Return pos if 0 <= pos <= size() and the value could be
// inserted.  (It might not be, if the sequence has a fixed capacity,
// e.g., because it's implemented using a fixed-size array.)  Otherwise,
// leave the sequence unchanged and return -1.  Notice that
// if pos is equal to size(), the value is inserted at the end.
{
	if ((0 <= pos) && (pos <= m_size) && (m_size > m_occupied))
	{
		for (int i = m_occupied; pos <= i; i--)
		{
			if (i != pos)
			{
				arrayObj[i] = arrayObj[i - 1];
			}
			else
			{
				arrayObj[pos] = value;
			}
		}
		m_occupied++;
		return(pos);
	}
	else if (m_size == m_occupied)
	{
		return -1;
	}
	return(-1);
}





int Sequence::insert(const ItemType& value)
// Let p be the smallest integer such that value <= the item at
// position p in the sequence; if no such item exists (i.e.,
// value > all items in the sequence), let p be size().  Insert
// value into the sequence so that it becomes the item in position
// p.  The original item at position p and those that follow it end
// up at positions one greater than before.  Return p if the value
// was actually inserted.  Return -1 if the value was not inserted
// (perhaps because the sequence has a fixed capacity and is full).
{

	int p = 0;
	for (; p < m_occupied; p++)
	{
		ItemType temp;
		temp = arrayObj[p];
		if (value <= temp)
		{
			break;
		}
	}
	int result = insert(p, value);
	return (result);
}





bool Sequence::erase(int pos)
// If 0 <= pos < size(), remove the item at position pos from
// the sequence (so that all items that followed that item end up at
// positions one lower than they were at before), and return true.
// Otherwise, leave the sequence unchanged and return false.
{
	if ((0 <= pos) && (pos < m_occupied))
	{
		for (int count = pos; count < m_size; count++)
		{
			if (count != m_size - 1)
			{
				arrayObj[count] = arrayObj[count + 1];
			}
			else
			{
				m_occupied--;
			}
		}
		return true;
	}
	return false;
}




int Sequence::remove(const ItemType& value)
// Erase all items from the sequence that == value.  Return the
// number of items removed (which will be 0 if no item == value).
{
	int counter = 0;
	for (int i = 0; i < m_occupied; i++)
	{
		if (arrayObj[i] == value)
		{
			erase(i);
			counter++;
			i--;
		}
	}
	return (counter);
}




bool Sequence::get(int pos, ItemType& value) const
// If 0 <= pos < size(), copy into value the item at position pos
// of the sequence and return true.  Otherwise, leave value unchanged
// and return false.
{
	if ((0 <= pos) && (pos < m_occupied))
	{
		value = arrayObj[pos];
		return true;
	}
	return false;
}





bool Sequence::set(int pos, const ItemType& value)
// If 0 <= pos < size(), replace the item at position pos in the
// sequence with value and return true.  Otherwise, leave the sequence
// unchanged and return false.
{
	if ((0 <= pos) && (pos < m_occupied))
	{
		arrayObj[pos] = value;
		return true;
	}
	return false;
}







int Sequence::find(const ItemType& value) const
// Let p be the smallest integer such that value == the item at
// position p in the sequence; if no such item exists, let p be -1.
// Return p.
{
	for (int p = 0; p < m_occupied; p++)
	{
		if (value == arrayObj[p])
		{
			return p;
		}
	}
	return (-1);
}






void Sequence::swap(Sequence& other)
// Exchange the contents of this sequence with the other one.
{
	int temp = other.m_size;
	other.m_size = m_size;
	m_size = temp;
	int temp2 = other.m_occupied;
	other.m_occupied = m_occupied;
	m_occupied = temp2;					// lines above here complete the reassignment of the occupied and size variables
	ItemType* tempPtr = other.arrayObj;
	other.arrayObj = arrayObj;
	arrayObj = tempPtr;					// lines here complete the reassignment of the pointer variables
}



