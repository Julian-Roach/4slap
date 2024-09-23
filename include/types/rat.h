#pragma once

// The class of a rational number, consisting of an integer numerator and denominator
#include "../gcd/gcd.h"
#include <tuple>

namespace slap {

	class rat
	{
	private:

		int N, D;
		void simplify();

	public:

		inline rat(int N_init = 0, int D_init = 1) : N(N_init), D(D_init) {};

		void set(int N_new, int D_new);
		std::tuple<int, int> get();

		rat operator+(rat addend);
		rat operator*(rat factor);
	};

}