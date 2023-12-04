// credit: NTVV
struct bg{
	int u , msk, val;
}; 
struct cmp_bg{
	bool operator()(const bg&a , const bg&b) const{
		return a.val > b.val;
	}  
}; 
// this algo only works for k <= 5
int f[base][mask(5)];
// spec[i]: special nodes
void djik_spider_man(){
	priority_queue<bg, vector<bg>, cmp_bg> pq;
	fod(i,1,n) fok(j,0,Mask(k)) f[i][j] = INF; 
	pq.push({spec[0],Mask(0),f[spec[0]][mask(0)] = 0});
	while(!pq.empty()){
		int u  = q.top().u; 
		int msk = q.top().msk; 
		int val = q.top().val; 
		q.pop() ; 
		if(f[u][msk] < val) continue;
		fok(i,0,k) if(BITpos(msk,i) == 0){
			int nmsk = msk ^ mask(i); 
			if(mini(f[u][nmsk], val + dis[i][u])){
				q.push({u,nmsk, f[u][nmsk]}); 
			}
		}
		for(auto [v,w] : adj[u]){
			if(mini(f[v][msk],val+w)){
				q.push({v,msk,val+w}) ; 
			}
		}
	}
	int res = INF;
	fod(i,1,n){
		mini(res,f[i][mask(k)-1]) ; 
	}
	cout << res;
}