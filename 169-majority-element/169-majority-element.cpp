class Solution {
public:
    int majorityElement(vector<int>& arr) {
        
        int n=arr.size();
        int cnt=1,ele=arr[0];
    
    for(int i=1;i<n;i++){
        
        if(ele!=arr[i]){
            cnt--;
            if(cnt<0){
                ele=arr[i];
                cnt=1;
            }
        }
        else{
            cnt++;
        }
        
        
    }
    
    cnt=0;
    
    for(int i=0;i<n;i++){
        
        if(arr[i]==ele){
            cnt++;
        }
    }
    
    if((cnt>(n/2))){
        return ele;
    }else{
        return -1;
    }
        
    }
};