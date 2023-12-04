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
const int N=20+5; ll oo=-1e18,o=1e18;
int xx[]={0,-1,0,1,0,-1,-1,1,1};
int yy[]={0,0,1,0,-1,-1,1,1,-1};
struct point
{
    ll l,r;
};
ll n,dd[N][N],m;
char a[N][N];
int vx[5] ={0,-1,1,0,0};
int vy[5] ={0,0,0,-1,1};
bool check(ll x, ll y)
{
	return (1 <= x and x <= n and 1 <= y and y <= m);
}
void bfs(ll x,ll y)
{
	queue<point>q;
	dd[x][y] = 1;
	q.push({x,y});
	while(!q.empty())
	{
		ll u = q.front().l;
		ll v = q.front().r;
		q.pop();
		FOR(i,1,8)
		{
			ll X = u + xx[i];
			ll Y = v + yy[i];
			if(check(X,Y) and !dd[X][Y] and a[X][Y] != '#')
			{	
				dd[X][Y] = 1;
				q.push({X,Y});
			}
		}
	}
}
ll thu(ll x, ll y)
{
	if(x == 1 and y == 1) return 0;
	if(x == n and y == m) return 0;
	return 1;
}
void reset()
{
	FOR(i,1,n) FOR(j,1,m)
	{
		dd[i][j] = 0;
	}
}
bool nay(int u, int v, int x, int y)
{
	FOR(i,u,x) FOR(j,v,y)
	{
		if(a[i][j] == '#') return 0; 
	}
	return 1;
}
void dam()
{
	cin>>n>>m;
	swap(n,m);
	FOR(i,1,n) FOR(j,1,m)
	{
		cin>>a[i][j];
	}
	if((n == 2 and m == 1) or(n == 1 and m == 2))
	{
		cout<<"Imposible";
		return;
	}
	// reset();
	// bfs(1,1);
	// cout << dd[n][m];
	// if(!dd[n][m])
	// {
	// 	cout<<0;
	// 	return;
	// }
	reset();
	for(int k = 1;k<=min(n,m);k++)
	{
		FOR(i,1,n) FOR(j,1,m)
		{
			if(!thu(i,j)) continue;
			int u = i+k-1;
			int v = j+k-1;
			if(!thu(u,v)) continue;
			if(nay(i,j,u,v) and check(u,v)){
				FOR(q,i,u) FOR(p,j,v)
				{		
					a[i][j] = '#';
				}
				bfs(1,1);
				if(!dd[n][m]){
				 	cout<< k;
				 	return;
				}
				else
				{
					FOR(q,i,u) FOR(p,j,v)
					{
						a[i][j] = '.';
					}
				}
			}
			reset();
		}
	}
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