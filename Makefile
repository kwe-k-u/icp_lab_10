output: stabbingFunctions.o testStabLineProg.o
	g++ stabbingFunctions.o testStabLineProg.o  -o output

stabbingFunctions.o: stabbingFunctions.cpp stabbingLines.h
	g++ -c stabbingFunctions.cpp

testStabLineProg.o: testStabLineProg.cpp
	g++ -c testStabLineProg.cpp

clean:
	rm *.o output


