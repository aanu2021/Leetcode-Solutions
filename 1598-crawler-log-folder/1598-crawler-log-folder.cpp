class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n = logs.size();
        stack<string>S;
        for(int i=0;i<n;i++){
            string str = logs[i];
            if(str == "./"){
                continue;
            }
            else if(str == "../"){
                if(!S.empty()) S.pop();
            }
            else{
                string dir = "";
                for(char ch : str){
                    if(ch == '/') break;
                    dir += ch;
                }
                S.push(dir);
            }
        }
        return S.size();
    }
};