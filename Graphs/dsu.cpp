struct dsu{
    int parent[N];
    int groupsize[N];
    dsu(){
        for (int i = 1 ; i < N ; i++){
            parent[i] = i;
            groupsize[i] = 1;
        }
    }
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    bool samegroup(int x, int y){
        int a = find(x);
        int b = find(y);
        return a == b;
    }
    void uni(int x, int y){
        int a = find(x);
        int b = find(y);
        if(a == b) return;
        if(groupsize[a] > groupsize[b]){
            parent[b] = a;
            groupsize[a] += groupsize[b];
        }
        else{
            parent[a] = b;
            groupsize[b] += groupsize[a];
        }
    }
    int size(int x){
        int a = find(x);
        return groupsize[a];
    }
};
