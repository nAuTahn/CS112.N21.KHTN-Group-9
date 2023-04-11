//    OniGirichan
//    Ahihi To Thich Cau :))
#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

#define ll long long
#define pb push_back
#define po pop_back
#define rand rd

string NAME = "bai1";

mt19937_64 rng(high_resolution_clock::now().time_since_epoch().count());

ll randLL(ll n) {
    return uniform_int_distribution<ll> (0, n - 1)(rng);
}

class bigNum {
    public:
        string a;
        bigNum(string a) : a(a) {}

        bigNum operator + (bigNum other) {
            string b = other.a;
            if ((int)a.size() > (int)b.size()) swap(a, b);
            string c;
            int carry = 0;
            for (int i = (int)a.size() - 1; i >= 0; --i) {
                int tmp = (a[i] - '0') + (b[i + (int)b.size() - (int)a.size()] - '0') + carry;
                c.pb(tmp % 10 + '0');
                carry = tmp / 10;
            }

            for (int i = (int)b.size() - (int)a.size() - 1; i >= 0; --i) {
                int tmp = (b[i] - '0') + carry;
                c.pb(tmp % 10 + '0');
                carry = tmp / 10;
            }

            if (carry) c.pb(carry + '0');
            reverse(c.begin(), c.end());

            return bigNum(c);
        }

        bigNum operator * (bigNum other) {
            string b = other.a;
            string c((int)a.size() + (int)b.size(), 0);

            for (int i = (int)a.size() - 1; i >= 0; --i)
            for (int j = (int)b.size() - 1; j >= 0; --j) {
                int dig = (a[i] - '0') * (b[j] - '0') + c[i + j + 1];
                c[i + j + 1] = dig % 10;
                c[i + j] += dig / 10;
            }

            for (int i = 0; i < (int)c.size(); ++i) c[i] += '0';
            if (c[0] == '0') return c.substr(1);

            return bigNum(c);
        }

        bigNum operator ^ (int y) {
            if (y == 0)
                return bigNum("1");
            bigNum tmp = (*this)^(y/2);
            if (y % 2 == 0) return tmp * tmp;
            return (*this) * tmp * tmp;
        }
};


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    for (int t = 1; t <= 100; ++t) {
        string thisName = NAME + to_string(t);
        cerr << thisName;
        ofstream inp((NAME + to_string(t) + "inp.txt").c_str());
        ofstream out((NAME + to_string(t) + "out.txt").c_str());
        cerr << '\n';
        inp << t;
        for (int i = 1; i <= t; ++i) {
            int a = randLL(998) + 2, b = randLL(998) + 2;
            bigNum A = bigNum(to_string(a)), B = bigNum(to_string(b));

            inp << "\n" << a << " " << b;
            A = A ^ b;
            B = B ^ a;
            out << (A + B).a << "\n";
        }
    }

    return 0;
}
