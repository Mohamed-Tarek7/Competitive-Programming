vt<int> divisors(int n){
	vt<int> div;
	for (int i = 1 ; i * i <= n ; i++){
		if (n % i == 0){
			div.pb(i);
			if (i != n / i) div.pb(n / i);
		}
	}
	sort(all(div));
	return div;
}
