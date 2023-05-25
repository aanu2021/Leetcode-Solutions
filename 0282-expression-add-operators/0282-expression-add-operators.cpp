class Solution {
public:
    
    vector<string>answer;
    
    typedef long long ll;
    
    void func(string &input,int pos,string currExp,ll currVal,ll lastVal,int target){
        
        if(pos == input.length()){
            if(currVal == target){
                answer.push_back(currExp);
            }
            return;
        }
        
        ll value = 0LL;
        string part = "";
        
        for(int index=pos;index<input.length();index++){
            
            if(index != pos && input[pos]=='0') break;
            value = (value*10LL) + (input[index]-'0');
            part += input[index];
            
            if(pos==0){
                
                func(input,index+1,currExp+part,value,value,target);
                
            }
            else{
                
                func(input,index+1,currExp+"+"+part,currVal + value,value,target);
                func(input,index+1,currExp+"-"+part,currVal - value,-value,target);
                func(input,index+1,currExp+"*"+part,currVal - lastVal + (lastVal*value),lastVal*value,target);
                
            }
            
        }
        
    }
    
    vector<string> addOperators(string num, int target) {
        
        func(num,0,"",0LL,0LL,target);
        
        return answer;
        
    }
};

/*

recursion -> is the only way out over here

if only '+' / '-' operands are allowed, then there is no headeache of maintaining last segment that we took.
    
but with the introduction of multiplication we should maintain the last picked up segment.    

e0 e1 e2 e3 e4 e5

e0 + e1 - e2 * e3

if we are not picking up the segment 'e2', how do we know with which number 'e3' is gonna multiplied ?
    
therefore, the recursion call must look something like this :

rec(input,pos,currExp,currVal,lastVal,target)
    
if(pos == 0)
    
rec(input,idx+1,currExp,currVal,currVal,target)    
    
else    
    
rec(input,idx+1,currExp,currVal + value,value,target)
rec(input,idx+1,currExp,currVal - value,-value,target)
rec(input,idx+1,currExp,currVal - lastVal + (lastVal*value),target)
    
idx >= pos    

edge cases to be handled :

if(input[pos]=='0') return
    
if(pos == input.length())
     if(currVal == target)
     else
         
*/         