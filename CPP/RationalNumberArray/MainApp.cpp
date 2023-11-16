#include <iostream>
#include "RationalNumberArray.h"

using namespace std;

int main(int argc, char** argv)
{

	int rows = 3;
	int cols = 5;

	// -- pointer instantiation
	RationalNumberArray* rna = new RationalNumberArray(rows, cols);
	cout << rna->toString() << "Mean: " << rna->getMean() << " Standard Dev: " << rna->getStdDev() << endl << endl;

	// -- assign values to the data cells
	for (int i = 0; i < rna->getRows(); ++i) {
		for (int j = 0; j < rna->getCols(); ++j) {
			RationalNumber value(j + i * cols + 1, 3);
			rna->setCell(i, j, value);
		}
	}
	cout << rna->toString() << "Mean: " << rna->getMean() << " Standard Dev: " << rna->getStdDev() << endl << endl;

	// -- copy constructor instantiation
	RationalNumberArray* rna2 = new RationalNumberArray(*rna);
	cout << rna->toString() << "Mean: " << rna->getMean() << " Standard Dev: " << rna->getStdDev() << endl << endl;

	try {
		RationalNumber value(1, 2);
		rna2->setCell(-1, 0, value);
	}
	catch (const char* msg) {
		cout << msg << endl << endl;
	}

	// -- pointer deletion
	delete rna2;
	delete rna;

	// -- non pointer instantiation
	RationalNumberArray ra(4, 4);
	// -- assign values to the data cells
	for (int i = 0; i < ra.getRows(); ++i) {
		for (int j = 0; j < ra.getCols(); ++j) {
			RationalNumber value(j + i * cols + 1, 2);
			ra.setCell(i, j, value);
		}
	}

	cout << ra.toString() << "Mean: " << ra.getMean() << " Standard Dev: " << ra.getStdDev() << endl << endl;

	return 0;

}