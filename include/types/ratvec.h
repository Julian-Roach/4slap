#pragma once

#include "rat.h"
#include <vector>

namespace slap {

	class ratvec
	{
	public:
		std::vector<slap::rat> entries;

		unsigned int getSize();
		void setSize(unsigned int size);
		rat get(int entry);
		void set(unsigned int entry, rat value);

		ratvec operator+(ratvec addend);
		ratvec operator*(rat scalar);
	};

	// Dot product operation
	rat dot(ratvec v1, ratvec v2);
}
