#include <bits/stdc++.h>
using namespace std;

vector<pair<int,string>> a(9);

int calc(vector<int> trafficLight, int i){
	int cnt = 9;
	int ret = 0;
	while (--cnt >= 0){
		int tmp = i%3;
		i/=3;
		ret += a[cnt].first * tmp;
		for (char ch : a[cnt].second){
			int pos = ch - '1';
			trafficLight[pos] = (trafficLight[pos] + tmp)%3;
		}
	}
	bool flag = true;
	for (int i = 0; i<9; i++){
		if (trafficLight[i] != 0) flag = false;
	}
	if (flag) return ret;
	else return 0;

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	if (fopen("input.txt", "r")){
		freopen("input.txt","r",stdin);
	}

	for (int i = 0; i<9; i++){
		cin >> a[i].first >> a[i].second;
	}

	string s;
	cin >> s;
	vector<int> trafficLight(9);
	for (int i = 0; i<9; i++){
		if (s[i] == 'X') trafficLight[i] = 0;
		if (s[i] == 'V') trafficLight[i] = 1;
		if (s[i] == 'D') trafficLight[i] = 2;
	}

	int MAX = pow(3,9);
	int ans = INT32_MAX;
	for (int i = 0; i<MAX; i++){
		int tmp = calc(trafficLight,i);
		if (tmp){
			ans = min(ans,tmp);
		};
	}
	if (ans == INT32_MAX) cout << -1;
	else cout << ans;
	return 0;
}
