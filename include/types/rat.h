#pragma once

// The class of a rational number, consisting of an integer numerator and denominator
#include "../gcd/gcd.h"
#include "intvec.h"

namespace slap {

	class rat
	{
	private:
		
		void simplify();

	public:
		
		bool limitCrossed = false; // Is this really necessary?
		LINT N, D;

		inline rat(LINT N_init = 0, LINT D_init = 1) : N(N_init), D(D_init) { simplify(); };

		void set(LINT N_new, LINT D_new);
		intvec2 get();

		rat operator+(rat addend);
		rat operator*(rat factor);
	};

}