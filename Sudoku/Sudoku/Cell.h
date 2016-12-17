#pragma once

/*	Ka�da kom�rka zawiera wektor dziewi�cioelementowy wektor int�w
	oraz bie��c� warto��.

	Je�eli warto�� jest 0, to jest nieustalona
	
	Je�eli jest r�na od 0, to jest ustalona
	i nie mo�e wyst�pi�
	ani w wierszu, ani w kolumnie ani w kwadracie
*/

#include <vector>

class Cell
{
public:
	Cell();
	~Cell();

	std::vector<int> possibles = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int getValue() { return value; };
	void setValue(int val);
	void removePossible(int val);


private:
	int value = 0;

};
