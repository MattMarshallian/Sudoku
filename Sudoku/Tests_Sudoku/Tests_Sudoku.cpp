// Tests_Sudoku.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <gtest\gtest.h>
#include <gmock\gmock.h>

#include "..\Sudoku\Cell.h"

int main(int ac, char* av[])
{
	testing::InitGoogleTest(&ac, av);
	return RUN_ALL_TESTS();
}


TEST(TestSingleCell, TestCellInitialValue)
{
	Cell cell;
	EXPECT_EQ(0, cell.getValue());
}


TEST(TestSingleCell, TestCellSetValue)
{
	Cell cell;
	cell.setValue(4);
	EXPECT_EQ(4, cell.getValue());
}


TEST(TestSingleCell, TestCellInitialVector)
{
	Cell cell;
	std::vector<int> test = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }; 
	EXPECT_THAT(test, ::testing::ContainerEq(cell.possibles));
}


TEST(TestSingleCell, IfValueIsSetThenClearPossiblesToTheSameValue)
{
	Cell cell;
	cell.setValue(5);

	std::vector<int> test = { 5 };
	EXPECT_THAT(test, ::testing::ContainerEq(cell.possibles));
}

TEST(TestSingleCell, RemoveSomeValuesFromPossibles)
{
	Cell cell;
	cell.removePossible(3);
	cell.removePossible(8);
	cell.removePossible(4);
	cell.removePossible(6);

	std::vector<int> test = { 1, 2, 5, 7, 9 };
	EXPECT_THAT(test, ::testing::ContainerEq(cell.possibles));
}