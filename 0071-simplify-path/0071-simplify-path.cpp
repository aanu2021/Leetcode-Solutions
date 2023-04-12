class Solution {
public:
    string simplifyPath(string path) {
        int n = path.length();
        stack<string>S;
        for(int i=0;i<n;i++){
            if(path[i]=='/') continue;
            string temp = "";
            int j = i;
            while(j<n && path[j] != '/'){
                temp += path[j];
                j++;
            }
            reverse(temp.begin(),temp.end());
            if(temp=="."){
                
            }else if(temp==".."){
                if(!S.empty()) S.pop();
            }else{
                S.push(temp);
            }
            i = j;
            i--;
        }
        string res = "";
        while(!S.empty()){
            res += S.top();
            S.pop();
            res += "/";
        }
        reverse(res.begin(),res.end());
        if(res.length()) return res;
        else return "/";
    }
};