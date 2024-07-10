/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        map<int,Employee*>mp;
        for(auto it:employees){
            mp[it->id]=it;
        }
        queue<int>q;
        int res=0;
        q.push(id);
        while(!q.empty()){
            int uId=q.front();q.pop();
            res+=mp[uId]->importance;
            for(int vId:mp[uId]->subordinates){
                q.push(vId);
            }
        }
        return res;
    }
};