#include "Clock.h"

class Sudoku
{
	public:
		Sudoku();
		void giveQuestion(); //output 81 digits
		void readIn(); //input 81 digits
		void solve(); //output my solved answer
		void changeNum(int n1, int n2);
		void changeRow(int r1, int r2);
		void changeCol(int c1,int c2);
		void rotate(int n);
		void flip(int n);
		void transform();
		void start();
		void finish();
		
	private:
		int setTrue(int n, int row, int col); //0:conflict ; 1:success
		int setFalse(int n, int row, int col); //0:conflict ; 1:success
		void setMapCell(int n, int row, int col);
		
		int single(); //single test (including hidden single and naked single)
		int backtracking(Sudoku & thisSudoku); //the recursive backtracking method
		
		int getRowNum(int N, int n, int row); //give the number of given value of a row
		int getColNum(int N, int n, int col); //give the number of given value of a column
		int getBoxNum(int N, int n, int boxRow, int boxCol); //give the number of given value of a box
		int getCellNum(int N, int row, int col); //give the number of given value of a cell
		int getPossible(); //give the highest priority cell

		void print(); //print the sudoku to standard output
		void bitprint();  //print the sudoku bitmap to standard output
		
		//The following sudoku number stored is 0~8
		signed char bitmap[9][9][9]; //-1:unset ; 0:false ; 1:true
		signed char map[9][9];  //-1:unset ; 0~8:number
		bool visited[729];
		
		signed char boxNum[2][9][3][3];  //[0:false, 1:unset][num][boxRow][boxCol]
		signed char rowNum[2][9][9];  //[0:false, 1:unset][num][row]
		signed char colNum[2][9][9];  //[0:false, 1:unset][num][col]
		signed char cellNum[2][9][9];  //[0:false, 1:unset][row][col]
		
		Clock timmer;
};