#include "Sudoku.h"
using namespace std;

int main()
{
	for(int i = 0; i < 500; i++)
	{
	Sudoku su;
	//su.giveQuestion();
	//su.transform();
	su.readIn();
	su.start();
	su.solve();
	su.finish();
	}
}