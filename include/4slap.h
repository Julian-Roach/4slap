#pragma once

#include "types/rat.h"
#include "types/ratvec.h"
#include "types/ratmat.h"

// Commit: renamed "entries" to "nums" to distinguish between memebers
// mmore easily. Created ratmat class

// Matters yet to be handled:
// 
// In gcd.h: code for debug (remove)
// In ratvec.cpp: minor optimisations due
// In rat.h: questioning the purpose of limitCrossed
// In ratmat.cpp: function structure repeated
// In rat.cpp: type conversion between int and rat
// In rat.cpp: automatic conversion from "int/int" to rat
// In source files: getting rid of minor warnings
// 
