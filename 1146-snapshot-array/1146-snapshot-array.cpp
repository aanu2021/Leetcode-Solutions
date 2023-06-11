class SnapshotArray {
public:
    
    vector<vector<int>>snaps;
    vector<vector<int>>values;
    
    int snapCnt = 0;
    
    SnapshotArray(int length) {
        
        snaps.clear();
        values.clear();
        
        snaps.resize(length);
        values.resize(length);
        
        for(int i=0;i<length;i++){
            snaps[i].push_back(0);
            values[i].push_back(0);
        }
        
    }
    
    void set(int index, int val) {
        snaps[index].push_back(snapCnt);
        values[index].push_back(val);
    }
    
    int snap() {
        snapCnt++;
        return snapCnt - 1;
    }
    
    int get(int index, int snap_id) {
        
        int j = upper_bound(snaps[index].begin(),snaps[index].end(),snap_id) - snaps[index].begin();
        j--;
        
        return values[index][j];
        
    }
};

// snap_id = 0 1 2 3 4 5 ....
    
    


/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */