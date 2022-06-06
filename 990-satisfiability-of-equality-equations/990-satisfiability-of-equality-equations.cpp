class Solution {
public:
    
    int Parent[26];
    int Rank[26];
    
    int find(int x){
        
        if(Parent[x]==x){
            return x;
        }
        
        int temp=find(Parent[x]);
        
        return Parent[x]=temp;
        
    }
    
    bool Union(int x,int y){
        
        int lx=find(x);
        int ly=find(y);
        
        if(lx!=ly){
            
            if(Rank[lx]<Rank[ly]){
                Parent[lx]=ly;
            }
            
            else{
                Parent[ly]=lx;
                if(Rank[lx]==Rank[ly]){
                    Rank[lx]++;
                }
            }
            
            return true;
            
        }
        
        else{
            
            return false;
            
        }
        
    }
    
    bool equationsPossible(vector<string>& equations) {
        
        for(int i=0;i<26;i++){
            Parent[i]=i;
            Rank[i]=1;
        }
        
        for(int i=0;i<equations.size();i++){
            
            if(equations[i][1]=='='){
                
                int x=equations[i][0]-'a';
                int y=equations[i][3]-'a';
                
                Union(x,y);
                
            }
            
        }
        
        
        for(int i=0;i<equations.size();i++){
            
             if(equations[i][1]=='!'){
                
                int x=equations[i][0]-'a';
                int y=equations[i][3]-'a';
                
                 int lx=find(x);
                 int ly=find(y);
                 
                 if(lx==ly){
                     return false;
                 }
                
            }
            
        }
        
        return true;
        
    }
};