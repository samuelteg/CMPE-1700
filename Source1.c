//*********************************************
//    Samuel Tegegne(A01)
//		S
//*********************************************
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv)
{
	//If the argument is not morethan two, show error
	if (argc != 2)
	{
		fprintf(stderr, "Error,one argument only!");
		exit(EXIT_FAILURE);
	}
	//If the argument is negative ,show error
	else if (argc <= 0)
	{
		fprintf(stderr, "Enter positive numbers");
		exit(EXIT_FAILURE);
	}

	unsigned int nBits = atoi(argv[1]);				// user input as an argument
	unsigned int avgOfruns = 0;						// Average number of runs of bits
	double runCount = 0;							//Check the number of runs for a given number
	double runTotal = 0;							//Check the total number of runs for a given number
	double nAverage = 0;							//Average number of runs 

	// Iterate through the number in tit range
	for (int c = 1; c < (1 << nBits) + 1; c++)
	{
		// Iterate through the bits in digits
		for (int i = 0; i < nBits; i++)
		{
			if (c & 1 << i && avgOfruns == 0)
			{
				avgOfruns = 1;
				runCount++;
			}
			else if (!(c & 1 << i) && avgOfruns == 1)
				avgOfruns = 0;
		}

		// calculate the running average
		runTotal = runCount;
		nAverage = runTotal / c;

		// Clear the stored number for another input
		avgOfruns = 0;
		runCount = 0;
	}
	printf("The total number of runs is %f and the running average is %f \n", runTotal,nAverage);
	exit(EXIT_SUCCESS);
}