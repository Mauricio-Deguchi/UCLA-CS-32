#include "History.h"



History::History(int nRows, int nCols)
{
	m_cols = nCols;						// establishes the number of rows
	m_rows = nRows;						// establishes the number of columns
	for (int rows = 0; rows < m_rows; rows++) {						// extracts data for the history object
		for (int columns = 0; columns < m_cols; columns++) {
			hist_array[rows][columns] = '.';
		}
	}
}

bool History::record(int r, int c)
{
	// if we're outside of the object, we will return false
	if ((r > m_rows) || (c > m_cols) || (r < 1) || (c < 1))
	{
		return false;
	}
	// otherwise, we will need to loop through and record the information for the array
	switch (hist_array[r-1][c-1])
	{
	case '.': hist_array[r-1][c-1] = 'A'; break;
	case 'Z': hist_array[r - 1][c - 1] = 'Z'; break;
	default:  hist_array[r - 1][c - 1] += 1; break;
	}
	return true;
}

void History::display() const
{		// to display the history object, we will first need to clear the screen
	clearScreen();								
	for (int rows = 0; rows < m_rows; rows++)			// then, we will print row by row and column by column of the data we've accumulated
	{
		for (int columns = 0; columns < m_cols; columns++)
		{
			cout << hist_array[rows][columns];
		}
		cout << endl;
	}
	cout << endl;
}