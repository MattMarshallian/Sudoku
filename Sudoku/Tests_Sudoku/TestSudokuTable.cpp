
#include "stdafx.h"

#include <gtest\gtest.h>
#include <gmock\gmock.h>

#include "..\Sudoku\SudokuTable.h"

TEST(SudokuTable, InitialValue)
{
    SudokuTable sudoku;
    EXPECT_EQ(0, 0);
}