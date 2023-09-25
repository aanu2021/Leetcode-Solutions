class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = s.length();
        unordered_map<int,int>freq;
        for(int i=0;i<n;i++){
            freq[s[i]]++;
        }
        for(int i=0;i<=n;i++){
            freq[t[i]]--;
        }
        int cnt = 0;
        int occ = 0;
        char ele;
        for(auto &itr : freq){
            if(itr.second != 0){
                cnt++;
                occ = itr.second;
                ele = itr.first;
            }
        }
        // cout<<cnt<<" "<<occ<<"\n";
        if(cnt != 1) return '#';
        if(occ != -1) return '#';
        else return ele;
    }
};