#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
//#define for(i, n) for (int i = 0; i < n; i++)
//#define for(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, false, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define mod 1000000007
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
vector<int> SieveOfEratosthenes(int n,vector<int>&pnum){
vector<bool> prime(n + 1, true);
for (int p = 2; p * p <= n; p++) {
if (prime[p] == true) {
for (int i = p * p; i <= n; i += p)
prime[i] = false;
}
}
for (int p = 2; p <= n; p++){
if (prime[p]) pnum.push_back(p);
}
return pnum;
} 
int dp[200005][2];
vector<int> adj[200005];
void dfs(int src,int par){
    bool leaf = 1;
    dp[src][0]=0;
    dp[src][1]=0;
    for(auto child:adj[src]){
        if(child!=par){
           leaf = 0;
           dfs(child,src); 
        }
    }
    if(leaf) return;
    for(auto child:adj[src]){
        if(child!=par){
            dp[src][0]+=max(dp[child][0],dp[child][1]);
        }
    }
    for(auto child:adj[src]){
        if(child!=par){
            dp[src][1] = max(dp[src][1],1+dp[child][0]+(dp[src][0]-max(dp[child][0],dp[child][1])));
        }
    }
}
void solve(){
 int n;
cin>>n;


for(int i = 0;i<n-1;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
   adj[v].push_back(u); 
}
dfs(1,0);
cout<<max(dp[1][0],dp[1][1]);

 

}
 
 
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
int t=1;

while (t--){
solve();
}
return 0;
}