all:giveQuestion.o solve.o transform.o Sudoku.o Clock.o
	g++ -o giveQuestion giveQuestion.o Sudoku.o Clock.o
	g++ -o solve solve.o Sudoku.o Clock.o
	g++ -o transform transform.o Sudoku.o Clock.o
giveQuestion.o:giveQuestion.cpp Sudoku.h
	g++ -c giveQuestion.cpp
solve.o:solve.cpp Sudoku.h
	g++ -c solve.cpp
transform.o:transform.cpp Sudoku.h
	g++ -c transform.cpp
Sudoku.o:Sudoku.cpp Sudoku.h Clock.h
	g++ -c Sudoku.cpp
Clock.o:Clock.cpp Clock.h
	g++ -c Clock.cpp
clean:
	rm giveQuestion solve transform *.o