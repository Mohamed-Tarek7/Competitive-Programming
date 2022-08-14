const int mod = 1e9 + 7;

ll add(ll a, ll b){
	return ((a % mod) - (b % mod) + mod) % mod;
}
