class Solution {
public:
    vector<int> parent;
    int find(int x){
        if(parent[x]!=x) parent[x]=find(parent[x]);
        return parent[x];
    }

    void unite(int x,int y){
        int px = find(x);
        int py = find(y);
        if(px!=py) parent[py]=px;
    }
    
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        for(int i=0;i<26;i++) parent[i]=i;

        for(auto& e:equations){
            if(e[1]=='='){
                int x = e[0]-'a';
                int y= e[3]-'a';
                unite(x,y);
            }
        }
        for(auto& e:equations){
            if(e[1]=='!'){
                int x =e[0]-'a';
                int y =e[3]-'a';
                if(find(x)==find(y)) return false;
            }
        }
        return true;
    }
};