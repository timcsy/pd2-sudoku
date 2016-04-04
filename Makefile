pd2-sudoku:main.o Sudoku.o Clock.o
	g++ -o Sudoku main.o Sudoku.o Clock.o
main.o:main.cpp Sudoku.h
	g++ -c main.cpp
Sudoku.o:Sudoku.cpp Sudoku.h Clock.h
	g++ -c Sudoku.cpp
Clock.o:Clock.cpp Clock.h
	g++ -c Clock.cpp
clean:
	rm Sudoku *.o