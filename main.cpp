#include <iostream>
#include <cstdint>
#include <cstdio>

using std::cin;
using std::cout;
typedef uint64_t integer;
integer *cnCache, *mwcCache;

integer calculateCn(integer n, integer k, integer m, integer *a, integer *mwc) {
	if (n == 0) {
		return 0;
	} else if (cnCache[n] != 0) {
		return cnCache[n];
	}

	integer sum = 0;

	for (integer i = 0; i < k; ++i) {
		sum += a[i] * mwcCache[n - i - 1] + cnCache[n-1];
	}

	cnCache[n] = floor(sum / m);
	return cnCache[n];
}

integer calculateMWCn(integer n, integer k, integer m, integer *a, integer *mwc) {
	if (mwcCache[n] != 0) {
		return mwcCache[n];
	}

	integer cn = calculateCn(n-1, k, m, a, mwc);

	integer sum = 0;
	for (integer i = 0; i < k; ++i) {
		sum += (a[i] * calculateMWCn(n - i - 1, k, m, a, mwc) + cn) % m;
	}

	mwcCache[n] = sum;

	return sum;
}

int main() {
	integer k, m;

	cin >> k;
	cin >> m;

	integer *coefficients = new integer[k];
	integer *mwc = new integer[k];

	for (int i = 0; i < k; ++i) {
		cin >> coefficients[i];
	}

	for (int i = 0; i < k; ++i) {
		cin >> mwc[i];
	}

	integer a, b;
	scanf_s("%I64u-%I64u", &a, &b);

	cnCache = new integer[b+1];
	mwcCache = new integer[b+1];
	for (int i = 0; i <= b; ++i) {
		cnCache[i] = 0;
		mwcCache[i] = 0;
	}

	for (int i = 0; i < k; ++i) {
		mwcCache[i] = mwc[i];
	}

	for (int i = 0; i <= b; ++i) {
		integer res = calculateMWCn(i, k, m, coefficients, mwc);

		if (i < a) {
			continue;
		}

		cout << res;
		if (i != b) {
			cout << " ";
		}
	}

	delete coefficients;
	delete mwc;
	delete cnCache;
	delete mwcCache;
}