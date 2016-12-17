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

	int getValue() { return value; };
	void setValue(int val);
	void removePossible(int val);
	bool isValid();
    std::vector<int>& getPossibles() { return possibles; };

    struct
    {
        int index = 0;
        int row = 0;
        int col = 0;
        int square = 0;
    } location;

private:
	int value = 0;
    std::vector<int> possibles = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
};
