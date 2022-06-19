class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        vector<vector<string>>result;
        
        sort(products.begin(),products.end());
        
        int n=products.size();
        
        string prefix="";
        
        int bstart=0;
        
        for(char c:searchWord){
            
            prefix+=c;
            
            int start=lower_bound(products.begin()+bstart,products.end(),prefix)-products.begin();
            
            result.push_back({});
            
            for(int i=start;i<min(n,start+3);i++){
                
                if(products[i].compare(0,prefix.length(),prefix)==0){
                    
                    result.back().push_back(products[i]);
                    
                }
                
            }
            
            bstart=start;
            
        }
        
        return result;
        
    }
};