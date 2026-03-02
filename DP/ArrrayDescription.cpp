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
 
void solve(){
 int n,m;
cin>>n>>m;
int arr[n+1];
for(int i =1;i<=n;i++) cin>>arr[i];
 ll dp[n+1][m+2];
    memset(dp, 0, sizeof(dp));

    if(arr[1] == 0){
        for(int j = 1; j <= m; j++)
            dp[1][j] = 1;
    }
    else{
        dp[1][arr[1]] = 1;
    }

for(int i = 2;i<=n;i++){
    for(int j = 1;j<=m;j++){
            if(arr[i]==0){
                dp[i][j] = dp[i-1][j-1]%mod+dp[i-1][j]%mod+dp[i-1][j+1]%mod;
            }
            else{
                dp[i][arr[i]] = dp[i-1][arr[i]-1]%mod+dp[i-1][arr[i]]%mod+dp[i-1][arr[i]+1]%mod;
            }
        }
}
ll int ans = 0;
for(int i = 1;i<=m;i++){
    ans = (ans%mod+dp[n][i]%mod)%mod;
}
cout<<ans;
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