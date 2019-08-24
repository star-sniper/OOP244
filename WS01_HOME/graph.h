#include <iostream>
using namespace std;


#define MAX_NO_OF_SAMPLES 20
// Performs a fool-proof integer entry
// Fills the samples array with the statistic samples
namespace sict
{
	void getSamples(int samples[], int noOfSamples);
	// Displays the user interface menu
	// Finds the largest sample in the samples array, if it is larger than 70,
	// therwise it will return 70.
	int findMax(int samples[], int noOfSamples);
	// Prints a scaled bar relevant to the maximum value in samples array
	void printBar(int val, int max);
	// Prints a graph comparing the sample values visually
	void printGraph(int samples[], int noOfSamples);
}
