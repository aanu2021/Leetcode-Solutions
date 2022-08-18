class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        int n=arr.size();
        
        unordered_map<int,int>mp;
        
        for(int i=0;i<n;++i){
            mp[arr[i]]++;
        }
        
        vector<int>freq(n+1,0);
        
        for(auto itr:mp){
            freq[itr.second]++;
        }
        
        int curr_freq=n;
        
        int removed_num_till_now=0;
        
        int req_removal=(n/2);
        
        int size_of_set_removed=0;
        
        
        while(removed_num_till_now<req_removal){
            
            while(freq[curr_freq]>0 && removed_num_till_now<req_removal){
                
                size_of_set_removed++;
                
                freq[curr_freq]--;
                
                removed_num_till_now+=curr_freq;
                
            }
            
            curr_freq--;
            
        }
        
        return size_of_set_removed;
        
    }
};