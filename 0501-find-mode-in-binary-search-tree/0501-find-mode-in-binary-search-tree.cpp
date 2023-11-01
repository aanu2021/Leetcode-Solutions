class Solution {
public:
    
    void update(int &currFreq, int &maxFreq, int nodeValue, vector<int> &answer){
        if(currFreq > maxFreq){
            maxFreq = currFreq;
            answer.clear();
            answer.push_back(nodeValue);
        }
        else if(currFreq == maxFreq){
            answer.push_back(nodeValue);
        }
    }
    
    vector<int> findMode(TreeNode* root) {
        int maxFreq = 0;
        int currFreq = 0;
        int prevElement = -1;
        int modeElement = -1;
        vector<int>answer;
        while(root){
            if(root->left == NULL){
                if(root->val == prevElement) currFreq++;
                else currFreq = 1;
                prevElement = root->val;
                update(currFreq, maxFreq, root->val, answer);
                root = root->right;
            }
            else{
                TreeNode*prev = root->left;
                while(prev && prev->right && prev->right != root){
                    prev = prev->right;
                }
                if(prev->right == NULL){
                    prev->right = root;
                    root = root->left;
                }
                else{
                    prev->right = NULL;
                    if(root->val == prevElement) currFreq++;
                    else currFreq = 1;
                    prevElement = root->val;
                    update(currFreq, maxFreq, root->val, answer);
                    root = root->right;
                }
            }
        }
        return answer;
    }
};