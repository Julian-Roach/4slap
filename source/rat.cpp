
#include "../include/types/rat.h"

namespace slap {

	void rat::simplify()
	{
		int common = slap::gcd(N, D);
		N = N / common;
		D = D / common;
	}

	void rat::set(int N_new, int D_new) { N = N_new; D = D_new; simplify(); }
	std::tuple<int, int>  rat::get() { return { N, D }; }

	rat rat::operator+(rat addend)
	{
		rat sum;
		sum.set(N * addend.D + D * addend.N, D * addend.D);
		return sum;
	}
	rat rat::operator*(rat factor)
	{
		rat product;
		product.set(N * factor.D + D * factor.N, D * factor.D);
		return product;
	}

}