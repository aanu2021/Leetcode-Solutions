class Solution {
public:
    
    bool static comp(const vector<int>&x,const vector<int>&y){
        if(x[0] == y[0]) return x[1] < y[1];
        return x[0] > y[0];
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),comp);
        vector<vector<int>>ans;
        for(int i=0;i<people.size();i++){
            ans.insert(ans.begin() + people[i][1],people[i]);
        }
        return ans;
    }
};

// [7,0] [5,0] [7,1] [6,1] [5,2] [4,4]

// [5,0] [7,0] [6,1] [7,1] [5,2] [4,4]

// [7,0] [7,1] [6,1] [5,0] [5,2] [4,4]

// 5 7 5 6 4 7 