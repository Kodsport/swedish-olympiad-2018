#include "validator.h"
#include <bits/stdc++.h>

void run() {
	vector<int> nums = SpacedInts(4, 0, 100);
	Eof();

	string mask = Arg("mask", "1111");
	for (int i=0; i<4; i++) {
		if (mask[i] == '0') {
			assert(nums[i] == 0);
		}
	}
}