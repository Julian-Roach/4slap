#pragma once

#include "ratvec.h"

// The ratmat class embodies a rectnagular matrix with rat objects as entries
namespace slap {

	class ratmat
	{
	public:

		std::vector<ratvec> cols;

		intvec2 getSize();
		void setSize(intvec2 size);
		ratvec getCol(unsigned int column);
		void setCol(unsigned int column, ratvec v);
		rat get(intvec2 entry);
		void set(intvec2 entry, rat value);


		ratmat operator+(ratmat addend);
		ratmat operator*(rat scalar);
	};

	ratvec operator*(ratmat matrix, ratvec vector);
	ratmat operator*(ratmat m1, ratmat m2);

	// Functions for generation of operation matrices

	ratmat I(int n);
	// The second element of rows is the subtrahend row number
	ratmat E(int n, intvec2 rows, rat scalar);
	ratmat P(int n, intvec2 rows);
	ratmat S(int n, int row, rat scalar);
}

