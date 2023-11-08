#include <iostream>
using namespace std;

int main()
{
	cout << "                                            -----------------------------" << endl;
	cout << "                                            |   Monte Carlo Simulator   |" << endl;
	cout << "                                            |       MSA Unversity       |" << endl;
	cout << "                                            |   Credits: Mohamed Amr    |" << endl;
	cout << "                                            -----------------------------" << endl << endl;
	int n;
	cout << "(/) Specify a number of values: ";
	cin >> n;
	int* values = new int [n];
	float* p = new float[n];
	float* c = new float[n];
	int* cum_int = new int[n];
	int* interval_1 = new int[n];
	int* interval_2 = new int[n];
	int* random_number = new int[n];

	//Input values and their relative probability
	
	cout << "Please enter each value followed by it's corresponding probability.." << endl << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "No [" << i << "]    : "; 
		cin >> values[i]; 
		cout << "No [" << i << "] (P): ";
		cin >> p[i]; 
		cout << endl;
	}

	//Cumulative Calculation
	c[0] = p[0];
	float c_tot = p[0];
	for (int i = 1; i < n; i++)
	{
		c_tot += p[i];
		c[i] = c_tot;
	}

	//Convert cumulative values to non-fraction for random interval
	for (int i = 0; i < n; i++)
	{
		if (c[i] < 1 && c[i] > 0)
		{
			cum_int[i] = c[i] * 100;
		}
	}

	//Random Intervals
	interval_1[0] = 0;
	interval_2[0] = cum_int[0];
	for (int i = 1; i < n; i++)
	{
		interval_2[i] = cum_int[i];
		interval_1[i] = cum_int[i - 1];
	}

	//Random Number Generation
	int input, input2;
	cout << "(/) How many random numbers for MonteCarlo?: ";
	cin >> input2;
	cout << "(/) Do you want to specify your own set of numbers or auto generate?" << endl;
	cout << "1. Auto generate" << endl;
	cout << "2. I want to specify the numbers" << endl;
	cin >> input;
	if (input == 1)
	{
		cout << "The following numbers have been randomly generated: " << endl;
		for (int i = 0; i < input2; i++)
		{
			random_number[i] = rand() % 100;
			//random_number[i] = random_number[i] / 100;
			cout << random_number[i] << endl;
		}
	}
	else if (input == 2)
	{
		cout << "Please insert the random numbers.." << endl;
		for (int i = 0; i < input2; i++)
		{
			cout << "Random Number" << i << ": ";
			cin >> random_number[i];
		}
	}
	else
	{
		cout << "Input Error" << endl;
	}

	//Print Table
	cout << "------------------------------------------------------------------" << endl;
	cout << "  #  " << "   |Value" << "   |Probability" << "   |C.Probability" << "   |Random Intervals" << endl;
	cout << "------------------------------------------------------------------" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "No(" << i << ")" << "   |   " << values[i] << "   |   " << p[i] << "       |       " << c[i] << "      |      " << interval_1[i] << " -< " << interval_2[i] << endl;
		cout << "------------------------------------------------------------------" << endl;
	}

	//Classify random numbers according to their laying interval & find corresponding value
	cout << endl;
	cout << "----------------------" << endl;
	cout << "Random Number" << "|" <<  "Value" << endl;
	cout << "----------------------" << endl;
	for (int i = 0; i < input2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (random_number[i] >= interval_1[j] && random_number[i] <= interval_2[j])
			{
				cout << random_number[i] << "     |      " << values[j] << endl;
				cout << "----------------------" << endl;
			}
		}
	}

	system("pause");
}
