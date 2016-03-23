class Sudoku
{
	public:
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
		int * getRow(int row);
		int * getCol(int col);
		int * getBox(int box);
		
		void setCell(int n, int i, int j);
		
		void single(int n);
		void hiddenSingle();
		void nakedSingle();
		void backTracking();
		
		int map[sudokuSize];
		signed char map[9][9][9];
}