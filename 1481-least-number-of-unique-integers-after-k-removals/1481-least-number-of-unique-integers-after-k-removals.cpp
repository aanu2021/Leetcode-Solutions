class Solution {
public:
    
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        
       unordered_map<int,int>freq;
        
        for(int ele:arr){
            freq[ele]++;
        }
        
        vector<int>vec;
        
        for(auto itr:freq){
            
            vec.push_back(itr.second);
            
        }
        
        sort(vec.begin(),vec.end());
        
        int i=0,n=vec.size();
        
        int num=n;
        
        for(i=0;i<n;++i){
            
            if(k>=vec[i]){
                k-=vec[i];
                num--;
            }
            
            else{
                break;
            }
            
        }
        
        return num;
        
    }
};