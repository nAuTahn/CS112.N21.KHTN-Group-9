#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	if (fopen("input.txt", "r")){
		freopen("input.txt","r",stdin);
	}
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i<n; i++){
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	if (n == 0){
		cout << 1;
		return 0;
	}

	for (int r = 1; r<=5000; r++){
		int id = 0, R = 0;
		for (int i = 0; i<m; i++){
			R = a[id] + 2*r;
			while (a[id] <= R && id < n){
				id++;
			}
		}
		if (id >= n) {
			cout << r;
			return 0;
		}
	}

	return 0;
}
