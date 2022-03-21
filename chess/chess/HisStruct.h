/** @file  */

/*
Computer Programming
Chess
*/

#ifndef HISSTRUCT_H
#define HISSTRUCT_H
#include "Pieces.h"

/**Struct that contains what pieces was moved, where, and what piece it has captured*/
struct HisStruct
{
	/**moved piece*/
	Pieces* md;

	/**x parameter*/
	int x;

	/**y parameter*/
	int y;

	/**what it has captured*/
	Pieces* killed;
};

#endif
