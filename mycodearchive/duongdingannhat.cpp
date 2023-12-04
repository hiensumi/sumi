#include <algorithm>
#include <bitset>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define ll long long
#define int long long
#define fi first
#define se second
#define name ""
#define pb push_back
using namespace std;
typedef priority_queue<int, vector<int>, greater<int>> sus;
const int oo = 1000111000;
typedef pair<int, int> ii;
const int MOD = 998244353;
const int base = 1e6 + 5;
inline void add(int &x, int y, int mod = MOD) { x += y; while (x >= mod) x -= mod; while (x < 0) x += mod;}
inline void mul(int &x, int y, int mod = MOD) { x = (x * 1LL * y) % mod;}
inline int prod(int x, int y, int mod = MOD) { return mul(x, y, mod), x;}
inline int sum(int x, int y, int mod = MOD) { return add(x, y, mod), x;}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) mul(ans, x, mod); mul(x, x, mod); y >>= 1;} return ans;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
inline int Div(int x, int y, int mod = MOD) { return prod(x, Inv(y, mod), mod);}
int sub, n, m, inq[base];
struct BigInt {
    string a;
    int sign;
    BigInt(){}
    void operator = (string b) {
        a= (b[0]=='-' ? b.substr(1) : b);
        reverse(a.begin(), a.end());
        (*this).Remove0(b[0]=='-' ? -1 : 1);
    }
    BigInt(string x) {(*this)=x;}
    BigInt(ll x) {(*this)=to_string(x);}
    void operator = (ll x){*this=to_string(x);}

    char operator[](int i){return a[i];}
    int size() {return a.size();}
    BigInt inverseSign() {sign*=-1; return (*this);}

    BigInt Remove0(int newSign) {
        sign = newSign;
        for(int i=a.size()-1; i>0 && a[i]=='0'; i--) a.pop_back();
        if(a.size()==1 && a[0]=='0') sign=1;
        return (*this);
    }

    bool operator == (BigInt x) {return sign==x.sign && a==x.a;}
    bool operator == (string x) {return *this==BigInt(x);}
    bool operator == (ll x)     {return *this==BigInt(x);}
    bool operator != (BigInt x) {return !(*this==x);}
    bool operator != (string x) {return !(*this==x);}
    bool operator != (ll x)     {return !(*this==x);}

    bool operator < (BigInt b) {
        if (sign!=b.sign) return sign<b.sign;
        if(a.size()!=b.size()) return a.size()*sign<b.size()*sign;
        for(int i=a.size()-1; i>=0; i--)
            if(a[i] != b[i]) return a[i]<b[i];
        return false;
    }
    bool operator <  (string x) {return *this<BigInt(x);}
    bool operator <  (ll x)     {return *this<BigInt(x);}
    bool operator <= (BigInt b) {return *this==b || *this<b;}
    bool operator <= (string b) {return *this==b || *this<b;}
    bool operator <= (ll b)     {return *this==b || *this<b;}
    bool operator >  (BigInt b) {return !(*this==b || *this<b);}
    bool operator >  (string x) {return !(*this==x || *this<x);}
    bool operator >  (ll b)     {return !(*this==b || *this<b);}
    bool operator >= (BigInt b) {return *this==b || *this>b;}
    bool operator >= (string b) {return *this==b || *this>b;}
    bool operator >= (ll b)     {return *this==b || *this>b;}

    BigInt operator + (BigInt b) {
        if(sign != b.sign) return (*this)-b.inverseSign();
        BigInt sum;
        for(int i=0, carry=0; i<a.size() || i<b.size() || carry; i++){
            if (i<a.size()) carry+=a[i]-'0';
            if (i<b.size()) carry+=b[i]-'0';
            sum.a += (carry % 10 + 48);
            carry /= 10;
        }
        return sum.Remove0(sign);
    }
    BigInt operator +  (string x) {return *this+BigInt(x);}
    BigInt operator +  (ll x)     {return *this+BigInt(x);}
    // BigInt operator ++ (int) {*this+=1; return *this-1;}
    BigInt operator ++ ()    {*this+=1; return *this;}
      void operator += (BigInt x) {*this = *this+x;}
      void operator += (string x) {*this = *this+x;}
      void operator += (ll x)     {*this = *this+x;}


    BigInt operator - ( BigInt b ) {
        if(sign != b.sign) return (*this)+b.inverseSign();
        if(*this < b) return (b - *this).inverseSign();
        BigInt sub;
        for(int i=0,borrow=0; i<a.size(); i++) {
            borrow = a[i]-borrow-(i<b.size() ? b.a[i] : '0');
            sub.a += borrow>=0 ? borrow+'0' : borrow + 58;
            borrow = borrow>=0 ? 0:1;
        }
        return sub.Remove0(sign);
    }
    BigInt operator - (string x) {return *this-BigInt(x);}
    BigInt operator - (ll x)     {return *this-BigInt(x);}
    // BigInt operator -- (int) {*this-=1; return *this+1;}
    BigInt operator -- ()    {*this-=1; return *this;}
      void operator -= (BigInt x) {*this = *this-x;}
      void operator -= (string x) {*this = *this-x;}
      void operator -= (ll x)     {*this = *this-x;}

