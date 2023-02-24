//Every pro was once an amateur. Every expert was once a beginner.

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std::chrono;
using namespace __gnu_pbds;

#define FAST() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define read(x) for (auto &it : (x)) cin >> it;
#define readpair(x) for (auto &it : (x)) cin >> it.first >> it.second;
#define print(x) for (auto &it : (x)) cout << it << " ";
#define printpair(x) for (auto &it : (x)) cout << it.first << " " << it.second << '\n';
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORe(i, a, b) for (int i = a; i <= b; i++)
#define FORd(i, a, b) for (int i = a; i >= b; i--)
#define EACH(i, x) for (auto &i : (x))
#define Fill(x, n) memset(x, n, sizeof x)
#define sz(x) int(x.size())
#define READ(FILE) freopen(FILE, "r", stdin);
#define WRITE(FILE) freopen(FILE, "w", stdout);
#define ll long long
#define ull unsigned long long
#define MP make_pair
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vt vector
#define f first
#define s second
//#define tolower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
//#define toupper(s) transform(s.begin(), s.end(), s.begin(), ::toupper)
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

const double pi = acos(-1);
const int N = 1e2 + 10, mod = 1e9 + 7;
const ll OO = LLONG_MAX;
const int oo = 0x7f7f7f7f;
int dx4[] = {-1, 0, 0, 1};
int dy4[] = {0, -1, 1, 0};
int dx8[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy8[] = {1, -1, 0, 0, 1, -1, -1, 1};
// RESET ALL GLOBALS.

void run_case(){
	int n;
	while (cin >> n && n){
		vector<vector<int>> A(n, vector<int>(n));
		bool r[N], c[N];
		memset(r, 0, sizeof r);
		memset(c, 0, sizeof c);
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				cin >> A[i][j];
			}
		}
		int even = 0;
		for (int i = 0; i < n; ++i){
			int sum = 0;
			for (int j = 0; j < n; ++j){
				sum += A[i][j];
			}
			if (sum % 2 == 0){
				++even;
				r[i] = true;
			}
		}
		for (int i = 0; i < n; ++i){
			int sum = 0;
			for (int j = 0; j < n; ++j){
				sum += A[j][i];
			}
			if (sum % 2 == 0){
				++even;
				c[i] = true;
			}
		}
		if (even == n * 2)
			cout << "OK\n";
		else{
			bool ans = false;
			for (int i = 0; i < n; ++i){
				for (int j = 0; j < n; ++j){
					int sum = 0, cnt = 0;
					A[i][j] = 1 - A[i][j];
					for (int k = 0; k < n; ++k)
						sum += A[i][k];
					if (sum % 2 == 0 && r[i] == false)
							++cnt;
					for (int k = 0; k < n; ++k)
						sum += A[k][j];
					if (sum % 2 == 0 && c[j] == false)
							++cnt;
					if (cnt + even == n * 2){
						if (ans == false)
							cout << "Change bit (" << i + 1 << "," << j + 1 << ")\n";
						ans = true;
					}
					A[i][j] = 1 - A[i][j];
				}
			}
			if (ans == false)
				cout << "Corrupt\n";
		}
	}	
}

int main(){
    FAST();
    int tc = 1;
    //cin >> tc;
    //preprocess();
    for (int i = 1; i <= tc; i++){
        //cout << "Case #" << i << ": ";
        //initialize();
        run_case();
    }
    return 0;
}
