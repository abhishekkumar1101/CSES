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
 // dp[i][j] -> operation require to transform s (till i length) to t (till j length)
void solve(){
 string s,t;
 cin>>s>>t;
 int n = s.length(),m=t.length();
 int dp[n+1][m+1];
 for(int i = 0;i<=n;i++){
    for(int j = 0;j<=m;j++){
        if(i==0){ // string s is empty
            dp[i][j] = j;
        }
        else if(j==0) { // string t is empty
            dp[i][j] = i;
        }
        else if(s[i-1]==t[j-1]){
            dp[i][j]=dp[i-1][j-1];
        }
        else{
            dp[i][j] = min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j]))+1;
        }
       // cout<<dp[i][j]<<" ";
    }
    //cout<<"\n";
 }
 cout<<dp[n][m];

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