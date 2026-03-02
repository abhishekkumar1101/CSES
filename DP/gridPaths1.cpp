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
 int n;
cin>>n;
vector<vector<char>> grid(n,vector<char>(n));
for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++) cin>>grid[i][j];
}
vector<vector<int>> dp(n,vector<int>(n));
ll int md = 1e9+7;
for(int i=n-1;i>=0;i--){
    for(int j = n-1;j>=0;j--){
        if(grid[i][j]!='*'){
            if(i==n-1 && j==n-1) dp[i][j] = 1;
            else if(i==n-1) dp[i][j] = (dp[i][j]+dp[i][j+1])%md;
            else if(j==n-1) dp[i][j] = (dp[i][j]+dp[i+1][j])%md;
            else dp[i][j] = (dp[i][j]+dp[i+1][j]+dp[i][j+1])%md;
        }
    }
}
cout<<dp[0][0];
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