class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<int,string>>vec(n);
        for(int i=0;i<n;i++){
            vec[i] = {heights[i], names[i]};
        }
        sort(vec.rbegin(),vec.rend());
        vector<string>answer;
        for(int i=0;i<n;i++){
            answer.push_back(vec[i].second);
        }
        return answer;
    }
};