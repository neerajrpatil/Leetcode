class Solution {
public:
    vector<int>parent;
    int get(int a){
        return parent[a]=(parent[a]==a)?a:get(parent[a]);
    }
    void merge(int a, int b){
        a=get(a);
        b=get(b);
        if(a!=b)
        parent[b]=a;
    }
    
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        for(int i=0;i<26;i++)parent[i]=i;
        for(string str:equations){
            if(str[1]=='=')merge(str[0]-'a',str[3]-'a');
        }
        for(string str:equations){
            if(str[1]=='!'){
                if(get(str[0]-'a')==get(str[3]-'a'))return 0;
            }
        }
        return 1;
    }
    
};