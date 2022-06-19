class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        int n=products.size();
        
        sort(products.begin(),products.end());
        
        vector<vector<string>>result;
        
        int bstart=0;
        
        string prefix="";
        
        for(char c:searchWord){
            
            prefix+=c;
            
            int start=lower_bound(products.begin()+bstart,products.end(),prefix)-products.begin();
            
            result.push_back({});
            
            for(int i=start;i<min(start+3,n) && !products[i].compare(0,prefix.length(),prefix);++i){
                
                result.back().push_back(products[i]);
                
            }
            
            bstart=start;
            
        }
        
        return result;
        
    }
};