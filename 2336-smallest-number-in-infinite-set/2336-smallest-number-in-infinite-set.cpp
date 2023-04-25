class SmallestInfiniteSet {
public:
    
    set<int>S;
    
    SmallestInfiniteSet() {
        for(int i=1;i<=2000;i++){
            S.insert(i);
        }
    }
    
    int popSmallest() {
        int ele = *S.begin();
        S.erase(ele);
        return ele;
    }
    
    void addBack(int num) {
        S.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */