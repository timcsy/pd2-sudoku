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
		static const int sudokuSize = 81;
	private:
		int setCell(int n, int row, int col); //0:conflict ; 1:success
		
		int single(int n); //single test (including hidden single and naked single)
		void backtracking(Sudoku su, int ij = 0); //the recursive backtracking method
		
		int * getRowNum(int N); //give the number of given value of a row
		int * getColNum(int N); //give the number of given value of a column
		int * getBoxNum(int N); //give the number of given value of a box
		
		void print(); //print the sudoku to standard output
		
		//The following sudoku number stored is 0~8
		signed char bitmap[9][9][9]; //-1:unset ; 0:false ; 1:true
		signed char map[9][9];  //-1:unset ; 0~8:number
}