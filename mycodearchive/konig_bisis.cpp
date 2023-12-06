struct bisis{
  	vector<vector<int>> adj;
  	vector<int> L, R, dd;
  
  	bisis(int n, int m) : adj(n), L(n, -1), R(m, -1), dd(n) {}
  
  	void add(int a, int b) {
		adj[a].push_back(b);
	}
  	
  	bool match(int u) {
    	if (dd[u]) return 0;
	    dd[u] = 1;
	    
	    for (int v : adj[u]) {
			if (R[v] == -1){
				L[u] = v;
				R[v] = u;
				return 1;
			}
	    }
	    for (int v : adj[u]) {
			if (match(R[v])) {
				L[u] = v;
				R[v] = u;
				return 1;
			}
	    }
	    
	    return 0;
	}
  
	int solve(){
		int ok = 1;
		while (ok--){
			fill(dd.begin(), dd.end(), 0);
			fod(i,0,L.size()-1) if (L[i] == -1) ok |= match(i);
		}
		int ret = 0;
		fod(i,0,L.size()-1) ret += (L[i] != -1);
		return ret;
	}
};