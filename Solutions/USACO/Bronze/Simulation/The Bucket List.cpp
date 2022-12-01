#include <bits/stdc++.h>
using namespace std;

#define FAST() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0
#define ll long long

vector<pair<int, ll>> S(1001), F(1001);

void solve(){
   int n; cin >> n;
   int mx = 0;
   for (int i = 0; i < n; i++){
	int s, t, b; cin >> s >> t >> b;
	++S[s].first;
	S[s].second += b;
	++F[t].first;
	F[t].second += b;
	mx = max(mx, t);
   }
   int ans = 0, cnt = 0;
   ll B = 0;
   for (int i = 1; i <= mx; i++){
	if (S[i].first){
	   B += S[i].second;
	   cnt += S[i].first;
	}
	if (F[i].first){
	   B -= F[i].second;	
	   cnt -= F[i].first;
	}
	if (cnt > 1)
	   ans = max(1ll * ans, B);
   }
   cout << ans;
}

int main(){
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);
    FAST();
    int tc = 1;
    //cin >> tc;
    while (tc--)
        solve();
    return 0;
}
