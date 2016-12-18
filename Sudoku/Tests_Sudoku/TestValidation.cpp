
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


TEST(SudokuValidationRules, RealSudokuFromInternet)
{
    /*
    Very easy sudoku example

    . . 8   . . .   7 . .
    . . .   . . .   . . .
    . . .   8 . 6   3 . .

    1 . .   . . 7   9 . 5
    . . 7   . 1 .   . 6 .
    9 8 .   3 . 5   1 . .

    . . 4   . 3 .   . . 8
    . . 6   9 . 1   . . 4
    7 . 1   . . .   . . .
    */

    SudokuTable sudoku;

    sudoku.allpCells[2]->setValue(8);
    sudoku.allpCells[6]->setValue(7);

    sudoku.allpCells[21]->setValue(8);
    sudoku.allpCells[23]->setValue(6);
    sudoku.allpCells[24]->setValue(3);

    sudoku.allpCells[27]->setValue(1);
    sudoku.allpCells[32]->setValue(7);
    sudoku.allpCells[33]->setValue(9);
    sudoku.allpCells[35]->setValue(5);

    sudoku.allpCells[38]->setValue(7);
    sudoku.allpCells[40]->setValue(1);
    sudoku.allpCells[43]->setValue(6);

    sudoku.allpCells[45]->setValue(9);
    sudoku.allpCells[46]->setValue(8);
    sudoku.allpCells[48]->setValue(3);
    sudoku.allpCells[50]->setValue(5);
    sudoku.allpCells[51]->setValue(1);

    sudoku.allpCells[56]->setValue(4);
    sudoku.allpCells[58]->setValue(3);
    sudoku.allpCells[62]->setValue(8);

    sudoku.allpCells[65]->setValue(6);
    sudoku.allpCells[66]->setValue(9);
    sudoku.allpCells[68]->setValue(1);
    sudoku.allpCells[71]->setValue(4);

    sudoku.allpCells[72]->setValue(7);
    sudoku.allpCells[74]->setValue(1);

    EXPECT_TRUE(sudoku.isValid());
}
