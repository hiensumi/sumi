#define lmao ""
#include<bits/stdc++.h>
#define forgor(i,a,b) for(int i=a; i<=b; i++)
#define rember(i,a,b) for(int i=a; i>=b; i--)
#define ll long long
#define db double
#define N 100005
#define N2 1000+5
#define big 1e16
#define small -1e16
#define pb push_back
#define endl '\n'
#define ishowspeed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mask(i) (1LL<<(i))
using namespace std;
bool maximize(ll &x, const ll &y) {
	if(x<y){
		x=y; return true;
	} else return false;
}
bool minimize(ll &x, const ll &y) {
	if(x>y){
		x=y; return true;
	} else return false;
}
typedef priority_queue<int,vector<int>,greater<int>> sup;
typedef priority_queue<int,vector<int>> yo;
typedef vector<int> vt;
const int sm=1e9+7;
inline void add(int &x,int y,int mod){x+=y;while(x>=mod) x-=mod;while(x<0) x+=mod;}
inline void mul(int &x,int y,int mod){x=(x*1LL*y)%mod;}
inline ll prod(int x,int y,int mod){ return mul(x,y,mod),x;}
inline ll sum(int x,int y,int mod){return add(x,y,mod),x;}
inline ll bpow(int x,int y,int mod){ int ans = 1; while(y){if(y&1) mul(ans,x,mod);mul(x,x,mod);y>>=1;} return ans;}
inline ll gcd(ll a,ll b){return __gcd(a,b);}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
struct bg{
	ll x;
	ll y;
};
bool cmp(int a,int b){
	 return a>b;}
bool cmp1(bg a,bg b){
	 return a.x<b.x;}
bool cmp2(bg a,bg b){
	 return a.y<b.y;}
const bool kys=false,nhieutest=false;
ll n,f[N],d[N];
string s;
void doc(){
	cin>>s;
	n=s.size();
	s="#"+s;
}
ll check(int k){
	forgor(i,1,26) d[i]=0,f[i]=0;
		forgor(j,1,k){
			int x=s[j]-'a'+1;
			d[x]++;
	}
//	cout<<d[2]<<" ";
	for(int i=k+1;i<=n;i+=k){
		forgor(j,i,i+k-1) f[s[j]-'a'+1]++;
		forgor(x,1,26) if(f[x]!=0) if(f[x]!=d[x]) return 0;
		forgor(x,1,26) f[x]=0;
	}
	return 1;
}
vt v;
ll gg[N];
void hello(){
	ll res=1;
//	cout<<s[1]-'a';
	forgor(i,1,n) gg[s[i]-'a'+1]++;
	if(gg[s[1]-'a'+1]==n){
		cout<<n;
		return ;
	}
	forgor(i,2,n-1) if(n%i==0) v.pb(i);
	for(int x:v) if(check(x)){
		cout<<n/x;
		return ;
	}
	cout<<res;
}
int main(){
    ishowspeed;
	if(kys){
    freopen(lmao".inp", "r", stdin);
    freopen(lmao".out", "w", stdout);
	}
	ll t=1;
	if(nhieutest) cin>>t;
	while(t--){
		doc(); hello();
		cout<<endl;
	}
	return 0;
}