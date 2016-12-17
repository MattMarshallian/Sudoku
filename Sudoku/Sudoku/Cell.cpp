#include "stdafx.h"
#include <algorithm>

#include "Cell.h"


Cell::Cell()
{
}


Cell::~Cell()
{
}


void Cell::setValue(int val)
{
	value = val;
	possibles.erase(std::remove_if(possibles.begin(), possibles.end(), [val] (int i) { return i != val; }), possibles.end());
}


void Cell::removePossible(int val)
{
	possibles.erase(std::remove(possibles.begin(), possibles.end(), val), possibles.end());
	if (possibles.size() == 1) value = possibles.front();
}


bool Cell::isValid()
{
	return value > 0 || !possibles.empty();
}

