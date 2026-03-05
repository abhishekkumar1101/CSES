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
int arr[n+1],idx[n+2];
for(int i =1;i<=n;i++) cin>>arr[i],idx[arr[i]]=i;
int ans = 1;
idx[0] = 0,idx[n+1]=n+1;
for(int i = 1;i<=n;i++){
    if(idx[i-1]>idx[i]) ans++;
}
//cout<<ans<<" ";
while(m--){
    int a,b;
    cin>>a>>b;
    int cnt = 0;
    if(a>b) swap(a,b);
    // if(a==b){
    //     cout<<ans<<"\n";
    //     continue;
    // }
    int numa = idx[arr[a]];
    int numb = idx[arr[b]];
    //cout<<numa<<" "<<numb<<"\n";
    swap(idx[arr[a]],idx[arr[b]]);

    if(abs(arr[a]-arr[b])==1){
        if(arr[a]<arr[b]){
            cnt++;
        if(idx[arr[a]-1]>numa){
                    if(idx[arr[a]-1]<idx[arr[a]]) cnt--;
                } 
        else {
                if(idx[arr[a]-1]>idx[arr[a]]) cnt++;
            }
            
            if(idx[arr[b]+1]>numb){
                if(idx[arr[b]+1]<idx[arr[b]]) cnt++;
            }
            else{
                if(idx[arr[b]+1]>idx[arr[b]]) cnt--;
            }
        }
        else{
            cnt--;
            if(idx[arr[b]-1]>numb){
                if(idx[arr[b]-1]<idx[arr[b]]) cnt++;
            } 
            else 
            {
                if(idx[arr[b]-1]>idx[arr[b]]) cnt++;
            }
            //cout<<cnt<<" ";

                if(idx[arr[a]+1]>numa){
                    if(idx[arr[a]+1]<idx[arr[a]]) cnt++;
                }
                else{
                    if(idx[arr[a]+1]>idx[arr[a]]) cnt--;
                }
            } 
    }
    else{
            // both prev

            //for a
            if(idx[arr[a]-1]>numa){
                if(idx[arr[a]-1]<idx[arr[a]]) cnt--;
            }
            else{
                if(idx[arr[a]-1]>idx[arr[a]]) cnt++;
            }
            // for b
              if(idx[arr[b]-1]>numb){
                if(idx[arr[b]-1]<idx[arr[b]]) cnt--;
            }
            else{
                if(idx[arr[b]-1]>idx[arr[b]]) cnt++;
            }


            // both next

            // for a
            if(idx[arr[a]+1]<numa){
                if(idx[arr[a]+1]>idx[arr[a]]) cnt--;
            }
            else{
                if(idx[arr[a]+1]<idx[arr[a]]) cnt++;
            }


            // for b

             if(idx[arr[b]+1]<numb){
                if(idx[arr[b]+1]>idx[arr[b]]) cnt--;
            }
            else{
                if(idx[arr[b]+1]<idx[arr[b]]) cnt++;
            }
    }
    swap(arr[a],arr[b]);
    ans+=cnt;
    cout<<ans<<"\n";
}

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
