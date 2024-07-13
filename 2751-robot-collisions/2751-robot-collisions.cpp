class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        
        int n = positions.size();
        vector<vector<int>>vec(n);
        
        for(int i=0;i<n;i++){
            int pos = positions[i];
            int hel = healths[i];
            int dir = (directions[i] == 'L' ? 0 : 1);
            int idx = i;
            vec[i] = {pos, hel, dir, idx};
        }
        
        sort(vec.begin(),vec.end());
        
        stack<vector<int>>S;
        for(int i=0;i<n;i++){
            int position = vec[i][0];
            int health = vec[i][1];
            int direction = vec[i][2];
            int index = vec[i][3];
            
            if(S.empty()){
                S.push({position, health, direction, index});
            }
            else{
                
                bool flag = true;
                
                while(!S.empty() && S.top()[2] == 1 && direction == 0){
                    auto curr = S.top(); S.pop();
                    int prev_position = curr[0];
                    int prev_health = curr[1];
                    int prev_direction = curr[2];
                    int prev_index = curr[3];
                    
                    if(prev_health > health){
                        flag = false;
                        S.push({prev_position, prev_health-1, prev_direction, prev_index});
                        break;
                    }
                    else if(prev_health < health){
                        flag = true;
                        health--;
                    }
                    else{
                        flag = false;
                        break;
                    }
                }
                
                if(flag){
                    S.push({position, health, direction, index});
                }
            }
        }
        
        vector<vector<int>>arr;
        while(!S.empty()){
            auto curr = S.top(); S.pop();
            int health = curr[1];
            int index = curr[3];
            arr.push_back({index, health});
        }
        
        sort(arr.begin(),arr.end());
        vector<int>answer;
        for(auto &ele : arr){
            answer.push_back(ele[1]);
        }
        
        return answer;
        
    }
};