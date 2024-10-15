
#include "../types/ratvec.h"

namespace slap
{
	unsigned int ratvec::getSize()
	{
		return nums.size();
	}

	// setSize can either add new entries which are 0 by default,
	// or it can remove the last few entries to accomodate the new size
	void ratvec::setSize(unsigned int size)
	{
		int difference = size - nums.size();

		if (difference > 0) {
			for (int i = 0; i < difference; i++)
			{
				nums.push_back(rat());
			}
		}
		else if (difference < 0) {
			for (int i = 0; i < -difference; i++)
			{
				nums.pop_back();
			}
		}
	}

	rat ratvec::get(unsigned int entry)
	{
		return nums[entry];
	}

	void ratvec::set(unsigned int entry, rat value)
	{
		if (getSize() > entry)
			nums[entry] = value;
	}

	// Operations

	ratvec ratvec::operator+(ratvec addend)
	{
		// Does not require equal size; ignores remaining entries
		int m = nums.size();
		if (m > addend.nums.size())
			m = addend.nums.size();

		ratvec v_sum; // Minor optimisation possible: allocate memory first
		for (int i = 0; i < m; i++)
			v_sum.nums.push_back(nums[i] + addend.nums[i]);

		return v_sum;
	}

	ratvec ratvec::operator*(rat scalar)
	{
		ratvec v_scaled; // Minor optimisation possible: allocate memory first
		for (int i = 0; i < nums.size(); i++)
			v_scaled.nums.push_back(nums[i] * scalar);

		return v_scaled;
	}
	
	rat operator*(ratvec v1, ratvec v2)
	{
		// Does not require equal size; assumes 0 for nonexistent entries
		int m = v1.nums.size();
		if (m > v2.nums.size())
			m = v2.nums.size();

		rat sum;
		for (int i = 0; i < m; i++)
			sum = sum + (v1.get(i) * v2.get(i));
		
		return sum;
	}
}