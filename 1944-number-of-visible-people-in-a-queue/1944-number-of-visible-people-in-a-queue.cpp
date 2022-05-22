class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& arr) {
        
        int n=arr.size();
        
        vector<int>right(n,n);
        
        stack<int>st;
        
        for(int i=n-1;i>=0;i--){
            
            if(st.empty()){
                st.push(i);
                right[i]=0;
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
        
        vector<int>ans(n);
        
//         for(int i=0;i<n;i++){
//             cout<<right[i]<<" ";
//         }cout<<endl;
        
      
        
        return right;
        
    }
};