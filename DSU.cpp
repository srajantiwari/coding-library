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
#define pi                  3.14159265359
ll INF=1e18+10;
ll MOD=1000000007;

const int N=1e5+10;

//DSU---------------------------------------------------------------------------------------

int sizz[N],parent[N];

void make_set(int v)
{
    if(parent[v]==0)
        parent[v]=v,sizz[v]=1;
}

int find_set(int v)
{
    if(v==parent[v])
        return v;
    return parent[v]=find_set(parent[v]);
}

void union_sets(int a,int b)
{
    a=find_set(a),b=find_set(b);
    if(a!=b)
    {
        if(sizz[a]<sizz[b])
            swap(a,b);
        parent[b]=a;
        sizz[a]+=sizz[b];
    }
}

//--------------------------------------------------------------------------------------------

int main()
{
	int n;cin>>n;
	int a[n];
	rep(i,0,n)
	{
		cin>>a[i];
		make_set(a[i]); // Always do this for DSU
	}

    rep(i,2,n)
		i&1 ? union_sets(a[0],a[i]) : union_sets(a[1],a[i]);

    rep(i,0,n)
		cout<<find_set(a[i])<<endl;
}
