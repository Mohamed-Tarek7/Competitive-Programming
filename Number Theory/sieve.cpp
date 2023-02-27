bool prime[N];

void sieve(){
	prime[0] = prime[1] = true;
	for (int i = 2; i <= n; ++i){
		if (prime[i] == false){
			for (int j = i; j <= n; j += i)
				prime[j] = true;
		}
	}
}
