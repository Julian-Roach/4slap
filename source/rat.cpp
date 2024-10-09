
#include "../include/types/rat.h"

namespace slap {

	void rat::simplify()
	{
		LINT common = slap::gcd(N, D);
		N = N / common;
		D = D / common;
		// Normally, the numerator and denominator will cancel, but if not, warn before operations.
		if (N > 80000000 || D > 80000000) {
			limitCrossed = true;
		}

		return;
	}
	
	void rat::set(LINT N_new, LINT D_new) { N = N_new; D = D_new; simplify(); }
	intvec2 rat::get() { return { intvec2(N,D) }; }

	rat rat::operator+(rat addend)
	{
		rat sum;
		sum.set(N * addend.D + D * addend.N, D * addend.D);
		return sum;
	}
	rat rat::operator*(rat factor)
	{
		rat product;
		product.set(N * factor.N, D * factor.D);
		return product;
	}

}