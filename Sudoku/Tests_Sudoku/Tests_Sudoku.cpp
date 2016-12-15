// Tests_Sudoku.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <gtest/gtest.h>

#include "..\Sudoku\myHeader.h"
#include "..\Sudoku\Cell.h"

int main(int ac, char* av[])
{
	testing::InitGoogleTest(&ac, av);
	return RUN_ALL_TESTS();
}


TEST(TestAddition, TestCanAddTwoNumbers)
{
	int a = 5;
	int b = 8;
	EXPECT_TRUE(my_add(a,b) == a + b);
}

TEST(TestAddition, TestCanAddTwoNumbers2)
{
	int a = -5;
	int b = -128;
	EXPECT_TRUE(my_add(a, b) == a + b);
}

TEST(TestSingleCell, TestCellExists)
{
	Cell cell;

}
