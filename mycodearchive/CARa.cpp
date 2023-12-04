#define TASK ""
#include<bits/stdc++.h>
using namespace std; 

bool tachi =  0 ;
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0);  srand(time(0)) ;
#define ll long long 
#define db long double
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll> 
#define tll map<ll,ll>
#define pb push_back 
#define pk pop_back 
#define FOR(i,a,b) for(int i =a ;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FORN(i,a,b) for(int i= a ;i<b;i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a);
#define print(a) for(auto  v : a )cout<<v<<" ";cout<<'\n';
#define el '\n' 
ll sq(ll a){return a*a;}  
    void tep()
    {
        fast 
        if(fopen(TASK".INP","r")) freopen(TASK".INP","r",stdin) , freopen(TASK".OUT","w",stdout);
    }
const int N=1e6+5; ll oo=-1e18,o=1e18;
int xx[]={0,-1,0,1,0,-1,-1,1,1};
int yy[]={0,0,1,0,-1,-1,1,1,-1};
struct point
{
    ll x,y;
};
ll DT(point A,point B,point C)
{
    return abs((B.x-A.x)*(C.y-B.y)-(C.x-B.x)*(B.y-A.y));
}
ll n,k,s,t,b[N];
point a[N];
bool check(ll w)
{
	ll h = 0;
	for(int i = 1;i<=k+1;i++)
	{
		ll kc = b[i] - b[i-1];
		if(w<kc) return 0;
		h+=2*kc -(w-kc); 
	}
	return h<=t;
}
ll cnp()
{
	ll ans = -1;
	ll l = 0;
	ll r = 2*1e9 ;
	while(l<=r)
	{
		int mid = (l+r)/2;
		if(check(mid))
		{
			ans = mid;
			l = mid+1;
		}
		else
		{
			r = mid-1;
		}
	}
	return ans;
}
ll CNP()
{
	ll d = 0;
	ll c = 2e9;
	while(d+1<c)
	{
		ll mid = (d+c)/2;
		if(check(mid))
		{
			c = mid;
		}
		else d = mid;
	}
	if(check(d)) return d;
	if(check(c)) return c;
}
void dam()
{
	cin>>n>>k>>s>>t;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>b[i];
	}
	sort(b+1,b+1+k);
	b[0] = 0;
	b[k+1] = s;
	ll w = CNP();
	ll res = o;
	for(int i=1;i<=n;i++)
	{
		if(a[i].y>w)
		{
			res = min(res,a[i].x);
		}
	}
	if(res == o) cout<< -1;
	else cout<<res;
}
void da()
{

}
int main()
{
    tep() ; 
    int test =1 ; 
    if(tachi)cin>>test;
    while(test--)
    {
        dam() ; 
        da() ;
    }
    cerr<<"Time:"<<" "<<clock()<<"ms"<<el;
}