#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
typedef long long ll;

#define mem(dp,a)           memset(dp,a,sizeof dp)
#define rep(i,a,b)          for(ll i=a;i<b;i++)
#define pb(x)               push_back(x)
#define mp(x,y)             make_pair(x,y)
#define fastio              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F                   first
#define S                   second
#define all(v)              (v).begin(),(v).end()
#define pi					3.14159265359
ll INF=1e18+10;
ll MOD=1000000007;

const int N=1e5+10;
vector <int> adj[N];
bool vis[N];

void dfs(int v)
{
    cout<<v<<" ";
    vis[v]=true;
    for(auto to : adj[v])
        if(!vis[to])
            dfs(to);
}

int main()
{
    int n,m;cin>>n>>m;   // Enter number of vertices and edges
    rep(i,0,m)
    {
        int a,b;cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    rep(i,1,n+1)
    {
        if(!vis[i])
            dfs(i);
    }
}

// Input :
// 6 5
// 1 2
// 1 3
// 1 4
// 2 5
// 2 6
// Output :
// 1 2 5 6 3 4
