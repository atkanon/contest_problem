#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

void solve() {
  double c, f, x; cin >> c >> f >> x;

  double sum = 0;
  double res = 0;
  int f_cnt = 0;
  double t;

  while (sum < x) {
    if (sum >= c) {
      t = (x-sum) / (2+f*f_cnt);
      if (c <= t*f) {
        f_cnt++;
        sum -= c;
        t = min(c-sum, x-sum) / (2+f*f_cnt);
      } else {
        t = min(c, x-sum) / (2+f*f_cnt);
      }
    } else {
      t = min(c-sum, x-sum) / (2+f*f_cnt);
    }

    sum = sum + t*2 + t*f*f_cnt;
    res += t;

//    cout << t << " " << sum << " " << res << " " << f_cnt << endl;
  }
  printf("%.10f\n", res);
//  cout << res << endl;
}

int main() {
  int t; cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }

  return 0;
}