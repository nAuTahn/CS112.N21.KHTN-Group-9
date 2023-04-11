#include <bits/stdc++.h>
#include <unistd.h>
#define llong long long

using namespace std;

mt19937_64 rng(chrono::steady_clock::now()
                   .time_since_epoch()
                   .count()); // 64-bit number generator
                              //
llong mulmod(llong a, llong b, llong m) {
  if (a == 0)
    return 0;
  if (b == 0)
    return 0;

  llong tmp = mulmod(a, b / 2, m);
  tmp = tmp * 2 % m;

  if (b & 1)
    tmp = (tmp + a) % m;
  return tmp;
}

void genTest(int id) {
  string tmp = "bai2//" + to_string(id) + ".inp";
  auto inp_file = tmp.c_str();
  freopen(inp_file, "w", stdout);
  int n = rng() % 10000 + 1;
  cout << n << "\n";
  // if (id == 1)
  //   n = 2;
  // else if (id == 2)
  //   n = 2;
  // else if (id == 3)
  //   n = 1e5;

  int MAX = 1e9;
  for (int i = 0; i < n; i++) {
    int query_type = rng() % 2 + 1;
    int a = rng() % MAX + 1, b = rng() % MAX + 1, c = rng() % MAX + 1;
    // if (n == 1)
    //   a = b = c = 1;
    cout << query_type << " " << a << " " << b << " " << c << "\n";
  }
}

int main() {
  // ios_base::sync_with_stdio(0);
  // cin.tie(NULL);

  for (int i = 1; i <= 50; i++) {
    genTest(i);
    sleep(1);
    string tmp = "bai2//" + to_string(i) + ".inp";
    auto inp_file = tmp.c_str();
    auto tmp2 = "bai2//" + to_string(i) + ".out";
    auto out_file = tmp2.c_str();
    freopen(inp_file, "r", stdin);
    freopen(out_file, "w", stdout);

    int q;
    cin >> q;
    while (q--) {
      int type;
      llong a, b, c;
      cin >> type >> a >> b >> c;
      if (type == 1)
        cout << mulmod(a, b, c) << '\n';
      else {
        llong gcd = __gcd(b, c);
        llong del = b / gcd;
        if (del > a / c)
          cout << min(b, c) - 1 << '\n';
        else {
          del *= c;

          llong num = a / del;
          llong ans = num * min(b, c);
          ans += min({b, c, a - num * del + 1});
          --ans;

          cout << ans << '\n';
        }
      }
    }
    sleep(1);
  }

  return 0;
}
