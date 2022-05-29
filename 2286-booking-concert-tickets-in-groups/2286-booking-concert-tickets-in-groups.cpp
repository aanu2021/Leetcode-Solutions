class BookMyShow {
public:
    
    typedef long long ll;
    
    int n,m;
    vector<array<ll,2>>stree;
    
    
    void Build(int i,int low,int high){
        
        if(low>high){
            return;
        }
        
        if(low==high){
            stree[i]={m,m};
            return;
        }
        
        int mid=(low+high)/2;
        
        stree[i]={(ll)m,(ll)(high-low+1)*m};
        
        Build(2*i+1,low,mid);
        
        Build(2*i+2,mid+1,high);
        
    }
    
    
    vector<int>query_max(int i,int low,int high,int k,int maxRow){
       
        if(low>high || low>maxRow){
            return {};
        }
        
        if(stree[i][0]<k){
            return {};
        }
        
        if(low==high){
            
            return {low,(int)(m-stree[i][1])};
            
        }
        
        int mid=(low+high)/2;
        
        vector<int>ret=query_max(2*i+1,low,mid,k,maxRow);
        
        if(ret.size()>0){
            return ret;
        }
        
        return query_max(2*i+2,mid+1,high,k,maxRow);
        
    }

    
    void update_max(int i,int low,int high,int row,int k){
        
        if(low>high || low>row || high<row){
            return;
        }
        
        if(low==high){
            
            stree[i][0]-=k;
            stree[i][1]-=k;
            return;
            
        }
        
        int mid=(low+high)/2;
        
        stree[i][1]-=k;
        
        update_max(2*i+1,low,mid,row,k);
        update_max(2*i+2,mid+1,high,row,k);
        
        stree[i][0]=max(stree[2*i+1][0],stree[2*i+2][0]);
        
    }
    
    
    ll query_sum(int i,int low,int high,int maxRow){
        
        if(low>maxRow){
            return 0LL;
        }
        
        if(high<=maxRow){
            return stree[i][1];
        }
        
        int mid=(low+high)/2;
        
        return query_sum(2*i+1,low,mid,maxRow) + query_sum(2*i+2,mid+1,high,maxRow);
        
    }
    
    
    void update_sum(int i,int low,int high,int k,int maxRow){
        
        if(low>maxRow || low>high){
            return;
        }
        
        if(low==high){
            
            stree[i][0]-=k;
            stree[i][1]-=k;
            return;
            
        }
        
        
        int mid=(low+high)/2;
        
        stree[i][1]-=k;
        
        if(mid+1>maxRow || stree[2*i+1][1]>=k){
            update_sum(2*i+1,low,mid,k,maxRow);
        }
        
        else{
            k-=stree[2*i+1][1];
            update_sum(2*i+1,low,mid,stree[2*i+1][1],maxRow);
            update_sum(2*i+2,mid+1,high,k,maxRow);
        }
        
        stree[i][0]=max(stree[2*i+1][0],stree[2*i+2][0]);
        
    }
    
    
    BookMyShow(int nn, int mm) {
        
        n=nn;
        m=mm;
        
        int sz=1;
        
        while(sz<n*2){
            sz<<=1;
        }
        
        stree.resize(sz);
        
        Build(0,0,n-1);
        
    }
    
    
    vector<int> gather(int k, int maxRow) {
        
        vector<int>ret=query_max(0,0,n-1,k,maxRow);
        
        if(ret.size()){
            
            update_max(0,0,n-1,ret[0],k);
            
        }
        
        return ret;
        
    }
    
    
    bool scatter(int k, int maxRow) {
        
        ll cnt=query_sum(0,0,n-1,maxRow);
        
        if(cnt>=k){
            
            update_sum(0,0,n-1,k,maxRow);
            
            return true;
            
        }
        
        return false;
        
    }
};

