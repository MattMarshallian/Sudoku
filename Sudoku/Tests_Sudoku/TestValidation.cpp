
#include "stdafx.h"

#include <gtest\gtest.h>

#include "..\Sudoku\SudokuTable.h"


TEST(SudokuValidationRules, EmptySudokuIsValid)
{
    SudokuTable sudoku;
    EXPECT_TRUE(sudoku.isValid());
}


TEST(SudokuValidationRules, SudokuIsInvalidIfTheSameValuesInRow)
{
    SudokuTable sudoku;
    sudoku.allpCells[47]->setValue(6);
    sudoku.allpCells[53]->setValue(6);
    EXPECT_FALSE(sudoku.isValid());
}


TEST(SudokuValidationRules, SudokuIsInvalidIfTheSameValuesInColumn)
{
    SudokuTable sudoku;
    sudoku.allpCells[14]->setValue(5);
    sudoku.allpCells[68]->setValue(5);
    EXPECT_FALSE(sudoku.isValid());
}


TEST(SudokuValidationRules, SudokuIsInvalidIfTheSameValuesInSquare)
{
    SudokuTable sudoku;
    sudoku.allpCells[42]->setValue(4);
    sudoku.allpCells[53]->setValue(4);
    EXPECT_FALSE(sudoku.isValid());
}

TEST(SudokuValidationRules, SudokuIsValidIfTheSameValuesInDifferRow)
{
    SudokuTable sudoku;
    sudoku.allpCells[2]->setValue(9);
    sudoku.allpCells[78]->setValue(9);
    EXPECT_TRUE(sudoku.isValid());
}


TEST(SudokuValidationRules, SudokuIsValidIfTheSameValuesInDifferColumn)
{
    SudokuTable sudoku;
    sudoku.allpCells[36]->setValue(5);
    sudoku.allpCells[62]->setValue(5);
    EXPECT_TRUE(sudoku.isValid());
}


TEST(SudokuValidationRules, SudokuIsValidIfTheSameValuesInDifferSquare)
{
    SudokuTable sudoku;
    sudoku.allpCells[52]->setValue(1);
    sudoku.allpCells[62]->setValue(1);
    EXPECT_TRUE(sudoku.isValid());
}
