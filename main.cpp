#include "Sudoku.h"
using namespace std;

int main()
{
	Sudoku su;
	//su.giveQuestion();
	//su.transform();
	su.readIn();
	su.solve();
}