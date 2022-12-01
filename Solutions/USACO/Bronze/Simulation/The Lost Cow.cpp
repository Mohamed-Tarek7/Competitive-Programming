#include <bits/stdc++.h>
using namespace std;

#define FAST() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0
#define ll long long

void solve(){
	int x, y; cin >> x >> y;
	int d = 1, ans = 0, pos = x, last = x;
	if (x <= y){
		while (x + d < y){
			last = pos;
			pos = x + d;
			ans += abs(pos - last);
			d *= -2;
		}
	} else{
		while (x + d > y){
			last = pos;
			pos = x + d;
			ans += abs(pos - last);
			d *= -2;
		}
	}
	last = pos;
	cout << ans + abs(last - y);
}

int main(){
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);
    FAST();
    int tc = 1;
    //cin >> tc;
    while (tc--)
        solve();
    return 0;
}
