#include <iostream>
#include "Sudoku.h"

Sudoku::Sudoku()
{
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			for(int n = 0; n < 9; n++)
				bitmap[n][i][j] = -1;
			map[i][j] = -1;
		}
	}
}
void Sudoku::giveQuestion()
{
	
}
void Sudoku::readIn()
{
	int n;
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			scanf("%d", &n);
			map[i][j] = n -1;
		}
	}
}
void Sudoku::solve()
{
	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 9; j++)
			if(map[i][j] != -1)
				setCell(map[i][j], i, j);
	Sudoku su = *this;
	switch(backtracking(*this))
	{
		case 0:
			printf("0\n");
			break;
		case 1:
			printf("1\n");
			print();
			break;
	}
}
void Sudoku::changeNum(int n1, int n2)
{
	
}
void Sudoku::changeRow(int r1, int r2)
{
	
}
void Sudoku::changeCol(int c1,int c2)
{
	
}
void Sudoku::rotate(int n)
{
	
}
void Sudoku::flip(int n)
{
	
}
void Sudoku::transform()
{
	
}

int Sudoku::setCell(int n, int row, int col)
{
	//self
	map[row][col] = n;
	if(bitmap[n][row][col] == -1) bitmap[n][row][col] = 1;
	else return 0;
	//column
	for(int i = 0; i < 9; i++)
		if(bitmap[n][i][col] == -1)
			bitmap[n][i][col] = 0;
	//row
	for(int j = 0; j < 9; j++)
		if(bitmap[n][row][j] == -1)
			bitmap[n][row][j] = 0;
	//box
	int boxRow = (row / 3);
	int boxCol = (col / 3);
	for(int i = boxRow * 3; i < boxRow * 3 + 3; i++)
		for(int j = boxCol * 3; j < boxCol * 3 + 3; j++)
			if(bitmap[n][i][j] == -1)
				bitmap[n][i][j] = 0;
	//cell
	for(int k = 0; k < 9; k++)
		if(bitmap[k][row][col] == -1) bitmap[k][row][col] = 0;
	return 1;
}

int Sudoku::single()
{
	for(;;) //infinite loop
	{
		int changed = 0;
		for(int n = 0; n < 9; n++)
		{
			for(int i = 0; i < 9; i++)
			{
				for(int j = 0; j < 9; j++)
				{
					//Conflict happens if all the blocks are 0
					if(getRowNum(0, n, i) == 9) return 0; //conflict
					if(getColNum(0, n, j) == 9) return 0; //conflict
					if(getBoxNum(0, n, i/3, j/3) == 9) return 0; //conflict
					if(bitmap[n][i][j] == -1)
					{
						if(getRowNum(-1, n, i) == 1)
						{
							setCell(n, i, j);
							++changed;
						}
						else if(getColNum(-1, n, j) == 1)
						{
							setCell(n, i, j);
							++changed;
						}
						else if(getBoxNum(-1, n, i/3, j/3) == 1)
						{
							setCell(n, i, j);
							++changed;
						}
					}
				}
			}
		}
		if(changed == 0) return 1; //if single test makes no change, leave
	}
}

int Sudoku::backtracking(Sudoku & thisSudoku, int nij)
{
	if(nij == 729) return 1; //if all cells are complete, leave
	int n = nij / 81, i = (nij % 81) / 9, j = nij % 9; //set n, i, j w.r.t nij
	int singleResult = 1; //Assume the sudoku passes single test if the cell has been set already
	if(bitmap[n][i][j] == -1) singleResult = single(); //if cell is unset, use single test first
	switch(singleResult)
	{
		case 0: //if single test conflicts
			return 0;
			break;
		case 1: //if single test makes no change or the cell has been set already
			if(bitmap[n][i][j] == -1) //if the cell is unset
			{
				Sudoku su = thisSudoku; //set temp sudoku
				su.setCell(n, i, j);  //give trial value
				switch(su.backtracking(su, ++nij)) //check the trial value
				{
					case 0: //if the trial value is wrong
						bitmap[n][i][j] = 0; //set the cell false
						return backtracking(thisSudoku, ++nij); //continue the following cell
						break;
					case 1: //if the trial value is right and all cells are complete
						thisSudoku = su; //give the trail result to the original one
						return 1;
						break;
				}
			}
			else return backtracking(thisSudoku, ++nij); //if the cell is set, continue the following cell
			break;
	}
}

int Sudoku::getRowNum(int N, int n, int row)
{
	int rowNum = 0;
	for(int j = 0; j < 9; j++) if(bitmap[n][row][j] == N) rowNum++;
	return rowNum;
}

int Sudoku::getColNum(int N, int n, int col)
{
	int colNum = 0;
	for(int i = 0; i < 9; i++) if(bitmap[n][i][col] == N) colNum++;
	return colNum;
}

int Sudoku::getBoxNum(int N, int n, int boxRow, int boxCol)
{
	int boxNum = 0;
	for(int i = boxRow * 3; i < boxRow * 3 + 3; i++)
		for(int j = boxCol * 3; j < boxCol * 3 + 3; j++)
			if(bitmap[n][i][j] == N) boxNum++;
	return boxNum;
}

void Sudoku::print()
{
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 8; j++)
			printf("%d ", map[i][j] + 1);
		printf("%d\n", map[i][8] + 1);
	}
}
void Sudoku::bitprint()
{
	for(int n = 0; n < 9; n++)
	{
		printf("n = %d\n", n);
		for(int i = 0; i < 9; i++)
		{
			for(int j = 0; j < 8; j++)
				printf("%d ", bitmap[n][i][j] + 1);
			printf("%d\n", bitmap[n][i][8] + 1);
		}
	}
}