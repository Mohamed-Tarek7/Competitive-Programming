vt<int> adj[N], lowlink(N), dfn(N, -1);
vt<vt<int>> comps;
int ndf = 0;
bool instack[N];
stack<int> st;

void tarjan(int node){
	lowlink[node] = dfn[node] = ndf++;
	instack[node] = 1;
	st.push(node);
	FOR(i, 0, sz(adj[node])){
		int child = adj[node][i];
		if (dfn[child] == -1){
			tarjan(child);
			lowlink[node] = min(lowlink[node], lowlink[child]);
		}
		else if (instack[child]) lowlink[node] = min(lowlink[node], dfn[child]);
	}
	if (lowlink[node] == dfn[node]){
		comps.pb(vt<int> ());
		int x = -1;
		while (x != node){
			x = st.top();
			st.pop();
			instack[x] = 0;
			comps.back().pb(x);
		}
	}
}
