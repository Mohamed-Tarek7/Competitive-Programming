#define ll long long

const ll OO = LONG_LONG_MAX;
const int N = 1e5;

vt<pair<int, ll>> adj[N];
vt<ll> d(N, OO);
vt<int> pre(N);
bool vis[N];
 
void dijkstra(int node){
	d[node] = 0;
	pq<pair<ll, int>, vector<pair<ll,int>>, greater<pair<ll,int>>> q;
	q.push(MP(d[node], node));
	while (!q.empty()){
		int from = q.top().s;
		q.pop();
		if (vis[from]) continue;
		vis[from] = 1;
		FOR(i, 0, sz(adj[from])){
			int to = adj[from][i].f;
			ll w = adj[from][i].s;
			if (d[to] > d[from] + w){
				d[to] = d[from] + w;
				q.push(MP(d[to], to));
				pre[to] = from;
			}
		}
	}
}
