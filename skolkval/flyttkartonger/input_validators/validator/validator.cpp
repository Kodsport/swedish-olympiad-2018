#include "validator.h"

void run() {
	int lo = Arg("lo"), hi = Arg("hi");
	int n = Int(lo, hi);
	Endl();

	int max_ai = Arg("max_ai", 0);
	SpacedInts(n, 1, max_ai);
	Eof();
}