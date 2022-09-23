class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        
        int swaps=0;
        
        int n=row.size();
        
        vector<int>ptn(n);
        vector<int>pos(n);
        
        for(int i=0;i<n;++i){
            
            pos[row[i]]=i;
            ptn[i]=(i%2 ? i-1 : i+1);
            
        }
        
        for(int i=0;i<n;++i){
            
            for(int j=ptn[pos[ptn[row[i]]]];j!=i;j=ptn[pos[ptn[row[i]]]]){
                
                swaps++;
                
                swap(row[i],row[j]);
                
                swap(pos[row[i]],pos[row[j]]);
                
            }
            
        }
        
        return swaps;
        
    }
};