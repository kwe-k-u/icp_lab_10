// Lab 10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <string>
#define MAXARRAYSIZE 500

using namespace std;

typedef int PointId;
typedef int LineId;



//Struct for a point in a 2-d plane
struct Point {
    int x;
    int y;
    PointId pointId;
};



//Struct for a line in a 2-d plane
struct Line {
    LineId id;
    PointId start;
    PointId end;
};


//function definitions
void readPoints(ifstream& inPutPointFile, Point pointsArray[], const int MaxPntsSize, int& numPoints);
void readLines(ifstream& inPutLineFile, Line linesArray[],const int MaxLnsSize, int& numLines);
void printLineByCoords(LineId lid, Line linesArray[], const int MaxLnsSize, Point pointsArray[], const int MaxPntsSize);
void getStabbedLines(const int xcoord, Line linesArray[], const int MaxLnsSize, const int NumLines, Point pointsArray[], const int MaxPtsSize, Line stabbedLines[], const int MaxStbSize, int& NumOfStbLines);

