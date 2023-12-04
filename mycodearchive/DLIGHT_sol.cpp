#include<bits/stdc++.h>
#define fi "input.txt"
#define fo "expected.txt"
#define ll long long
#define pb push_back
#define FOR(i,a,b) for( int i=a;i<=b;i++)
#define FORN(i,a,b) for( int i=a;i<b;i++)
#define FORG(i,a,b) for( int i=a;i>=b;i--)
using namespace std;
const ll oo=1e16;
const int N=1e6+5;

int n,q,res=0;
ll t[4*N],d[4*N],a[N];
struct bg{
	int gt,id;
};
bg b[N];
bool cmp( bg x, bg y)
{
	if(x.gt==y.gt)return x.id<y.id;
	return x.gt<y.gt;
}
void doc(){
    cin>>n>>q;  
}
void update(int k, int l, int r, int u, int v)
{
	if(d[k]>0)
	{
		d[2*k]+=d[k];
		d[2*k+1]+=d[k];
		t[k]+=d[k]*(r-l+1);
		d[k]=0;
	}
	if(r<u||v<l)return;
	if(u<=l&&r<=v){
		t[k]+=(r-l+1);
		d[2*k]+=1;
		d[2*k+1]+=1;
		return;
	}
	int mid=(l+r)>>1;
    update(2*k,l,mid,u,v);
    update(2*k+1,mid+1,r,u,v);
    t[k]=t[2*k]+t[2*k+1];
}
ll get(int k, int l, int r, int u,int v)
{
    if(d[k]>0)
	{
		d[2*k]+=d[k];
		d[2*k+1]+=d[k];
		t[k]+=d[k]*(r-l+1);
		d[k]=0;
	}
	if(r<u||v<l)return 0;
	if(u<=l&&r<=v)return t[k];
	int mid=(l+r)>>1;
	return get(2*k,l,mid,u,v)+get(2*k+1,mid+1,r,u,v);	
}
void xuly()
{
	FOR(i,1,4*n)t[i]=0;
   FOR(i,1,q)
   {
   	int u,v;
   	cin>>u>>v;
   	update(1,1,n,u,v);
   }
   FOR(i,1,n)if(get(1,1,n,i,i)%3==0)res++;
   cout<<res;
}
void sub2()
{
	FOR(i,1,q)
	{
		int u,v;
		cin>>u>>v;
		a[u]++;
		a[v+1]--;
	}
	FOR(i,1,n)
	{
	a[i]=a[i-1]+a[i];
	if(a[i]%3==0)res++;
    }
    cout<<res;
}
void sub4()
{
	FOR(i,1,q)
	{
		int u, v;
		cin>>u>>v;
		b[i]={u,i};
		b[q+i]={v,q+i};
		b[q+i].gt++;
	}
	b[0]={1,0};
	ll dem=0;
	sort(b,b+2*q+1,cmp);
	FOR(i,1,2*q)
	{
		if(dem%3==0)res+=b[i].gt-b[i-1].gt;
		if(b[i].id<=q)dem++;else dem--;
	}
	if(b[2*q].gt<n)res+=n-b[2*q].gt+1;
	cout<<res;
	
}
int main()
{
	if(fopen(fi, "r")){
		freopen( fi, "r" , stdin );
		freopen( fo, "w" , stdout );
	}
	ios_base:: sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	doc();
//	xuly();
//    sub2();
    sub4();

	return 0;
}