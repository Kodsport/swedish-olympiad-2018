#include "validator.h"
#include <bits/stdc++.h>
#include <cassert>


void run() {
	string inp = Word();
	Endl();

	int n = Arg("n", 15);
	assert(inp.length() <= n);

	for (char i: inp) {
		assert(i=='S' or i=='V');
	}
}
