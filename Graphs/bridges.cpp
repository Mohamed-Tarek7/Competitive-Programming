const int N = 1e5 + 1;

vt<int> adj[N], lowlink(N), dfn(N);
vt<pii> bridges;
int ndf;

void art_bridges(int node, int p){
	lowlink[node] = dfn[node] = ndf++;
	FOR(i, 0, sz(adj[node])){
		int child = adj[node][i];
		if (dfn[child] == -1){
			art_bridges(child, node);
			lowlink[node] = min(lowlink[node], lowlink[child]);
			if (lowlink[child] > dfn[node]) bridges.pb({min(child, node), max(child, node)});
		}
		else if (child != p) lowlink[node] = min(lowlink[node], dfn[child]);
	}
}
