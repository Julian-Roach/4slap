
######################################################################
4SLAP - Simple, Suboptimal System Solving Library Aiming for Precision

A library containing tools for solving linear systems of equations
having rational numbers as coefficients. It is meant to be easily
usable, not necessarily efficient, and most importantly: the solutions
should be perfect. This means the user can receive a solution x to the
equation Mx = v, where M is a matrix and v is a vector, such that x
will only contain rational components - no decimal approximations!
Naturally, the requirement here is for M and v to contain exclusively
rational numbers. 4SLAP revolves around rational numbers.

Rational numbers are the heart of 4SLAP. The core type is the "rat"
class embodying an arbitrary fraction. The "rat" class itself is
composed of a numerator and denominator, them both being of LINT type.
LINT is simply a macro for "long long int." Such large integers are
used to ensure accuracy when a system is being solved. The "rat" class
posesses its own operations like addition and multiplication.

The "rat" class is basis for other types introduced in the library,
in particular, "ratvec and "ratmat," which are tensors made up of
rational entries. They too have their own operations, working
precisely as convention has it.

By: Julian Zielinski
######################################################################
