//#include "stabbingFunctions.cpp"
#include "stabbingLines.h"




int main()
{
/**
reading the coordinates of points from a ;
reading the lines and their end points from a
printing, for each line, the LinId and their end point coordinates
 hx1; y1; x2; y2igetting the lines stabbed by the line "x = C."
 The value of C may be captured as an input.
*/


	ifstream linesFile, pointsFile;
	linesFile.open("lines.txt");
	pointsFile.open("points.txt");
	Line linesArray[10];
	Point pointsArray[10];
	Line stabbedLines[10];
	int counts = 10;




//TODO change points count later
	readPoints(pointsFile, pointsArray, 10, counts);
	readLines(linesFile, linesArray, 10, pointsArray, counts);
	getStabbedLines(counts, linesArray, counts, counts, pointsArray, counts, stabbedLines, counts, counts);
	printLineByCoords(5, linesArray, 10, pointsArray, 10);

}

