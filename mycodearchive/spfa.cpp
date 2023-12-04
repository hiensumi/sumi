void spfa(int s) {
    queue <int> q;
    fod(i,1,n) dis[i] = 1e18, inq[i] = 0;
    q.push(s);
    dis[s] = 0;
    inq[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = 0;
        for(auto v : adj[u]) {
            int to = v.first, w = v.second;
            if (dis[to] > dis[u] + w) {
                dis[to] = dis[u] + w;
                if (!inq[to]) {
                    q.push(to);
                    inq[to] = 1;
                }
            }
        }
    }
}