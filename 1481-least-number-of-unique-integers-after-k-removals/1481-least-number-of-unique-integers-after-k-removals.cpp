class Solution {
public:
    
    int findLeastNumOfUniqueInts(vector<int>& arr, int K) {
        
       int n=arr.size(); 
        
       unordered_map<int,int>freq;
        
        for(int ele:arr){
            freq[ele]++;
        }
        
        vector<int>count(n+1,0);
        
        for(auto itr:freq){
            count[itr.second]++;
        }
        
        // for(int i=1;i<=n;++i){
        //     cout<<count[i]<<" ";
        // }cout<<"\n";
        
        int remaining=freq.size();
        
        for(int k=1;k<=n;++k){
            
            bool flag=true;
            
            while(count[k]>0){
                
                if(K>=k){
                    K-=k;
                    remaining--;
                    count[k]--;
                }else{
                    flag=false;
                    break;
                }
                
            }
            
            if(flag==false){
                break;
            }
            
        }
        
        return remaining;
        
      
        
    }
};