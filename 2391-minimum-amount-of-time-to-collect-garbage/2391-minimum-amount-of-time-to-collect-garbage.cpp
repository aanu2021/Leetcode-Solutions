class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        
        
        int last_g=0,last_m=0,last_p=0;
        
        
        for(int i=0;i<garbage.size();++i){
            
            for(char ch:garbage[i]){
                
                if(ch=='G'){
                    
                    last_g=i;
                    
                }
                
                else if(ch=='M'){
                    
                    last_m=i;
                    
                }
                
                else{
                    
                    last_p=i;
                    
                }
                
            }
            
        }
        
        
        int time_g=0,time_m=0,time_p=0;
        
        for(int i=0;i<garbage.size();++i){
            
            int cntg=0,cntm=0,cntp=0;
            
            for(char ch:garbage[i]){
                
                if(ch=='G'){
                    cntg++;
                }
                
                else if(ch=='M'){
                    cntm++;
                }
                
                else{
                    cntp++;
                }
                
            }
            
            time_g+=cntg;
            time_m+=cntm;
            time_p+=cntp;
            
        }
        
        
        for(int i=0;i<last_g;++i){
            time_g+=travel[i];
        }
        
        for(int i=0;i<last_m;++i){
            time_m+=travel[i];
        }
        
        for(int i=0;i<last_p;++i){
            time_p+=travel[i];
        }
        
        return (time_g+time_m+time_p);
        
    }
};