

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// Global variables all functions use.
const int RUNNER_STATS = 7;
const int RUNNER_CHOICE = 5;
const string datafile = "runners.txt";

struct runnerstats
{
	string runnername;
	int runnermiles[RUNNER_STATS];
	double runnertotal;
	double runneraverage;
};

//The parameters for the functions.
int getdata(runnerstats runners[]);

void totaldata(runnerstats runners[]);

void avgdata(runnerstats runners[]);

int main()
{
	//Some variables that will be utilized by the functions. These contain the data the program will output.
	runnerstats runners[RUNNER_CHOICE];

	int elmprint;

	//These call the functions.
	elmprint = getdata(runners);
	totaldata(runners);
	avgdata(runners);

	//All the outputs are here. Each column runs the score data and the runner total and runner average are ran at the end of each row.
	for (int row = 0; row < elmprint; row++)
	{
		cout << runners[row].runnername << " ";
		for (int col = 0; col < RUNNER_STATS; col++)
		{
			cout << setw(7) << runners[row].runnermiles[col] << " ";
		}
		cout << setw(7) << runners[row].runnertotal << " ";
		cout << setw(7) << runners[row].runneraverage;
		cout << endl;
	}
}

//Stores the data in the text document into an array.
int getdata(runnerstats runners[])
{
	ifstream inputFile;
	inputFile.open(datafile);
	int rec = 0;

	while (inputFile >> runners[rec].runnername)
	{
		for (int i = 0; i < RUNNER_STATS; i++)
			inputFile >> runners[rec].runnermiles[i];
		rec++;
	}
	return rec;
}

//Finds the total of each row and stores it to the runner total to be output.

void totaldata(runnerstats runners[])
{
	for (int row = 0; row < RUNNER_CHOICE; row++)
	{
		int total = 0;
		for (int col = 0; col < RUNNER_STATS; col++)
		{
			total += runners[row].runnermiles[col];
		}
		runners[row].runnertotal = total;
	}
}

//Finds the average of each row and stores it to the runner average to be output.
void avgdata(runnerstats runners[])
{
	for (int row = 0; row < RUNNER_CHOICE; row++)
	{
		float average = 0;
		average = runners[row].runnertotal / 2;
		runners[row].runneraverage = average;
	}
}

