#include<bits/stdc++.h>
#include<iostream>
#define fok(i,a,b)	for(int i=a;i<=b;i++)
#define pb push_back
using namespace std;
using ll=long long;
using db=double;
const int maxn=1e6+5;
const int ma=3005;
typedef pair<int,int> Vector;
struct bg{
	int x,y;
};
struct point{
	int a,b,c;
};
ll n,m,res=0,stt=0,num[maxn],low[maxn],dd[maxn],tp[maxn];
stack<int> s;
vector<int> g[maxn];
void dfs(int u){
	stt++;
	num[u]=stt,low[u]=stt;
	s.push(u);
	for(int v:g[u]) if(dd[v]==0){
		if(num[v]!=0)	low[u]=min(low[u],num[v]);
		else {
			dfs(v);
			low[u]=min(low[u],low[v]);
		}
	}
	ll x;
	if(low[u]==num[u]){
		res++;
		do {
			x=s.top();
			s.pop();
			tp[x]=res;
			dd[x]=1;
		} while(x!=u);
	}
}
void inp(){
	cin>>n>>m;
	fok(i,1,m){
		ll u,v;
		cin>>u>>v;
		g[u].pb(v);
	}
}
void solve(){
	fok(i,1,n)	if(num[i]==0)	dfs(i);
	// fok(i,1,n){
	// 	cout << tp[i] << endl;
	// }
	cout << res;
}
int main(){
	freopen(".INP", "r", stdin);
   freopen(".OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	inp(),solve();
}