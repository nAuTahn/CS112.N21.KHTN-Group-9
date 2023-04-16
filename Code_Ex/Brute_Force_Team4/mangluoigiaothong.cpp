//    OniGirichan
//    Ahihi To Thich Cau :))
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
typedef long long ll;

const int MAXN = 100005;

int n, m;
vector <int> g[MAXN];
bool visited[MAXN];

int BFS_Count_Ver_in_One(int v) {
    visited[v] = true;

    queue <int> q;
    q.push(v);
    int re = 0;
    while(!q.empty()) {
        ++re;
        int tmp = q.front();
        q.pop();
        for (auto & u : g[tmp]) {
            if (!visited[u]) {
                visited[u] = 1;
                q.push(u);
            }
        }
    }

    return re;
}

int ToThichCau() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        g[u].pb(v); g[v].pb(u);
    }

    for (int i = 0; i <= 100003; ++i) visited[i] = 0;

    vector <int> vers_set;

    for (int i = 1; i <= n; ++i)
        if (!visited[i])
            vers_set.pb(BFS_Count_Ver_in_One(i));

    if ((int)vers_set.size() == 1) return cout << 0, 1;

    int ans = 0, cur = 0;

    for (int i = 0; i < (int)vers_set.size(); ++i) {
        ans += cur * vers_set[i];
        cur += vers_set[i];
    }

    return cout << ans, 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int test = 1; //cin >> test;
    while (test--) ToThichCau();

    return 0;
}
