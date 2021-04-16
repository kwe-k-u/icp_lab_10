#include "stabbingLines.h"



//Retrieves the list of points from a file
void readPoints(ifstream& inputFile, Point pointsArray[], const int MaxSize, int& numPoints) {
	if (inputFile.is_open()){
		string line;
		int numbers[3];


		while (getline(inputFile, line)){
			//TODO make separare function

			//finding separate numbers
			int index = 0; //which number sequence we are finding
			string digits = "";
			int count = 0; //current number of points //TODO change?
			for (char const &c: line){

			//if a new sequence of numbers begins, save the previous sequence and increase index by 1
				if (c == ' '){
					numbers[index] = stoi(digits);
					index++;

					digits = "";
				} else {
					digits += c;
				}
			}


			Point newPoint = Point{};
			newPoint.pointId = numbers[0];
			newPoint.x = numbers[1];
			newPoint.y = numbers[2];

			pointsArray[count] = newPoint;
			count++;

		}

	}

}

//Retireves the list of lines from a file
//REMINDER:!!!!!! If behaving funny, variables from readPoints are seeping into readLines
void readLines(ifstream& inputFile, Line linesArray[], const int linesSize, Point pointsArray[], const int pointsSize) {
	if (inputFile.is_open()){
		string line;
		int numbers[3];


		while (getline(inputFile, line)){
			//TODO make separare function

			//finding separate numbers
			int index = 0; //which number sequence we are finding
			string digits = "";
			int count = 0; //current number of points //TODO change?


			for (char const &c: line){
			//if a new sequence of numbers begins, save the previous sequence and increase index by 1
				if (c == ' '){
					numbers[index] = stoi(digits);
					index++;

					digits = "";
				} else {
					digits += c;
				}
			}


			Line newLine = Line{};
			newLine.id = numbers[0];
			newLine.start = numbers[1];
			newLine.end = numbers[2];

			linesArray[count] = newLine;
			count++;

		}

	}

}


//Displays the list of lines in the plane
void printLineByCoords(LineId lineId, Line linesArray[], const int linesSize, Point pointsArray[], const int pointsSize) {
	for (int lineIndex = 0; lineIndex < linesSize; lineIndex++){
		Line currentLine = linesArray[lineIndex];

		Point start = pointsArray[currentLine.start];
		Point end = pointsArray[currentLine.end];
		//LIne index 0 cordinates: x1 = 3, y1 = 3, 	 x2 = 3, y2= 3
		cout << "Line index " << lineIndex << "\tcordinates: x1= " << start.x << ", y1 = " << start.y << "\tx2= " << end.x << ", y2= " << end.y << endl;
	}
}



//Finds the lines that have been stabbed by x=C
void getStabbedLines(const int x, Line linesArray[], const int lineSize, const int lineCount, Point pointsArray[], const int pointsSize) {

		Line stabbedList[5] = {}; //TODO: change the list size
		int count = 0;

    //iterating through the lines in the plane by
    for (int lineIndex = 0; lineIndex < lineSize; lineIndex++) {// replace lineSize with lineCount??

        Line currentLine = linesArray[lineIndex];
		Point start = pointsArray[currentLine.start];
		Point end = pointsArray[currentLine.end];

        if (start.x<= x && end.x >= x) {
			stabbedList[count] = currentLine;
			count++;
        }
    }
}

