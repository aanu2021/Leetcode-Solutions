class TopVotedCandidate {
public:
    
    vector<int>arr;
    
    vector<int>ans; 
    
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        
        int n=persons.size();
        
        arr=times;
        
        ans.resize(n,-1);
        
        map<int,int>mp;
        
        int maxval=0;
        
        int win_cand=-1;
        
        for(int i=0;i<n;i++){
            
            mp[persons[i]]++;
            
            if(mp[persons[i]]>=maxval){
                maxval=mp[persons[i]];
                win_cand=persons[i];
            }
            
            ans[i]=win_cand;
            
        }
        
        
        
    }
    
    int q(int t) {
        
        int idx=upper_bound(arr.begin(),arr.end(),t)-arr.begin();
        
        return ans[idx-1];
        
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */