

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// Global variables all functions use.
const int RUNNER_STATS = 7;
const int RUNNER_CHOICE = 5;
const string datafile = "runners.txt";

//The parameters for the functions.
int getdata(string names[], double times[][RUNNER_CHOICE], int totals[], float avgs[]);

void totaldata(int totaltime[], double storedtimes[][RUNNER_CHOICE]);

void avgdata(int totaltime[], float averagetime[]);

int main()
{
	//Some variables that will be utilized by the functions. These contain the data the program will output.
	string runners[RUNNER_STATS];
	double runnerscores[RUNNER_STATS][RUNNER_CHOICE];
	int runnertotal[RUNNER_STATS];
	float runneravg[RUNNER_STATS];

	int elmprint;

	//These call the functions.
	elmprint = getdata(runners, runnerscores, runnertotal, runneravg);
	totaldata(runnertotal, runnerscores);
	avgdata(runnertotal, runneravg);

	//All the outputs are here. Each column runs the score data and the runner total and runner average are ran at the end of each row.
	for (int row = 0; row < elmprint; row++)
	{
		cout << runners[row] << " ";
		for (int col = 0; col < RUNNER_STATS; col++)
		{ 
			cout << setw(10) << runnerscores[row][col] << " ";
		}
		cout << setw(10) << runnertotal[row] << " ";
		cout << setw(10) << runneravg[row];
		cout << endl;
	}

	
}

//Stores the data in the text document into an array.
int getdata(string names[], double times[][RUNNER_CHOICE], int totals[], float avgs[])
{
	ifstream inputFile;
	inputFile.open(datafile);
	int rec = 0;

	while (inputFile >> names[rec] || rec < RUNNER_CHOICE)
	{
		for (int i = 0; i < RUNNER_STATS; i++)
			inputFile >> times[rec][i];
		rec++;
	}
	return rec;
}

//Finds the total of each row and stores it to the runner total to be output.
void totaldata(int totaltime[], double storedtimes[][RUNNER_CHOICE])
{
	for (int row = 0; row < RUNNER_CHOICE; row++)
	{
		int total = 0;
		for (int col = 0; col < RUNNER_STATS; col++)
		{
			total = total + storedtimes[row][col];
		}
		totaltime[row] = total;
	}
}

//Finds the average of each row and stores it to the runner average to be output.
void avgdata(int totaltime[], float averagetime[])
{
	for (int row = 0; row < RUNNER_CHOICE; row++)
	{
		float average = 0;
		average = totaltime[row] / 2;
		averagetime[row] = average;
	}
}