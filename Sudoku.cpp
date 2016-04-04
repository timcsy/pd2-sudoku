#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "Sudoku.h"
#include "Clock.h"

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
	for(int i = 0; i < 729; i++) visited[i] = 0;
}

void Sudoku::giveQuestion()
{
	int question[14][9][9]=
	{
		{8,0,0,0,0,0,0,0,0,0,0,3,6,0,0,0,0,0,0,7,0,0,9,0,2,0,0,0,5,0,0,0,7,0,0,0,0,0,0,0,4,5,7,0,0,0,0,0,1,0,0,0,3,0,0,0,1,0,0,0,0,6,8,0,0,8,5,0,0,0,1,0,0,9,0,0,0,0,4,0,0},
		{0,0,0,0,0,0,0,1,2,0,0,0,0,0,0,0,0,3,0,0,2,3,0,0,4,0,0,0,0,1,8,0,0,0,0,5,0,6,0,0,7,0,8,0,0,0,0,0,0,0,9,0,0,0,0,0,8,5,0,0,0,0,0,9,0,0,0,4,0,5,0,0,4,7,0,0,0,6,0,0,0},
		{6,0,2,0,5,0,0,0,0,0,0,0,0,0,3,0,4,0,0,0,0,0,0,0,0,0,0,4,3,0,0,0,8,0,0,0,0,1,0,0,0,0,2,0,0,0,0,0,0,0,0,7,0,0,5,0,0,2,7,0,0,0,0,0,0,0,0,0,0,0,8,1,0,0,0,6,0,0,0,0,0},
		{0,6,9,0,0,0,0,0,0,0,0,0,0,4,0,0,3,0,0,8,0,0,0,0,0,0,0,0,0,0,8,0,0,6,1,0,4,0,0,0,0,0,9,0,0,5,0,0,0,2,0,0,0,0,2,0,0,9,0,0,0,0,5,0,0,0,6,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
		{6,0,0,3,5,0,0,0,0,2,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,1,5,0,0,4,0,0,3,0,0,0,0,0,2,0,1,0,7,0,0,0,0,0,0,0,0,0,0,0,1,7,0,0,0,0,0,0,0,0,0,0,9,0,5,0,0,0,8,0,0,0,0,0,0,0},
		{7,0,0,1,0,0,0,0,0,0,0,0,7,0,0,3,0,0,0,0,0,0,0,8,4,0,0,2,0,0,0,0,0,0,5,0,0,0,0,0,3,0,6,0,0,1,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,1,0,0,3,0,0,4,0,0,0,0,0,0,0,5,0,0,0,7,0},
		{7,2,0,6,1,0,0,0,0,0,0,0,0,0,2,0,0,5,0,0,0,0,0,0,0,9,0,0,1,5,0,0,0,2,0,0,0,0,0,9,3,0,0,0,0,0,0,0,0,0,0,0,4,0,3,0,0,8,0,0,0,0,0,0,0,0,0,0,0,1,0,0,9,0,0,0,0,0,0,0,0},
		{0,0,0,0,6,0,0,0,8,0,4,0,3,0,0,0,0,0,0,1,0,0,0,0,5,0,0,0,0,0,1,0,5,0,4,0,6,0,0,0,0,0,2,0,0,7,0,0,0,0,3,0,0,0,2,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,6,0,0},
		{0,0,0,0,1,5,0,0,9,7,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,3,8,9,0,7,0,0,0,5,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,3,2,0,1,0,0,0,0,0,0,5,0,0,9,0,6,0,0,0,0,0},
		{0,0,0,0,1,0,4,0,7,0,2,0,3,0,0,0,0,0,0,6,0,0,0,0,0,0,8,0,3,0,2,0,0,0,0,0,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,5,0,0,0,0,1,0,0,0,0,0,0,8,0,0,0,0,6,0,0,0,2,0},
		{0,0,0,0,2,5,0,1,0,0,3,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,4,0,3,0,0,6,0,0,0,7,0,0,0,0,4,0,0,5,0,0,0,0,0,0,0,0,8,0,0,6,0,0,0,0,0,0,0,0,4,0,0,3,0,0,1,0,0,0,0,0,0,2,0},
		{0,3,1,0,0,0,0,0,5,0,0,0,8,0,0,0,2,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,1,0,0,7,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,8,3,0,0,0,0,3,1,9,0,0,6,4,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0},
		{0,8,0,0,9,0,1,0,0,6,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,9,0,8,0,0,0,4,0,3,0,0,0,0,0,0,6,0,0,0,0,0,8,0,1,0,0,0,0,0,0,0,0,0,7,0,0,0,2,0,5,9,0,0,0,0,0,0,0},
		{1,0,0,5,0,0,3,0,0,0,0,0,3,0,6,0,0,0,2,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,2,0,0,0,0,3,0,0,4,0,0,0,0,7,0,0,0,0,0,0,0,3,0,0,0,7,8,0,0,4,0,0,1,2,0,0,0,0,0,0,0,0,0,0,0,0}
	};
	srand(time(NULL));
	int N = rand() % 14;
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 8; j++)
			printf("%d ", question[N][i][j]);
		printf("%d\n", question[N][i][8]);
	}
	printf("\n");
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
				if(setTrue(map[i][j], i, j) == 0)
				{
					printf("0\n");
					return;
				}
	switch(backtracking(*this))
	{
		case 0:
			printf("0\n");
			break;
		case 1:
			printf("1\n");
			print();
			break;
		case 2:
			printf("2\n");
			break;
	}
}
int Sudoku::setTrue(int n, int row, int col)
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
int Sudoku::setFalse(int n, int row, int col)
{
	//self
	if(bitmap[n][row][col] == -1) bitmap[n][row][col] = 0;
	else return 0;
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
					if(getBoxNum(0, n, i/3, j/3) == 9) return 0; //conflict
					if(getRowNum(0, n, i) == 9) return 0; //conflict
					if(getColNum(0, n, j) == 9) return 0; //conflict
					if(getCellNum(0, i, j) == 9) return 0; //conflict
					if(bitmap[n][i][j] == -1)
					{
						if(getBoxNum(-1, n, i/3, j/3) == 1)
						{
							setTrue(n, i, j);
							++changed;
						}
						else if(getRowNum(-1, n, i) == 1)
						{
							setTrue(n, i, j);
							++changed;
						}
						else if(getColNum(-1, n, j) == 1)
						{
							setTrue(n, i, j);
							++changed;
						}
						
						else if(getCellNum(-1, i, j) == 1)
						{
							setTrue(n, i, j);
							++changed;
						}
					}
				}
			}
		}
		if(changed == 0) return 1; //if single test makes no change, leave
	}
}
int Sudoku::backtracking(Sudoku & thisSudoku)
{
	int nij = getPossible();
	if(nij == -1) return 1; //if all cells are complete, leave
	visited[nij] = 1;
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
				su.setTrue(n, i, j);  //give trial value
				switch(su.backtracking(su)) //check the trial value
				{
					case 0: //if the trial value is wrong
						setFalse(n, i, j); //set the cell false
						return backtracking(thisSudoku); //continue the following cell
						break;
					case 1: //if the trial value is right so all su cells are complete
					{
						setFalse(n, i, j);  //set the right trail value false to find if there is another solution
						Sudoku su2 = thisSudoku; //set another temp sudoku
						int backtrackingResult = su2.backtracking(su2);
						switch(backtrackingResult)
						{
							case 0:
								thisSudoku = su; //give the trail result to the original one
								return 1; //up to now, this sudoku has one solution
								break;
							case 1:
								return 2; //this sudoku has two or more solutions
								break;
							case 2:
								return 2; //this sudoku has two or more solutions
								break;
						}
						break;
					}
					case 2:
						return 2; //this sudoku has two or more solutions
						break;
				}
			}
			else return backtracking(thisSudoku); //if the cell is set, continue the following cell
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
int Sudoku::getCellNum(int N, int row, int col)
{
	int cellNum = 0;
	for(int n = 0; n < 9; n++) if(bitmap[n][row][col] == N) cellNum++;
	return cellNum;
}
int Sudoku::getPossible()
{
	int minBit;
	double minValue = 1000;
	for(int n = 0; n < 9; n++)
	{
		for(int i = 0; i < 9; i++)
		{
			for(int j = 0; j < 9; j++)
			{
				if(visited[n * 81 + i * 9 + 1] == 0 && bitmap[n][i][j] == -1)
				{
					//setting weight
					int value = 0;
					int rowNum = getRowNum(-1, n, i), colNum = getColNum(-1, n, j), boxNum = getBoxNum(-1, n, i/3, j/3), cellNum = getCellNum(-1, i, j);
					//The first priority is those who have only one unset bit
					if((rowNum-1)*(colNum-1)*(boxNum-1)*(cellNum-1) != 0) value += 10;
					//The second priority is regions who have less unset
					int value1 = rowNum;
					int tempvalue = colNum;
					if(tempvalue < value1) value1 = tempvalue;
					tempvalue = boxNum;
					if(tempvalue < value1) value1 = tempvalue;
					tempvalue = cellNum;
					if(tempvalue < value1) value1 = tempvalue;
					value += value1;
					//find the least weight, and give the corresponding bit
					if(value < minValue)
					{
						minBit = n * 81 + i * 9 + j;
						minValue = value;
					}
				}
			}
		}
	}
	//if the bit is visited or set, return -1, else return the minimum bit position
	return (minValue == 1000) ? -1 : minBit;
}

