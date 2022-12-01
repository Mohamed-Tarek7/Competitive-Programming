#include <bits/stdc++.h>
using namespace std;

#define FAST() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0
#define ll long long

void solve(){
	int n, m; cin >> n >> m;
	vector<pair<int, int>> A(n), B(m);
	for (int i = 0; i < n; i++)
		cin >> A[i].first >> A[i].second;
	for (int i = 0; i < m; i++)
		cin >> B[i].first >> B[i].second;
	int ans = 0, L1 = 1, L2 = 1, idx1 = 0, idx2 = 0;
	for (int i = 1; i <= 100; i++){
		if (B[idx2].second > A[idx1].second)
			ans = max(ans, B[idx2].second - A[idx1].second);
		if (L1 == A[idx1].first){
			L1 = 0;
			++idx1;
		}
		if (L2 == B[idx2].first){
			L2 = 0;
			++idx2;
		}
		++L1;
		++L2;
	}
	cout << ans; 
}

int main(){
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    FAST();
    int tc = 1;
    //cin >> tc;
    while (tc--)
        solve();
    return 0;
}
