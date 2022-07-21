vt<pair<pair<int, int>, ll>> adj[N];
bool vis[N];

ll prim(){
	pq<pair<pair<int, int>, ll>, vt<pair<pair<int, int>, ll>>, less<pair<pair<int, int>, ll>>> q;
	q.push(MP(MP(-1, 0), 0));
	ll ans = 0;
	while (!q.empty()){
		int from = q.top().f.f, to = q.top().f.s;
		ll w = q.top().s;
		q.pop();
		if (vis[to]) continue;
		vis[to] = 1;
		ans += w;
		FOR(i, 0, sz(adj[to])){
			int x = adj[to][i].f.f, y = adj[to][i].f.s;
			ll cost =  adj[to][i].s;
			if (!vis[y]) q.push(MP(MP(x, y), cost));
		}
	}
	return ans;
}
