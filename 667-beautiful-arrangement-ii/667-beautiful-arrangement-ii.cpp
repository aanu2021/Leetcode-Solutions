class Solution {
public:
    vector<int> constructArray(int n, int k) {
        
        if(n==1){
            return {1};
        }
        
        if(n==2){
            return {1,2};
        }
        
        vector<int>ans;
        
        int start = 1 , end = n;
        
        bool flag = true;
        
      //  k--;
        
        while(k>0){
            
            if(flag){
                
                ans.push_back(start++);
                
            }
            
            else{
                
                ans.push_back(end--);
                
            }
            
            k--;
            
            flag = !flag;
            
        }
        
        flag = !flag;
        
        if(flag){
            
            for(int ele=start;ele<=end;ele++){
                ans.push_back(ele);
            }
            
        }
        
        else{
            
            for(int ele=end;ele>=start;ele--){
                ans.push_back(ele);
            }
            
        }
        
        return ans;
        
    }
};