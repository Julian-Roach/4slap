#pragma once

#include "LINT.h"

// Simple specifically sized integer vector classes. The intvec2 class is crucial for rat::get().

namespace slap {

	// Two-dimensional integer vector class.
	class intvec2
	{
	public:
		LINT x, y;

		inline intvec2(LINT x_init = 0, LINT y_init = 0)
			: x(x_init), y(y_init) {};
	};

	// Three-dimensional integer vector class.
	class intvec3 : public intvec2
	{
	public:
		LINT z;

		inline intvec3(LINT x_init = 0, LINT y_init = 0, LINT z_init = 0)
			: intvec2(x_init, y_init), z(z_init) { };
	};

	// Four-dimensional integer vector class.
	class intvec4 : public intvec3
	{
	public:
		LINT w;

		inline intvec4(LINT x_init = 0, LINT y_init = 0, LINT z_init = 0, LINT w_init = 0)
			: intvec3(x_init, y_init, z_init), w(w_init) { };
	};

	// Optionally, operators such as addition, scalar multiplication as well as
	// the dot product may be added, but currently provide no reasonable benefit.
}
