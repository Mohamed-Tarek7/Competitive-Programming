bool prime[N];

void sieve(){
	prime[0] = prime[1] = true;
	for (int i = 2 ; i * i <= N ; i++){
		if (!prime[i]){
			for (int j = 2 * i ; j <= N ; j += i) prime[j] = true;
		}
	}
}
