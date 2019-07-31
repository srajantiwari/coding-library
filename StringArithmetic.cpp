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
inline void print(vector <int> v){for(int i=0;i<v.size();i++)cout<<v[i]<<" ";cout<<endl;}
inline void printrev(vector <int> v){for(int i=v.size()-1;i>=0;i--)cout<<v[i]<<" ";cout<<endl;}
ll MOD=1000000007;
ll INF=1e18+10;

string mul(string s,int x)/////////////////////////////////////multiplies string by a single digit integer x(s>0 & x>0)
{
    string res="";
    int n=s.length(),carry=0;
    for(int i=n-1;i>=0;i--)
    {
        int now=x*(s[i]-'0')+carry;
        if(now>10)
            carry=now/10,now%=10;
        else carry=0;
        res=(char)(now+'0')+res;
    }
    if(carry)
        res=(char)(carry+'0')+res;
    return res;
}

string add(string s1,string s2)////////////////////////////addition of two strings(s1>0 & s2>0)
{
    string x="",y="";
    int xlen=0,ylen=0;
    if(s1.length()>s2.length())
        x=s1,y=s2,xlen=s1.length(),ylen=s2.length();
    else
        x=s2,y=s1,xlen=s2.length(),ylen=s1.length();

    int req=min(xlen,ylen);
    int sum=0,carry=0;
    string res="";
    for(int i=0;i<req;i++)
    {
        int inx=xlen-i-1,iny=ylen-i-1;
        sum=(x[inx]-'0')+(y[iny]-'0')+carry;
        if(sum>9)
            sum-=10,carry=1;
        else carry=0;
        res=(char)(sum+'0')+res;
    }
    for(int i=xlen-req-1;i>=0;i--)
    {
        sum=(x[i]-'0')+carry;
        if(sum>9)
            sum-=10,carry=1;
        else carry=0;
        res=(char)(sum+'0')+res;
    }
    if(carry>0)
        res=((char)(carry+'0'))+res;
    return res;
}

string multiply(string s1,string s2)
{
    bool neg=0;
    if(s1[0]=='-')s1=s1.substr(1),neg=1;
    if(s2[0]=='-')s2=s2.substr(1),neg=1-neg;
    int a=s1.length(),b=s2.length();

    if(s1=="0" || s2=="0")
        return "0";

    vector <int> res(a+b);
    int ia=0;
    for(int i=a-1;i>=0;i--)
    {
        int carry=0,ib=0;
        int a1=s1[i]-'0';
        for(int j=b-1;j>=0;j--)
        {
            int b1=s2[j]-'0';
            int now=(a1*b1+carry+res[ia+ib]);
            carry=now/10;
            res[ia+ib]=now%10;
            ib++;
        }
        if(carry>0)
            res[ia+ib]+=carry;
        ia++;
    }
    for(auto to :res)
        cout<<to;
    cout<<endl;
    string result="";
    for(int i=0;i<(a+b);i++)
        result=(char)(res[i]+'0')+result;
    int in=0;
    for(int i=0;i<(a+b);i++)
    {
        if(result[i]=='0')
            continue;
        else
        {
            in=i;
            break;
        }
    }
    result=result.substr(in);
    if(neg)result='-'+result;
    return result;
}

string divide(string s,int x)///////////////////division of a string s by a single digit x
{
    string res="";
    int n=s.length(),rem=0;
    for(int i=0;i<n;i++)
    {
        int now=(s[i]-'0')+rem*10;
        rem=now%x;now/=x;
        if(i==0 && now==0)continue;
        res=res+(char)(now+'0');
    }
    return res;
}

bool cond(string l,string r)//////////////////compares two strings l and r(returns false if l<r else true)
{
    if(l.length()<r.length())
        return true;
    else if(l.length()==r.length())
        return l.compare(r)>=0 ? false : true;
    else
        return false;
}

int main()
{
    int n;
    while(cin>>n)
    {
        string p;cin>>p;
        string q;cin>>q;
        string res="";
        res=add(p,q);cout<<res<<endl;
        res=multiply(p,q);cout<<res<<endl;
    }
}
