int p[N], si[N], n;
vt<pair<pair<int, int>, ll>> adj;

struct dsu{
    dsu(){
        FOR(i, 1, N){
            p[i] = i;
            si[i] = 1;
        }
    }
    int find(int x){
        if(p[x] == x) return x;
        return p[x] = find(p[x]);
    }
   	bool uni(int x, int y){
        int a = find(x);
        int b = find(y);
        if (a != b){
           p[a] = b;
           si[b] += si[a];
        }
	return x != y;
    }
};

void kruskal(){
	dsu dsu;
	ll ans = 0;
	pq<pair<pair<int, int>, ll>, vector<pair<pair<int, int>, ll>>, less<pair<pair<int, int>, ll>>> q;
	FOR(i, 0, n) q.push(MP(MP(adj[i].f.f, adj[i].f.s), adj[i].s));
	while (!q.empty()){
		int from = q.top().f.f, to = q.top().f.s;
		ll w = q.top().s;
		q.pop();
		if (dsu.uni(from, to)) ans += w;
	}
}
