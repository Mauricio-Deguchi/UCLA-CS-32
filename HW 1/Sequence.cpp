#include "Sequence.h"

Sequence::Sequence()
// Create an empty sequence (i.e., one whose size() is 0).
{
	m_size = 0;
}




bool Sequence::empty() const
// Return true if the sequence is empty, otherwise false.
{
	if (m_size == 0)
	{
		return true;
	}
	return false;
}




int Sequence::size() const
// Return the number of items in the sequence.
{
	return(m_size);
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
	if ((0 <= pos) && (pos <= m_size) && (m_size != DEFAULT_MAX_ITEMS))
	{
		for (int i = m_size; pos <= i; i--)
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
		m_size++;
		return(pos);
	}
	else if (m_size == DEFAULT_MAX_ITEMS)
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
	for (p = 0; p < m_size; p++)
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
	if ((0 <= pos) && (pos < m_size))
	{
		for (int count = pos; count < m_size; count++)
		{
			if (count != m_size - 1)
			{
				arrayObj[count] = arrayObj[count + 1];
			}
			else
			{
				m_size--;
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
	for (int i = 0; i < m_size; i++)
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
	if ((0 <= pos) && (pos < m_size))
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
	if ((0 <= pos) && (pos < m_size))
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
	for (int p = 0; p < m_size; p++)
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
	int smaller, larger;
	if (other.m_size < m_size)
	{
		smaller = other.m_size;
		larger = m_size;
		for (int i = 0; i < smaller; i++)
		{
			ItemType stored = arrayObj[i];
			arrayObj[i] = other.arrayObj[i];
			other.arrayObj[i] = stored;
		}
		for (int j = smaller; j < larger; j++)
		{
			other.arrayObj[j] = arrayObj[j];
		}
	}
	else
	{
		smaller = m_size;
		larger = other.m_size;
		for (int i = 0; i < smaller; i++)
		{
			ItemType stored = arrayObj[i];
			arrayObj[i] = other.arrayObj[i];
			other.arrayObj[i] = stored;
		}
		for (int j = smaller; j < larger; j++)
		{
			arrayObj[j] = other.arrayObj[j];
		}
	}


	int temp = other.m_size;
	other.m_size = m_size;
	m_size = temp;
}


