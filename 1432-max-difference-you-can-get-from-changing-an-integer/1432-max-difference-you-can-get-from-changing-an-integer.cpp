class Solution {
public:
    int maxDiff(int num) {
        string str = to_string(num);
        int n = str.length();
        int index = -1;
        for(int i=0;i<n;i++){
            if(str[i] != '9'){
                index = i;
                break;
            }
        }
        if(index == -1) index = 0;
        string str1 = str;
        string str2 = str;
        for(int i=0;i<n;i++){
            if(str1[i] == str[index]){
                str1[i] = '9';
            }
        }
        if(str[0] != '1'){
            for(int i=0;i<n;i++){
                if(str2[i] == str[0]){
                    str2[i] = '1';
                }
            }
        }
        else{
           index = -1;
           for(int i=0;i<n;i++){
               if(str[i] != '1' && str[i] != '0'){
                   index = i;
                   break;
               }
           }
           if(index == -1){
               
           }
           else{
               for(int i=0;i<n;i++){
                   if(str2[i] == str[index]){
                       str2[i] = '0';
                   }
               }  
           }
        }
        int big = stoi(str1);
        int small = stoi(str2);
        // cout<<big<<" "<<small<<"\n";
        return big - small;
    }
};

/*

  5 6 5 4
  9 6 9 4 
  1 6 1 4 
  
  1 3 2 1 4
  9 3 2 9 4
  1 0 2 1 4

*/