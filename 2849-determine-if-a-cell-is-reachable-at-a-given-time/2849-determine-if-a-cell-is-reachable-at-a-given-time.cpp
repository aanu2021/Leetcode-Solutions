class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx == fx && sy == fy){
            if(t == 1) return false;
            return true;
        }
        int xDiff = abs(sx-fx);
        int yDiff = abs(sy-fy);
        int mxDiff = max(xDiff, yDiff);
        if(mxDiff > t) return false;
        return true;
    }
};