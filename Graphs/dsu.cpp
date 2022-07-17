int p[N];
int si[N];

struct dsu{
    dsu(){
        FOR(i, 1, N){
            p[i] = i;
            si[i] = 1;
        }
    }
    int find(int x){
        if(p[x] == x) return x;
        return p[x] = find(p[x]);
    }
    void uni(int x, int y){
        int a = find(x);
        int b = find(y);
        if (a != b){
           p[a] = b;
           si[b] += si[a];
        }
    }
};
