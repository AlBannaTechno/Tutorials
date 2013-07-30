#include <iomanip>
#include <iostream>

using std::cout;	using std::endl;	using std::setw; 	using std::setprecision;

int digits(double, int);

int main()
{
	const double max_base = 99.9;

	// find the number of digits in the highest base
	int max_base_width = digits(max_base, 2);

	// find the size of the highest square, allowing for 2 decimal places in the result
	int max_result_width = digits(max_base * max_base, 2);

	for (double i = 1; i <= max_base; i += .1) {
		// add 2 to the maximum widths to allow for the decimal point and one space for padding
		cout << setw(max_base_width + 2) << setprecision(max_base_width) << i
			 << setw(max_result_width + 2) << setprecision(max_result_width) << (i * i) << endl;
	}

	return 0;
}

// return the number of digits in n
int digits(double n, int places)
{
	// initialize result to the number of desired decimal places
	int result = places;

	while (n >= 1) {
		// add 1 to the result
		++result;
		// and remove a digit before the next pass
		n /= 10;
	}

	return result;
}
