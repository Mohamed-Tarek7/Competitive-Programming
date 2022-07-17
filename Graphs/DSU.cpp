const int N = 1e5 + 1;

struct DSU{
    int parent[N];
    int groupsize[N];
    DSU(){
        FOR(i, 0, N){
            parent[i] = i;
            groupsize[i] = 1;
        }
    }
    int FindLeader(int node){
        if(parent[node] == node) return node;
        return parent[node] = FindLeader(parent[node]);
    }
    bool SameGroup(int x, int y){
        int leader1 = FindLeader(x);
        int leader2 = FindLeader(y);
        return leader1 == leader2;
    }
    void MergeGroups(int x, int y){
        int leader1 = FindLeader(x);
        int leader2 = FindLeader(y);
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
    int GetSize(int node){
        int leader = FindLeader(node);
        return groupsize[leader];
    }
};
