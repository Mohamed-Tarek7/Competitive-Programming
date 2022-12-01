#include <bits/stdc++.h>
using namespace std;

#define FAST() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0
#define ll long long

void solve(){
   int n; cin >> n;
   vector<int> A(n);
   vector<string> B(n);
   for (int i = 0; i < n; i++)
	cin >> A[i];
   for (int i = 0; i < n; i++)
	cin >> B[i];
   for (int i = 1; i <= 3; i++){
	auto C = B;
	for (int j = 0; j < n; j++){
	   C[j] = B[A[j] - 1]; 
	}
	B = C;
   }
   for (int i = 0; i < n; i++)
	cout << B[i] << '\n';
}

int main(){
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    FAST();
    int tc = 1;
    //cin >> tc;
    while (tc--)
        solve();
    return 0;
}
