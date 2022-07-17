vt<int> adj[N];
bool vis[N];

void dfs(int node){
  vis[node] = 1;
  FOR(i, 0, sz(adj[node])){
    int child = adj[node][i];
    if (!vis[child]) dfs(child);
  }
}
