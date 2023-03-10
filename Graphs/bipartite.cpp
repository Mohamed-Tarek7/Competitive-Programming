bool dfs(int node, int col){
    color[node] = col;
    visited[node] = true;
    for (int i = 0; i < adj[node].size(); ++i){
        int child = adj[node][i];
        if (visited[child]){
            if (color[child] == col)
                return false;
        } else{
            if (dfs(child, 1 - col) == false)
                return false;
        }
    }
    return true;
}
