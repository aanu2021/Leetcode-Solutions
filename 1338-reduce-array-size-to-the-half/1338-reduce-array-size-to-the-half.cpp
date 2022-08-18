class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        int n=arr.size();
        
        unordered_map<int,int>Count;
        
        for(int i=0;i<n;++i){
            Count[arr[i]]++;
        }
        
        vector<int>freq(n+1,0);
        
        for(auto itr:Count){
            
            freq[itr.second]++;
            
        }
        
        int curr_freq=n;
        
        int size_of_set=0;
        
        int removed_num=0;
        
        int req_removal=(n/2);
        
        
      while(removed_num<req_removal){
            
        while(freq[curr_freq]>0 && removed_num<req_removal){
            
                size_of_set++;
                
                removed_num+=curr_freq;
                
                freq[curr_freq]--;
                
            }
          
          curr_freq--;
            
       }
        
        return size_of_set;
        
    }
};