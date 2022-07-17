const int N = 1e5 + 1, oo = 0x7f7f7f7f;

vt<int> adj[N], d(N, oo);
bool vis[N];

void bfs(int node){
	queue<int> q;
	q.push(node);
	d[node] = 0;
	while (!q.empty()){
		int parent = q.front();
		q.pop();
		vis[parent] = 1;
		FOR(i, 0, sz(adj[parent])){
			int child = adj[parent][i];
			if (!vis[child]){
				q.push(child);
				d[child] = d[parent] + 1;
				vis[child] = 1;
			}
		}
	}
}
