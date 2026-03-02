#include <bits/stdc++.h>
using namespace std;
#define ll long long

constexpr int N = 2e5;
vector<int> adj[N+1];
vector<ll> subans(N+1, 0), cnt(N+1, 0), ans(N+1, 0);

void preCal(int node, int prev) {
    ll int numofNodes = 1;
    ll int ansForSubtree = 0;
    for (int it : adj[node]) {
        if (it == prev) continue;
        preCal(it, node);
        numofNodes+= cnt[it];
        ansForSubtree+= subans[it] + cnt[it];
    }
    cnt[node] = numofNodes;
    subans[node] = ansForSubtree;
}

void dfs(int node, int prev, int n) {
    ans[node] = subans[node];
    for (int it : adj[node]) {
        if (it == prev) continue;
        ll int partial_ans = ans[node]-(subans[it]+cnt[it]);
        ans[it] =subans[it]+partial_ans+(n-cnt[it]);
        dfs(it, node, n);
    }
}

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        cnt[i] = subans[i] = ans[i] = 0;
    }

    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    preCal(1, 0);
    ans[1] = subans[1];
    dfs(1, 0, n);

    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