    BigInt operator * (BigInt b) {
        BigInt mult("0");
        for(int i=0, k=a[i]; i<a.size(); i++, k=a[i]) {
            while(k-- -'0') mult=mult+b;
            b.a.insert(b.a.begin(),'0');
        }
        return mult.Remove0(sign * b.sign);
    }
    BigInt operator * (string x) {return *this*BigInt(x);}
    BigInt operator * (ll x)     {return *this*BigInt(x);}
      void operator *= (BigInt x) {*this = *this*x;}
      void operator *= (string x) {*this = *this*x;}
      void operator *= (ll x)     {*this = *this*x;}

    BigInt operator / (BigInt b) {
        if(b.size()==1 && b[0]=='0') b.a[0]/=(b[0]-'0');
        BigInt c("0"), d;
        for(int j=0; j<a.size(); j++) d.a += "0";
        int dSign = sign*b.sign; b.sign=1;
        for(int i=a.size()-1; i>=0; i--) {
            c.a.insert(c.a.begin(),'0');
            c=c+a.substr(i,1);
            while(!(c<b)) c=c-b, d.a[i]++;
        }
        return d.Remove0(dSign);
    }
    BigInt operator / (string x) {return *this/BigInt(x);}
    BigInt operator / (ll x)     {return *this/BigInt(x);}
      void operator /= (BigInt x) {*this = *this/x;}
      void operator /= (string x) {*this = *this/x;}
      void operator /= (ll x)     {*this = *this/x;}

    BigInt operator % (BigInt b) {
        if( b.size()==1 && b[0]=='0') b.a[0]/=(b[0]-'0') ;
        BigInt c("0");
        int cSign = sign*b.sign; b.sign=1;
        for( int i=a.size()-1; i>=0; i-- ) {
            c.a.insert( c.a.begin(),'0');
            c = c+a.substr(i,1);
            while(!(c<b)) c=c-b;
        }
        return c.Remove0(cSign);
    }
    BigInt operator % (string x) {return *this%BigInt(x);}
    BigInt operator % (ll x)     {return *this%BigInt(x);}
      void operator %= (BigInt x) {*this = *this%x;}
      void operator %= (string x) {*this = *this%x;}
      void operator %= (ll x)     {*this = *this%x;}

    void print() {
        if(sign==-1) putchar('-');
        for(int i=a.size()-1; i>=0; i--) putchar(a[i]);
    }
    friend istream& operator >>(istream &in,BigInt &x){
        string s; in>>s; x=s; return in;
    }
    friend ostream& operator <<(ostream &out,BigInt &x){
        if(x.sign==-1) putchar('-');
        for(int i=x.size()-1; i>=0; i--)
            putchar(x[i]);
        return out;
    }

    friend BigInt pow(BigInt base, BigInt pw){
        BigInt ans=1;
        while(pw!=0){
            if(pw%2 !=0) ans*=base;
            base*=base, pw/=2;
        }
        return ans;
    }
    friend BigInt pow(BigInt a, BigInt b,BigInt mod) {
        if (b==0) return BigInt(1);
        BigInt tmp=pow(a,b/2,mod);
        if ((b%2)==0) return (tmp*tmp)%mod;
        else return (((tmp*tmp)%mod)*a)%mod;
    }
    friend BigInt sqrt(BigInt x) {
        BigInt ans=x,tmp=(x+1)/2;
        while (tmp<ans) ans=tmp, tmp=(tmp+x/tmp)/2;
        return ans;
    }
    friend BigInt gcd(BigInt a,BigInt b){
        return a%b==0 ? b : gcd(b, a%b);
    }
    friend BigInt lcm(BigInt a,BigInt b){
        return a/gcd(a,b);
    }
};
BigInt dis[base];
vector <ii> adj[base];
void spfa(int s){
    queue <int> q;
    fod(i,1,n) dis[i] = 2e18, inq[i] = false;
    q.push(s);
    dis[s] = 0;
    inq[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (auto v: adj[u]) {
            int to = v.first, w = v.second;
            if (dis[to] > dis[u] + w) {
                dis[to] = dis[u] + w;
                if (!inq[to]) {
                    q.push(to);
                    inq[to] = true;
                }
            }
        }
    }
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	// cout << bpow(2,150000);
	cin >> sub;
	cin >> n >> m;
	fod(i,1,m){
		int u, v;
        BigInt c, d = 2;
		cin >> u >> v >> c;
		c = pow(d,c);
		adj[u].pb({v,c});
		adj[v].pb({u,c});
	}
	int s, t; cin >> s >> t;
	spfa(s);
	if(dis[t] >= (int) 1e18) cout << -1;
	else cout << sum(dis[t],0);
    // cerr << "\nTime: " << clock() << "ms\n";
    return 0;
}
