pd2-sudoku:main.o Sudoku.o
	g++ -o main.o Sudoku.o
main.o:main.cpp Sudoku.h
	g++ -c main.o main.cpp
Sudoku.o:Sudoku.cpp Sudoku.h
	g++ -c Sudoku.o Sudoku.cpp
clean:
	rm Sudoku *.o