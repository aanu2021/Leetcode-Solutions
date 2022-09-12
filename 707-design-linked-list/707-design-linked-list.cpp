class Node{
    
  public:
    
    int val;
    Node*next;
    
    Node(int val){
        
        this->val=val;
        this->next=NULL;
        
    }
    
};

class MyLinkedList {
public:
    
    Node*head;
    
    int length;
    
    MyLinkedList() {
        
        head=NULL;
        
        length=0;
        
    }
    
    int get(int index) {
        
        if(index>=length){
            
            return -1;
            
        }
        
        else{
            
            Node*ptr=head;
            
            while(index--){
                
                ptr=ptr->next;
                
            }
            
            return ptr->val;
            
        }
        
    }
    
    void addAtHead(int val) {
        
        Node*temp=new Node(val);
        
        temp->next=head;
        
        head=temp;
        
        length++;
        
    }
    
    void addAtTail(int val) {
        
        if(!head){
            
            head=new Node(val);
            
        }
        
        else{
            
            Node*ptr=head;
            
            while(ptr && ptr->next){
                
                ptr=ptr->next;
                
            }
            
            ptr->next=new Node(val);
            
        }
        
        length++;
        
    }
    
    void addAtIndex(int index, int val) {
        
        if(index==0){
            
            addAtHead(val);
            
        }
        
        else if(index==length){
            
            addAtTail(val);
            
        }
        
        else if(index>0 && index<length){
            
            Node*ptr=head;
            
            index--;
            
            while(index--){
                
                ptr=ptr->next;
                
            }
            
            Node*nextptr=ptr->next;
            
            Node*temp=new Node(val);
            
            ptr->next=temp;
            temp->next=nextptr;
            
            length++;
            
        }
        
        else{
            
            return;
            
        }
        
    }
    
    void deleteAtIndex(int index) {
        
        if(index>=length){
            
            return;
            
        }
        
        else if(index==0){
            
            head=head->next;
            
        }
        
        else{
            
            index--;
            
            Node*ptr=head;
            
            while(index--){
                
                ptr=ptr->next;
                
            }
            
            ptr->next=ptr->next->next;
            
        }
        
        length--;
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */