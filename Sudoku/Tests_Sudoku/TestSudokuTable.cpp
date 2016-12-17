
#include "stdafx.h"

#include <gtest\gtest.h>
#include <gmock\gmock.h>

#include "..\Sudoku\SudokuTable.h"


TEST(SudokuTable, SudokuTableHas81Elements)
{
    SudokuTable sudoku;
    EXPECT_EQ(NUMBERS_IN_SUDOKU, sudoku.allpCells.size());
}


TEST(SudokuTable, LocationOfFirstIndex)
{
    SudokuTable sudoku;
    EXPECT_EQ(0, sudoku.allpCells[0]->location.index);
    EXPECT_EQ(0, sudoku.allpCells[0]->location.row);
    EXPECT_EQ(0, sudoku.allpCells[0]->location.col);
    EXPECT_EQ(0, sudoku.allpCells[0]->location.square);
}


TEST(SudokuTable, LocationOfLastIndex)
{
    SudokuTable sudoku;
    EXPECT_EQ(80, sudoku.allpCells[NUMBERS_IN_SUDOKU - 1]->location.index);
    EXPECT_EQ(8, sudoku.allpCells[NUMBERS_IN_SUDOKU - 1]->location.row);
    EXPECT_EQ(8, sudoku.allpCells[NUMBERS_IN_SUDOKU - 1]->location.col);
    EXPECT_EQ(8, sudoku.allpCells[NUMBERS_IN_SUDOKU - 1]->location.square);
}

TEST(SudokuTable, LocationOfSomethingInTheMiddle)
{
    int somewhere = 42;
    SudokuTable sudoku;
    EXPECT_EQ(somewhere, sudoku.allpCells[somewhere]->location.index);
    EXPECT_EQ(4, sudoku.allpCells[somewhere]->location.row);
    EXPECT_EQ(6, sudoku.allpCells[somewhere]->location.col);
    EXPECT_EQ(5, sudoku.allpCells[somewhere]->location.square);
}
