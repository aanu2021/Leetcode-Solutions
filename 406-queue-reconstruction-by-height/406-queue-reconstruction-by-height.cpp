class Solution {
public:
    
    bool static comp(const vector<int>&x,const vector<int>&y){
        
        if(x[0]==y[0]){
            return x[1] < y[1];
        }
        
        return x[0] > y[0];
        
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        sort(people.begin(),people.end(),comp);
        
        vector<vector<int>>ans;
        
        ans.push_back(people[0]);
        
        for(int i=1;i<people.size();++i){
            
            ans.insert(ans.begin()+people[i][1],people[i]);
            
        }
        
        return ans;
        
    }
};