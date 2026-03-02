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
 vector<int> adj[200005],parent(200005),ans(200005),depth(200005);
 int farthestNode=0,maxdist=0;
 void farthestNodedfs(int src,int prev,int dist){
    if(dist>maxdist){
        maxdist=dist;
        farthestNode = src;
    }
    for(auto it:adj[src]){
        if(it!=prev){
            farthestNodedfs(it,src,dist+1);
        }
    }
 }
vector<int> getDistances(int src, int n){
    vector<int> dist(n+1, -1);
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v: adj[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

void eval_depth(int src,int prev){
    int max_depth = 0;
    for(auto child:adj[src]){
        if(child!=prev){
            eval_depth(child,src);
            max_depth = max(max_depth,1+depth[child]);
        }
        depth[src]=max_depth;
    }
}

void solve(int src,int prev,int par_ans){
    vector<int> prefixMax,suffixMax;
    for(auto child:adj[src]){
        if(child==prev) continue;
        prefixMax.push_back(depth[child]);
        suffixMax.push_back(depth[child]);
    }
    for(int i = 1;i<prefixMax.size();i++) prefixMax[i] = max(prefixMax[i],prefixMax[i-1]);
    for(int i = (int)suffixMax.size()-2;i>=0;i--) suffixMax[i] = max(suffixMax[i],suffixMax[i+1]);
    int c_no = 0;
    for(auto child:adj[src]){
        if(child!=prev) {
            int op1 = (c_no==0)?INT_MIN:prefixMax[c_no-1];
            int op2 = (c_no==suffixMax.size()-1)?INT_MIN:suffixMax[c_no+1];
            int partial_ans = 1+max(par_ans,max(op1,op2));
            solve(child,src,partial_ans);
            c_no++;
        }
    }
    ans[src] = 1+max(par_ans,(prefixMax.empty()?-1:prefixMax.back()));

}
void solve(){
 int n;
cin>>n;
for(int i = 0;i<n-1;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
   adj[v].push_back(u);
      parent[v]=u;  
}
if(n==1){
    cout<<"0";
    return;
}
// farthestNodedfs(1,-1,0);
// int farthestNode1 = farthestNode;
// maxdist=0;
// farthestNodedfs(farthestNode,-1,0);
// int farthestNode2 = farthestNode;
// vector<int>endpoint1 = getDistances(farthestNode1,n);
// vector<int>endpoint2 = getDistances(farthestNode2,n);
// for(int i =1;i<=n;i++) ans[i] = max(endpoint1[i],endpoint2[i]);
eval_depth(1,0);
solve(1,0,-1);
for(int i =1;i<=n;i++) cout<<ans[i]<<" ";




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