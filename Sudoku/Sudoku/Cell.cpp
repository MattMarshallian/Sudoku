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
	std::vector<int> currentValues = possibleValues;
	for (auto value : currentValues)
		if (value != val)
			removePossible(value);
}

void Cell::removePossible(int val)
{
	possibleValues.erase(std::remove(possibleValues.begin(), possibleValues.end(), val), possibleValues.end());
}
