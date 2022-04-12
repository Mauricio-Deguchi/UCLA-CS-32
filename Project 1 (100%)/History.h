#ifndef History_h
#define History_h
#include "globals.h"

class History
{
public:
	History(int nRows, int nCols);		// class constructor
	bool record(int r, int c);			// record method
	void display() const;				// display method

private:
	int m_rows = 0;						// number of rows for the History object
	int m_cols = 0;						// number of columns for the history object
	char hist_array[MAXROWS][MAXCOLS];			// history object information
};

#endif