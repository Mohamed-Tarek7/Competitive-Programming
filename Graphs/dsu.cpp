struct dsu{
    int p[N];
    int groupsize[N];
    dsu(){
        for (int i = 1 ; i < N ; i++){
            p[i] = i;
            groupsize[i] = 1;
        }
    }
    int find(int x){
        if(p[x] == x) return x;
        return p[x] = find(p[x]);
    }
    void uni(int x, int y){
        int a = find(x);
        int b = find(y);
        if(a == b) return;
        if(groupsize[a] > groupsize[b]){
            p[b] = a;
            groupsize[a] += groupsize[b];
        }
        else{
            p[a] = b;
            groupsize[b] += groupsize[a];
        }
    }
};