void Sudoku::print()
{
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 8; j++)
			printf("%d ", map[i][j] + 1);
		printf("%d\n", map[i][8] + 1);
	}
	printf("\n");
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
	printf("\n");
}

void Sudoku::setMapCell(int n, int row, int col)
{
	map[row][col] = n;
}
void Sudoku::changeNum(int n1, int n2)
{
	--n1; --n2;
	Sudoku su = *this;
	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 9; j++)
		{
			if(map[i][j] == n1)
				su.setMapCell(n2, i, j);
			else if(map[i][j] == n2)
				su.setMapCell(n1, i, j);
		}
	*this = su;
}
void Sudoku::changeRow(int r1, int r2)
{
	Sudoku su = *this;
	for(int j = 0; j < 9; j++)
	{
		for(int i = 0; i < 3; i++)
		{
			su.setMapCell(map[r1 * 3 + i][j], (r2 * 3 + i), j);
			su.setMapCell(map[r2 * 3 + i][j], (r1 * 3 + i), j);
		}
	}
	*this = su;
}
void Sudoku::changeCol(int c1,int c2)
{
	Sudoku su = *this;
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			su.setMapCell(map[i][(c1 * 3 + j)], i, (c2 * 3 + j));
			su.setMapCell(map[i][(c2 * 3 + j)], i, (c1 * 3 + j));
		}
	}
	*this = su;
}
void Sudoku::rotate(int n)
{
	//i,j -> (i - 4),(j - 4) -> (j - 4),-(i - 4) -> (j - 4) + 4,-(i - 4) + 4 -> j,(8 - i)
	Sudoku su = *this;
	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 9; j++)
		{
			if((n % 4) == 1)
				su.setMapCell(map[i][j], j, (8 - i));
			else if((n % 4) == 2)
				su.setMapCell(map[i][j], (8 - i), (8 - j));
			else if((n % 4) == 3)
				su.setMapCell(map[i][j], (8 - j), i);
		}
	*this = su;
}
void Sudoku::flip(int n)
{
	//horizontally(1): j,i -> (j - 4),(i - 4) -> -(j - 4),(i - 4) -> -(j - 4) + 4,(i - 4) + 4 -> i,(8 - j)
	Sudoku su;
	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 9; j++)
		{
			if(n == 0)
				su.setMapCell(map[i][j], (8 - i), j);
			else if(n == 1)
				su.setMapCell(map[i][j], i, (8 - j));
		}
	*this = su;
}
void Sudoku::transform()
{
	srand(time(NULL));
	changeNum(rand() % 9 + 1, rand() % 9 + 1);
	changeRow(rand() % 3, rand() % 3);
	changeCol(rand() % 3, rand() % 3);
	rotate(rand() % 4);
	flip(rand() % 2);
	print();
}

void Sudoku::start()
{
	timmer.start();
}
void Sudoku::finish()
{
	printf("using %f seconds\n", timmer.getElapsedTime());
}