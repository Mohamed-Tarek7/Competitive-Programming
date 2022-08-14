ll gcd(ll a, ll b){
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll gcd(ll a, ll b){
	while (b){
		ll c = a % b;
		a = b;
		b = c;
	}
	return a;
}
