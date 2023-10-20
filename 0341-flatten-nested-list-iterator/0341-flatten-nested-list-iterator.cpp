class NestedIterator {
    stack<pair<vector<NestedInteger>, int>> st;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        st.push({nestedList, 0});
    }
    
    int next() {
        if(hasNext()) {
            auto [list, idx] = st.top();
            st.pop();
            int val = list[idx].getInteger();
            
            if(idx + 1 < list.size()) {
                st.push({list, idx+1});
            }
            
            return val;
        }
        
        return 1;
    }
    
    bool hasNext() {
        while(!st.empty()) {
            auto [list, idx] = st.top();
            st.pop();
            if(idx < list.size()) {
                if(list[idx].isInteger()) {   
                    st.push({list, idx});
                    return true;
                } else {
                    if(idx + 1 < list.size()) {
                        st.push({list, idx+1});
                    }

                    st.push({list[idx].getList(), 0});
                }
            }
        }

        
        return false;
    }
};