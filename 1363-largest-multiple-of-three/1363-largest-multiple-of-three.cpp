class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        
        vector<int>count(10,0);
        
        int sum=0;
        
        for(int i:digits){
            count[i]++;
            sum+=i;
        }
        
        int arr1[6]={1,4,7,2,5,8};
        int arr2[6]={2,5,8,1,4,7};
        
        while(sum%3!=0){
            
            for(int i:sum%3==1 ? arr1 : arr2){
                
                if(count[i]>0){
                    
                    count[i]--;
                    sum-=i;
                    break;
                    
                }
                
            }
            
        }
        
        
        string res="";
        
        for(int i=9;i>=0;i--){
            
            while(count[i]>0){
                res+=to_string(i);
                count[i]--;
            }
            
        }
        
        while(res.length()>1 && res[0]=='0'){
            res.erase(0,1);
        }
        
        return res;
        
    }
};