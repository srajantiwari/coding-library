#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define mem(dp,a)           memset(dp,a,sizeof dp)
#define rep(i,a,b)          for(ll i=a;i<b;i++)
#define repb(i,a,b)         for(ll i=a;i>=b;i--)
#define pb(x)               push_back(x)
#define mp(x,y)             make_pair(x,y)
#define tr(c,it)            for(auto const &it : c)
#define xlr8                ios_base::sync_with_stdio(false);cin.tie(NULL)
#define sz(c)               (c).size()
#define all(c)              (c).begin(),(c).end()
#define sl(a)               scanf("%lld",&a);
#define TH                  1000
#define F                   first
#define S                   second
ll MOD=pow(10,9)+7;//998244353
ll INF=1e18+10;

const int N=10005;
vector <pair<ll,ll>> adj[N];
ll d[N];
ll n,m;

void dijkstra(int s)
{
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
    q.push(mp(s,0));

    d[s]=0;
    while(!q.empty())
    {
        ll v=q.top().F;
        ll dist=q.top().S;
        q.pop();
        
        if(dist>d[v])
            continue;
        
        if(d[v]==INF)
            break;
        
        for(auto edge : adj[v])
        {
            ll to=edge.F;
            ll len=edge.S;
            if(d[to]>(d[v]+len))
            {
                d[to]=d[v]+len;
                q.push(mp(to,d[to]));
            }
        }
    }

}

int main()
{
    xlr8;
    int t;cin>>t;
    while(t--)
    {
        rep(i,1,N)
        d[i]=INF;
        cin>>n>>m;
        rep(i,0,m)
        {
            int a,b,c;cin>>a>>b>>c;
            adj[a].pb(mp(b,c));
        }
        int a,b;cin>>a>>b;

        dijkstra(a);
        d[b]!=INF ? cout<<d[b]<<endl : cout<<"NO\n";
        rep(i,0,n+1)
        adj[i].clear();

    }
}
