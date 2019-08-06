//RSQ Implementation
#include<bits/stdc++.h>
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

const int N=3*1e4+10;
int segt[4*N];

void build(int v,int tl,int tr,int a[])
{
    if(tl==tr)segt[v]=a[tl];
    else
    {
        int mid=(tl+tr)>>1;
        build(v<<1,tl,mid,a);
        build(1+(v<<1),mid+1,tr,a);
        segt[v]=segt[v<<1]+segt[1+(v<<1)];
    }
}

void update(int v,int tl,int tr,int tar)
{
    if(tl==tar && tar==tr)segt[v]=1;
    else
    {
        int mid=(tl+tr)>>1;
        if(tar<=mid)update(v<<1,tl,mid,tar);
        else update(1+(v<<1),mid+1,tr,tar);
        segt[v]=(segt[v<<1]+segt[1+(v<<1)]);
    }
}

int solve(int v,int tl,int tr,int l,int r)
{
    if(tr<l || tl>r)return 0;
    else if(l<=tl && tr<=r)return segt[v];
    else
    {
        int mid=(tl+tr)>>1;
        int p1=solve(v<<1,tl,mid,l,r);
        int p2=solve(1+(v<<1),mid+1,tr,l,r);
        return p1+p2;
    }
}

int main()
{
    fastio;
    int n;cin>>n;
    int a[n];
    rep(i,0,n)cin>>a[i];

    build(1,0,n-1,a);
    int q;cin>>q;
    while(q--)
    {
        int l,r;cin>>l>>r;
        l--,r--;
        cout<<solve(1,0,n-1,l,r)<<endl;
    }
}
