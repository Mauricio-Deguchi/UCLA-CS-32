#include "Sequence.h"
#include <limits>
#include "LevelList.h"


LevelList::LevelList()
// Create an empty level list.
{
	Sequence s();
}






bool LevelList::add(unsigned long level)
// If the level is valid (a value from 30 to 400) and the level list
// has room for it, add it to the level list and return true.
// Otherwise, leave the level list unchanged and return false.
{
	if ((30 <= level) && (level <= 400) && (s.size() < DEFAULT_MAX_ITEMS))
	{
		s.insert(level);
		return true;
	}
	return false;
}





bool LevelList::remove(unsigned long level)
// Remove one instance of the specified level from the level list.
// Return true if a level was removed; otherwise false.
{
	int pos = s.find(level);
	bool flag = s.erase(pos);
	return flag;
}






int LevelList::size() const  
// Return the number of levels in the list.
{
	return(s.size());
}






unsigned long LevelList::minimum() const
// Return the lowest-valued level in the level list.  If the list is
// empty, return NO_LEVEL.
{
	if (s.empty())
	{
		return (NO_LEVEL);
	}
	unsigned long temp;
	s.get(0, temp);
	return(temp);
}





unsigned long LevelList::maximum() const
// Return the highest-valued level in the level list.  If the list is
// empty, return NO_LEVEL.
{
	if (s.empty())
	{
		return (NO_LEVEL);
	}
	unsigned long temp;
	s.get(s.size() - 1, temp);
	return(temp);
}




