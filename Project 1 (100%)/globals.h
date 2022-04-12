#ifndef globals_h
#define globals_h
#include <iostream>
using namespace std;


const int MAXROWS = 20;             // max number of rows in the mesa
const int MAXCOLS = 25;             // max number of columns in the mesa
const int MAXGARKS = 150;           // max number of garks allowed
const int INITIAL_GARK_HEALTH = 2;

const int UP = 0;
const int DOWN = 1;
const int LEFT = 2;
const int RIGHT = 3;
const int NUMDIRS = 4;


// Return a uniformly distributed random int from min to max, inclusive
int randInt(int min, int max);
void clearScreen();



#endif