#include "validator.h"
#include <cassert>

void run() {
	long long relo = Arg("lo"), rehi = Arg("hi");
	long long lo = Int(relo, rehi);
	bool eq = Arg("eq", "no") == "yes";
	Space();
	long long hi = Int(lo, rehi);
	Endl();
	Eof();

	if (eq)
		assert(lo == hi);
}