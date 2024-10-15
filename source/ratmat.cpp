
#include "../types/ratmat.h"

namespace slap {

    intvec2 slap::ratmat::getSize()
    {
		int width = cols.size();
		return intvec2(width, (width > 0) ? cols[0].nums.size() : 0);
    }

	// setSize can either add new vectors which are zero vectors by default,
	// or it can remove the last few columns to accomodate the new size
	void ratmat::setSize(intvec2 size)
	{
		// Set size coulmn-wise, resizing each existing column
		for (int i = 0; i < this->getSize().x; i++)
		{
			cols[i].setSize(size.y);
		}

		// Set size row-wise, augmenting the matrix with zero vectors or
		// popping a few existing ones back
		int difference = size.x - cols.size();
		if (difference > 0) {
			for (int i = 0; i < difference; i++)
			{
				ratvec v_zero;
				v_zero.setSize(size.y);
				cols.push_back(v_zero);
			}
		}
		else if (difference < 0) {
			for (int i = 0; i < -difference; i++)
			{
				cols.pop_back();
			}
		}
	} // Minor optimisation possible: function structure identical to function in ratvec

	ratvec ratmat::getCol(unsigned int column)
	{
		return cols[column];
	}

	void ratmat::setCol(unsigned int column, ratvec v)
	{
		// If the size of the column differs, it is not set
		if(this->getSize().y == v.getSize())
			cols[column] = v;
	}

	rat ratmat::get(intvec2 entry)
	{
		return cols[entry.x].nums[entry.y];
	}

	void ratmat::set(intvec2 entry, rat value)
	{
		cols[entry.x].nums[entry.y] = value;
	}

	// Operations

	ratmat ratmat::operator+(ratmat addend)
	{
		// Does not require equal size; ignores remaining entries

		ratmat m_sum = *this; // Minor optimisation possible: allocate memory first
		intvec2 m = this->getSize();
		if (addend.getSize().x < getSize().x)
			m.x = addend.getSize().x;
		if (addend.getSize().y < getSize().y)
			m.x = addend.getSize().y;

		for (int x = 0; x < m.x; x++)
		{
			for (int y = 0; y < m.y; y++)
			{
				m_sum.cols[x].nums[y] = cols[x].nums[y] + addend.cols[x].nums[y];
			}
		}
		return m_sum;
	}

	ratmat ratmat::operator*(rat scalar)
	{
		ratmat m_scaled = *this;
		for (int i = 0; i < cols.size(); i++)
			m_scaled.setCol(i,this->cols[i] * scalar);

		return m_scaled;
	}

	ratvec operator*(ratmat matrix, ratvec vector)
	{
		// Transform if and only if the size aligns
		int width = matrix.cols.size();

		if (width != vector.getSize())
			return vector;
		else {
			ratvec transformed;
			transformed.setSize(width);

			for (int i = 0; i < width; i++)
			{
				transformed = transformed + matrix.cols[i] * vector.nums[i];
			}
			return transformed;
		}
	}

	ratmat operator*(ratmat m1, ratmat m2)
	{
		// Transform if and only if the size aligns
		intvec2 s_m1 = m1.getSize();
		intvec2 s_m2 = m2.getSize();

		if (s_m1.x != s_m2.x || s_m1.y != s_m2.y)
			return m1;
		else {
			ratmat transformed;
			transformed.setSize(s_m2);

			for (int i = 0; i < s_m2.x; i++)
			{
				transformed.cols[i] = m1 * m2.cols[i];
			}
			return transformed;
		}
	}
}
