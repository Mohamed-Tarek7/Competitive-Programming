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
	return a != b;
    }
};

ll kruskal(){
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
	return ans;
}

const int N = 1e5 + 1;

struct dsu{
    int p[N], g[N];

    dsu(){
        for (int i = 0; i < N; ++i){
            p[i] = i;
            g[i] = 1;
        }
    }

    int find(int x){
        if (p[x] == x) 
            return x;

        return p[x] = find(p[x]);
    }

    void uni(int x, int y){
        int a = find(x);
        int b = find(y);

        if (a != b){
            if (g[a] > g[b])
                swap(a, b);

            p[a] = b;
            g[b] += g[a];
        }
    }
};

void run_case(){
    int n, m; cin >> n >> m;
    vector<pair<int, pair<int, int>>> edges;

    for (int i = 0; i < m; ++i){
        int x, y, w; cin >> x >> y >> w;
        --x, --y;

        edges.push_back({w, {x, y}});
    }

    sort(edges.begin(), edges.end());

    ll mst = 0;
    dsu dsu;

    for (int i = 0; i < m; ++i){
        int x = edges[i].second.first;
        int y = edges[i].second.second;
        int w = edges[i].first;

        if (dsu.find(x) != dsu.find(y)){
            dsu.uni(x, y);
            mst += w;
        }
    }
}
