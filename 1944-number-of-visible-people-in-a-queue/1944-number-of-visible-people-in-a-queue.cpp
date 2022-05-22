class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& arr) {
        
        int n=arr.size();
        
        vector<int>right(n,0);
        
        stack<int>st;
        
       // st.push(n-1);
        
        for(int i=n-1;i>=0;i--){
            
            if(st.empty()){
                right[i]=0;
                st.push(i);
                continue;
            }
            
            if(arr[st.top()]>=arr[i]){
                right[i]=1;
                st.push(i);
            }
            
            else if(!st.empty() && arr[st.top()]<arr[i]){
                
                int cnt=0;
                
                while(!st.empty() && arr[st.top()]<arr[i]){
                    cnt++;
                    st.pop();
                }
                
                if(!st.empty()){
                    cnt++;
                }
                
                right[i]=cnt;
                
                st.push(i);
                
            }
            
        }
        
        return right;
        
    }
};