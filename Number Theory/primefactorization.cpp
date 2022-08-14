vt<int> PrimeFactorization(int n){
	vt<int> fact;
	for (int i = 2 ; i * i <= n ; i++){
		while (n % i == 0){
			fact.pb(i);
			n /= i;
		}
	}
	if (n > 1) fact.pb(n);
	return fact;
}
