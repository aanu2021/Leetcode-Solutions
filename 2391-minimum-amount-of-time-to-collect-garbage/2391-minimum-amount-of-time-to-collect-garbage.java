class Solution {
    public int garbageCollection(String[] garbage, int[] travel) {
        int n = garbage.length;
        int last_g = -1, last_p = -1, last_m = -1;
        for(int i=0;i<n;i++){
            for(int j=0;j<garbage[i].length();j++){
                char ch = garbage[i].charAt(j);
                if(ch == 'G') last_g = i;
                if(ch == 'M') last_m = i;
                if(ch == 'P') last_p = i;
            }
        }
        int time_g = 0, time_p = 0, time_m = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<garbage[i].length();j++){
                char ch = garbage[i].charAt(j);
                if(ch == 'G') time_g++;
                if(ch == 'P') time_p++;
                if(ch == 'M') time_m++;
            }
        }
        for(int i=0;i<last_m;i++){
            time_m += travel[i];
        }
        for(int i=0;i<last_g;i++){
            time_g += travel[i];
        }
        for(int i=0;i<last_p;i++){
            time_p += travel[i];
        }
        return (time_g + time_m + time_p);
    }
}