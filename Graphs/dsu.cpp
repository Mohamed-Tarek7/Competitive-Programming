int p[N];
int size[N];

struct dsu{
    dsu(){
        for (int i = 1 ; i < N ; i++){
            p[i] = i;
            size[i] = 1;
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
           size[b] += size[a];
        }
    }
};
