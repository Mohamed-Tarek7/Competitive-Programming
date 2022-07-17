vt<int> adj[N], lowlink(N), dfn(N);
set<int> art_points;
int ndf;
bool root;

void bicon(int node, int p){
	lowlink[node] = dfn[node] = ndf++;
	FOR(i, 0, sz(adj[node])){
		int child = adj[node][i];
		if (dfn[child] == -1){
			bicon(child, node);
			lowlink[node] = min(lowlink[node], lowlink[child]);
			if (lowlink[child] >= dfn[node]){
				if (dfn[node] == 0 && !root) root = true;
				else art_points.insert(node);
			}
		}
		else if (child != p) lowlink[node] = min(lowlink[node], dfn[child]);
	}
}
