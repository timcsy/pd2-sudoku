#include "Sudoku.h"
using namespace std;

int main()
{
	Sudoku su;
	//su.giveQuestion();
	//su.transform();
	su.readIn();
	su.changeNum(1, 1);
	su.changeRow(0, 0);
	su.changeCol(0, 0);
	su.rotate(1);
	su.rotate(2);
	su.rotate(3);
	su.flip(0);
	su.flip(1);
	//su.solve();
}