#pragma once

#include "rat.h"
#include <vector>

// The ratvec class embodies a vector with rat objects as components
namespace slap {

	class ratvec
	{
	public:
		std::vector<rat> nums;

		unsigned int getSize();
		void setSize(unsigned int size);
		rat get(unsigned int entry);
		void set(unsigned int entry, rat value);

		ratvec operator+(ratvec addend);
		ratvec operator*(rat scalar);
	};

	// Dot product operation
	rat operator*(ratvec v1, ratvec v2);
}
