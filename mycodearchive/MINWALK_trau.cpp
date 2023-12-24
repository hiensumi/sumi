#include<bits/stdc++.h>
using namespace std;
 
#define sd(mark) scanf("%d",&mark)
#define ss(mark) scanf("%s",mark)
#define sl(mark) scanf("%lld",&mark)
#define debug(mark) printf("check%d\n",mark)
#define clr(mark) memset(mark,0,sizeof(mark))
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ll long long
#define N 100010
#define INF 1e17
int mark[N];
vector<pair<int,ll> > v[N];
ll d[N],d_x[N],d_y[N],d_z[N];
void dijkstra(int st)
{
	int i;
	int cur;
	for(i=0;i<N;++i)
	{
		mark[i]=0;
		d[i]=INF;
	}
	priority_queue<pair<ll,int> > q;

	d[st]=0;
	q.push(MP(0,st));
	while(!q.empty())
	{
		pair<ll,int> p=q.top();
		cur=p.S;
		q.pop();
		if(!mark[cur])
		{
			mark[cur]=1;
			for(i=0;i<v[cur].size();++i)
			{
				if(d[v[cur][i].F]>(d[cur]+v[cur][i].S))
				{
					d[v[cur][i].F]=(d[cur]+v[cur][i].S);
					q.push(MP(-d[v[cur][i].F],v[cur][i].F));
				}
			}
		}
	}
}
// map<pair<int,int>,int> mapp;
int main()
{
	int t;
	// freopen("11.in","r",stdin);
	// freopen("11.out","w",stdout);
	clock_t start = clock();
	
	sd(t);
	assert(t>=1 && t<=5);
	while(t--)
	{
		// mapp.clear();
		int n,m,i,j,x,y,z;
		
		sd(n);sd(m);
		assert(n>=2 && n<=100000 && m>=(n-1) && m<=100000);
		
		for(i=0;i<=n;++i)
			v[i].clear();
		
		sd(x);sd(y);sd(z);
		assert(x>=1 && x<=n && y>=1 && y<=n && z>=1 && z<=n);

		for(i=0;i<m;++i)
		{
			int x,y,z;
			sd(x);sd(y);sd(z);
			assert(x>=1 && x<=n && y>=1 && y<=n && x!=y);
			// assert(mapp[MP(x,y)]==0);
			v[x].PB(MP(y,z));
			v[y].PB(MP(x,z));
			// mapp[MP(x,y)]=mapp[MP(y,x)]=1;
		}
		dijkstra(x);
		for(i=1;i<=n;++i)
		{
			d_x[i]=d[i];
			assert(d_x[i] < INF-10);
		}
		dijkstra(y);
		for(i=1;i<=n;++i)
			d_y[i]=d[i];
		dijkstra(z);
		for(i=1;i<=n;++i)
			d_z[i]=d[i];

		ll ans=INF;
		for(i=1;i<=n;++i)
			ans=min(ans,d_x[i]+d_y[i]+d_z[i]);
		if(ans > INF-10)
			ans=-1;
		assert(ans!=-1);
		printf("%lld\n",ans);
	}
	clock_t end = clock();
	cerr <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
}