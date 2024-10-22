#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(int fahrenheit) {
	return (fahrenheit - 32) * 5.0 / 9.0;
}

int main() {
	//Open the input file (FahrenheitTemperature.txt) for reading
	ifstream inputFile("FahrenheitTemperature.txt");

	//Check if the input file was opened successfully
	if (!inputFile.is_open()) {
		cerr << "Error opening input file!" << endl;
		return 1;
	}

	//Open the output file (CelsiusTemperature.txt) for writing
	ofstream outputFile("CelsiusTemperature.txt");

	//Check if the output file was opened successfully
	if (!outputFile.is_open()) {
		cerr << "Error opening output file!" << endl;
	}

	//Close the input and output files
	inputFile.close();
	outputFile.close();

	cout << "Conversion completed, Check CelsiusTemperature.txt for results." << endl;
	return 0;

}