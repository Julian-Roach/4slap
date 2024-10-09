
#include "../types/ratvec.h"

namespace slap
{
	unsigned int ratvec::getSize()
	{
		return entries.size();
	}

	// setSize can either add new entries which are 0 by default,
	// or it can remove the last few entries to accomodate the new size
	void ratvec::setSize(unsigned int size)
	{
		int difference = size - entries.size();

		if (difference > 0) {
			for (int i = 0; i < difference; i++)
			{
				entries.push_back(rat());
			}
		}
		else if (difference < 0) {
			for (int i = 0; i < -difference; i++)
			{
				entries.pop_back();
			}
		}
	}

	rat ratvec::get(int entry)
	{
		return entries[entry];
	}

	void ratvec::set(unsigned int entry, rat value)
	{
		if (getSize() > entry)
			entries[entry] = value;
	}

	rat dot(ratvec v1, ratvec v2)
	{
		// Does not require equal size; assumes 0 for nonexistent entries
		int m = v1.entries.size();
		if (m > v2.entries.size())
			m = v2.entries.size();

		rat sum;
		for (int i = 0; i < m; i++)
			sum = sum + (v1.get(i) * v2.get(i));
		
		return sum;
	}

	ratvec ratvec::operator+(ratvec addend)
	{
		// Does not require equal size; ignores remaining entries
		int m = entries.size();
		if (m > addend.entries.size())
			m = addend.entries.size();

		ratvec v_sum; // Minor optimisation possible: allocate memory first
		for (int i = 0; i < m; i++)
			v_sum.entries.push_back(entries[i] + addend.entries[i]);

		return v_sum;
	}

	ratvec ratvec::operator*(rat scalar)
	{
		ratvec v_scaled; // Minor optimisation possible: allocate memory first
		for (int i = 0; i < entries.size(); i++)
			v_scaled.entries.push_back(entries[i] * scalar);

		return v_scaled;
	}

}