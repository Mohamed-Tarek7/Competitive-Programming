struct coordinateCompression {
private:
    vector<ll> init;

    void compress(vector<ll> &a) {
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
    }

public:
    coordinateCompression(vector<ll> &a) {
        init = a;
        compress(init);
    }

    int compressedVal(ll val) {
        return lower_bound(init.begin(), init.end(), val) - init.begin();
    }

    ll initVal(int idx) {
        return init[idx];
    }
};
