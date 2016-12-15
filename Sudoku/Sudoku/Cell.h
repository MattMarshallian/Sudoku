#pragma once

/*	Ka¿da komórka zawiera wektor dziewiêcioelementowy wektor intów
	oraz bie¿¹c¹ wartoœæ.

	Je¿eli wartoœæ jest 0, to jest nieustalona
	
	Je¿eli jest ró¿na od 0, to jest ustalona
	i nie mo¿e wyst¹piæ
	ani w wierszu, ani w kolumnie ani w kwadracie
*/

#include <vector>

class Cell
{
public:
	Cell();
	~Cell();

	std::vector<int> possibleValues = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int getValue() { return value; };
	void setValue(int val);
	void removePossible(int val);


private:
	int value = 0;

};
