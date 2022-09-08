ll power(ll x, ll y){
    ll ans = 1;
    while (y){
        if (y & 1) ans *= x;
        x *= x;
        y /= 2;
    }
    return ans;
}

ll inverse(ll a){
    return power(a, mod - 2);
}
