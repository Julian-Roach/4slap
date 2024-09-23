
#include "../include/gcd/gcd.h"

namespace slap {

	int gcd(int a, int b)
	{
		int r = a % b;

		if (r != 0)
			return gcd(b, r);
		else
			return b;

		return 0;
	}

}
