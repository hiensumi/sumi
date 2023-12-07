
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1005;
int G[maxn][maxn],C[maxn*100];
int A,B,m,dy[2][maxn][maxn],ans;
int u[maxn*100],v[maxn*100],c[2];
 
void dfs(int a,int b,int x,int y,int now,int pre){
	if(now==pre){ dy[a][x][now]=y,dy[b][y][now]=x; return;}
	
	int to=dy[b][y][now];
	dy[a][x][now]=y,dy[b][y][now]=x;
	
	if(!to) dy[b][y][pre]=0;
	else dfs(b,a,y,to,pre,now);
}
 
int main(){
	scanf("%d%d%d",&A,&B,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",u+i,v+i);
		G[u[i]][v[i]]=i;
	}
	
	for(int i=1;i<=m;i++){
		c[0]=c[1]=1;
		while(dy[0][u[i]][c[0]]) c[0]++;
		while(dy[1][v[i]][c[1]]) c[1]++;
		ans=max(ans,max(c[0],c[1]));
		dfs(0,1,u[i],v[i],c[0],c[1]);
	}
	
	for(int i=1;i<=A;i++)
	    for(int j=1;j<=ans;j++) if(dy[0][i][j]) C[G[i][dy[0][i][j]]]=j;
	
	printf("%d\n",ans);
	for(int i=1;i<=m;i++) printf("%d ",C[i]);
	return 0;
}