#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;
typedef long long LL;

LL circle_sum(LL r, LL k) {
//	LL ans = 2LL*r*k + 2LL*k*k - k;
	LL ans = 2*r + 2*k - 1;
//	cout << ans << endl;
	return ans;
}

LL solve(LL r, LL t)
{
	LL low = -1;
	LL high = 1000000000;
    while ((high-low) > 1) {
        LL mid = (high + low) / 2;
//		LL x = 2*r*mid + 2*(mid*mid) - mid;
//		if (x > t) {
		LL x = 2*r + 2*mid - 1;
		if (mid > 0 && x > t/mid) {
			high = mid;
		} else {
			low = mid;
		}
	}
	return low;
}

LL calc(LL r, LL t) {
//	LL lower = 1;
//	LL upper = 1000000000;
//	LL upper = 1000000;
	LL k, ans;

	LL low = -1;
//	double high = 2000000000;
	LL high = 1000000000;
	LL mid;
	while (high - low > 1) {
		mid = (high + low + 1) / 2;
		//double x = 2.0*r*mid + 2*(double)mid*mid - mid;
		LL x = 2*r + 2*mid - 1;
		if (x > t/mid) {
			high = mid;
		} else {
			low = mid;
		}
	}
	return low;
/*
	while (1) {
		k = (lower + upper) / 2;
		ans = circle_sum(r, k);
		if (ans > t*1.0/k) {
			upper = min(upper-1, k);
		} else {
			lower = max(lower+1, k);
		}
//		cout << lower << " " << k << " " << upper << endl;
		if (lower == upper) break;
	}
	return k;*/
}

int main() {

	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		LL r, t;
		cin >> r >> t;
//		cout << "Case #" << i << ": " << calc(r, t) << endl;
		cout << "Case #" << i << ": " << solve(r, t) << endl;
		if (solve(r, t) != calc(r, t))
			cerr << "Case #" << i << ": correct" << solve(r, t) << " incorrect " << calc(r, t) << endl;
	}

	return 0;

	cout << calc(1, 9) << endl;
	cout << calc(1, 10) << endl;
	cout << calc(3, 40) << endl;
	cout << calc(1, 1000000000000000000LL) << endl;
	cout << calc(10000000000000000LL, 1000000000000000000LL) << endl;


	return 0;

}