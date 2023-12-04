#define lmao ""
#include<bits/stdc++.h>
#define forgor(i,a,b) for(int i=a; i<=b; i++)
#define rember(i,a,b) for(int i=a; i>=b; i--)
#define ll long long
#define db double
#define N 1<<20
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
const bool kys=true,nhieutest=false;
ll n,a[N],res;
unordered_map<ll,ll> m;
void doc(){
	cin>>n;
	forgor(i,1,n) cin>>a[i],m[a[i]]++;
}
bool check(int x,int y,int z){
	if(x==y) return 1;
	if(y==z) return 1;
	if(x==z) return 1;
	return 0;
}
void hello(){
	ll tmp=0;
	forgor(i,1,n){
		if(m[a[i]]>=2) res+=m[a[i]]*(m[a[i]]-1)/2*(n-m[a[i]])+(m[a[i]])*(m[a[i]]-1)*(m[a[i]]-2)/6,m[a[i]]=0;
	}
	forgor(i,1,n) forgor(j,i+1,n) forgor(k,j+1,n) if(check(a[i],a[j],a[k])) tmp++;
	cout<<tmp;
}
int main(){
    ishowspeed;
	if(kys){
    freopen(lmao".inp", "r", stdin);
    freopen(lmao".ans", "w", stdout);
	}
	ll t=1;
	if(nhieutest) cin>>t;
	while(t--){
		doc(); hello();
		cout<<endl;
	}
	return 0;
}