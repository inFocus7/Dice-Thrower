#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

void Roll(int numThrows, int maxRoll, int numdice, double * data)
{
	int roll;
	double temp;

	for (int i = 1; i <= numThrows; i++)
	{
		roll = rand() % (maxRoll - numdice + 1) + numdice; //rand from lowest to maxRoll, looks really weird, but works.
		temp = data[roll - numdice];
		temp++;
		data[roll - numdice] = temp;
	}
}
void stats(int numThrows, int numdice, int maxRoll, double * data)
{
	int index = maxRoll / 6, width, total = 0;
	cout << "ROLL STATISTICS" << endl;
	cout << "_______________" << endl;
	for (int i = 0; i <= (maxRoll - numdice); i++)
	{
		//Doing this small addition to make the table look nicer
		if (index < 10)
			width = 14;
		else if (index >= 10 && index < 100)
			width = 13;
		else
			width = 12;
		//Was thinking about using setprecision() to make decimals look better, but didn't want to risk data looking like it's missing.
		cout << index << ":" << setw(width) << data[i]/numThrows << endl;
		index++;

		//To see if there were any "throws" missing. (checks to see if the total counted == total thrown [inputted])
		total += data[i];
	}
	cout << "_______________" << endl;
	if (total == numThrows)
		cout << "Successfully threw " << numdice << " dices " << total << " times!" << endl;
	else
		cout << "I seemed to have lost " << numThrows - total << " rolls around here somewhere..." << endl;
}

int main()
{
	srand(time(NULL));
	int numThrows, numdice, maxRoll;

	cout << "How many dices do you want to throw?" << endl;
	cin >> numdice;
	maxRoll = 6 * numdice;
	cout << "How many times do you want to throw the six-sided dice(s)?" << endl;
	cin >> numThrows;
	double * data = new double[5 * numdice];

	//Initialize everything in array to 0
	for (int i = 0; i <= (5 * numdice); i++)
		data[i] = 0;
	//Roll
	Roll(numThrows, maxRoll, numdice, data);
	stats(numThrows, numdice, maxRoll, data);

	return 0;
}