
#include "stdafx.h"

#include <gtest\gtest.h>
#include <gmock\gmock.h>

#include "..\Sudoku\Cell.h"

TEST(Cell, CellInitialValue)
{
	Cell cell;
	EXPECT_EQ(0, cell.getValue());
}


TEST(Cell, CellSetValue)
{
	Cell cell;
	cell.setValue(4);
	EXPECT_EQ(4, cell.getValue());
}


TEST(Cell, CellInitialVector)
{
	Cell cell;
	std::vector<int> test = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	EXPECT_THAT(test, ::testing::ContainerEq(cell.possibles));
}


TEST(Cell, IfValueIsSetThenClearPossiblesToTheSameValue)
{
	Cell cell;
	cell.setValue(5);

	std::vector<int> test = { 5 };
	EXPECT_THAT(test, ::testing::ContainerEq(cell.possibles));
}


TEST(Cell, RemoveSomeValuesFromPossibles)
{
	Cell cell;
	cell.removePossible(3);
	cell.removePossible(8);
	cell.removePossible(4);
	cell.removePossible(6);

	std::vector<int> test = { 1, 2, 5, 7, 9 };
	EXPECT_THAT(test, ::testing::ContainerEq(cell.possibles));
}


TEST(Cell, CellIsValid)
{
	Cell cell1;
	EXPECT_TRUE(cell1.isValid());

	Cell cell2;
	cell2.setValue(3);
	EXPECT_TRUE(cell2.isValid());

	Cell cell3;
	for (int i = 1; i <= 9; ++i) cell3.removePossible(i);
	EXPECT_TRUE(cell3.isValid()); 	// See test AfterRemoveOneBeforeLastSetValue
}

TEST(Cell, AfterRemoveOneBeforeLastSetValue)
{
	Cell cell;
	std::vector<int> valsToRemove = { 5, 7, 1, 3, 4, 2, 9, 8 };
	for (auto v : valsToRemove) cell.removePossible(v);
	EXPECT_EQ(6, cell.getValue());
}