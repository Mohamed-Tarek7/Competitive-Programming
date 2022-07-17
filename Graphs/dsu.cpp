const int N = 1e5 + 1;

struct dsu{
    int parent[N];
    int groupsize[N];
    dsu(){
        for (int i = 1 ; i < N ; i++){
            parent[i] = i;
            groupsize[i] = 1;
        }
    }
    int find(int node){
        if(parent[node] == node) return node;
        return parent[node] = find(parent[node]);
    }
    bool samegroup(int x, int y){
        int leader1 = find(x);
        int leader2 = find(y);
        return leader1 == leader2;
    }
    void uni(int x, int y){
        int leader1 = find(x);
        int leader2 = find(y);
        if(leader1 == leader2) return;
        if(groupsize[leader1] > groupsize[leader2]){
            parent[leader2] = leader1;
            groupsize[leader1] += groupsize[leader2];
        }
        else{
            parent[leader1] = leader2;
            groupsize[leader2] += groupsize[leader1];
        }
    }
    int size(int node){
        int leader = find(node);
        return groupsize[leader];
    }
};
