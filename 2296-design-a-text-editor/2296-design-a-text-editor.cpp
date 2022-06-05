class TextEditor {
public:
    
    string before,after;
    
    TextEditor() {
        before="";
        after="";
    }
    
    void addText(string text) {
        
        before.insert(before.end(),text.begin(),text.end());
        
    }
    
    int deleteText(int k) {
        
        int m=before.length();
        
        k=min(k,m);
        
        before.resize(before.size()-k);
        
        return k;
        
    }
    
    string cursorLeft(int k) {
        
        // int m=before.length();
        
        while(k>0 && !before.empty()){
            
            after.push_back(before.back());
            before.pop_back();
            k--;
            
        }
        
         int m=before.length();
        
        return before.substr(before.size()-min(10,m));
        
    }
    
    string cursorRight(int k) {
        
         // int m=before.length();
        
        while(k>0 && !after.empty()){
            
            before.push_back(after.back());
            after.pop_back();
            k--;
            
        }
        
          int m=before.length();
        
        return before.substr(before.size()-min(10,m));
        
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */