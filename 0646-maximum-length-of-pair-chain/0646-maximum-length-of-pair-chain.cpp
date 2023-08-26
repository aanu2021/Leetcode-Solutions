class Solution {
public:
    
    bool static comp(const vector<int>&x,const vector<int>&y){
        return x[1] < y[1];
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(),pairs.end(),comp);
        int last = pairs[0][1];
        int answer = 1;
        for(int i=1;i<n;i++){
            if(pairs[i][0] > last){
                answer++;
                last = pairs[i][1];
            }
        }
        return answer;
    }
};
