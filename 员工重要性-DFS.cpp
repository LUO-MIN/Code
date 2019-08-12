/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        if(employees.empty())
        {
            return 0;
        }
        
        unordered_map<int,Employee*> info;
        int sum=0;
        for(const auto& e : employees)
            info[e->id]=e;
        DFS(info,sum,id);
        return sum;
    }
    void DFS(unordered_map<int,Employee*> &info,int &sum,int id)
    {
        sum+=info[id]->importance;
        for(const auto& subid : info[id]->subordinates)
        {
            DFS(info,sum,subid);
        }
    }
};