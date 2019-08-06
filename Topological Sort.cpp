#include <bits/stdc++.h>
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
#define pi                  3.14159265359
ll INF=1e18+10;
ll MOD=998244353;

const int N=1e5+10;
vector<int> adj[N];bool vis[N];
vector<int> order;

//Top-sort--------------------------------------------------------------------------------
//if graph is disconnected run dfs for each component separately
void dfs(int v)
{
    vis[v]=true;
    for(auto to : adj[v])
        if(!vis[to])
        dfs(to);
    order.pb(v);    // saves topological sorting in reverse order
}

//---------------------------------------------------------------------------------------

int main()
{
    return 0;
}
