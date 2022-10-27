class Solution {
public:
    
    int shift_count(vector<vector<int>>&A,vector<vector<int>>&B){
        
        int n = A.size();
        
        int maxi = 0;
        
        for(int x=-(n-1);x<n;x++){
            
            for(int y=-(n-1);y<n;y++){
                
                int cnt = 0;
                
                for(int i=0;i<n;i++){
                    
                    for(int j=0;j<n;j++){
                        
                        if(i-y>=0 && j-x>=0 && i-y<n && j-x<n){
                            
                            if(A[i][j] && A[i][j]==B[i-y][j-x]){
                                
                                cnt++;
                                
                            }
                            
                        }
                        
                    }
                    
                }
                
                maxi = max(maxi,cnt);
                
            }
            
        }
        
        return maxi;
        
    }
    
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        
       return max(shift_count(A,B),shift_count(B,A));
        
    }
};