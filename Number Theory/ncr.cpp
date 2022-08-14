ll fact[N], inv[N];

void preprocess(){
	fact[0] = inv[0] = 1;
	for (int i = 1 ; i < N ; i++){
		fact[i] = mul(fact[i - 1], i);
		inv[i] = power(fact[i], mod - 2);
	}
}

int ncr(int n, int r){
	return mul(fact[n], mul(inv[n - r], inv[r]));
}
