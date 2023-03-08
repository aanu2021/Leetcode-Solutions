class Solution {
public:
    
    bool static comp(const vector<int>&x,const vector<int>&y){
        if(x[0] == y[0]) return x[1] < y[1];
        return x[0] > y[0];
    }
    
    bool static comp2(const vector<int>&x,const vector<int>&y){
        if(x[0] == y[0]) return x[1] > y[1];
        return x[0] < y[0];
    }
    
    vector<vector<int>> reconstructQueue2(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),comp);
        vector<vector<int>>ans;
        for(int i=0;i<people.size();i++){
            ans.insert(ans.begin() + people[i][1],people[i]);
        }
        return ans;
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),comp2);
        int n = people.size();
        vector<vector<int>>ans(n);
        for(int i=0;i<n;i++){
            int j = 0 , cnt = 0;
            for(j=0;j<n;j++){
                if(ans[j].size() == 0){
                    if(cnt == people[i][1]){
                        break;
                    }
                    cnt++;
                }
            }
            ans[j] = people[i];
        }
        return ans;
    }
    
};

// [7,0] [5,0] [7,1] [6,1] [5,2] [4,4]

// [5,0] [7,0] [6,1] [7,1] [5,2] [4,4]

// [7,0] [7,1] [6,1] [5,0] [5,2] [4,4]

// 5 7 5 6 4 7 

/*

[4,4] [5,0] [5,2] [6,1] [7,0] [7,1]

                         4
---   ---   ---   ---   ---   ---
 0     1     2     3     4     5   
 
 */