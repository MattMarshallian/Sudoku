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
	possibleValues.erase(std::remove_if(possibleValues.begin(), possibleValues.end(), [val] (int i) { return i != val; }), possibleValues.end());
}

void Cell::removePossible(int val)
{
	possibleValues.erase(std::remove(possibleValues.begin(), possibleValues.end(), val), possibleValues.end());
}
