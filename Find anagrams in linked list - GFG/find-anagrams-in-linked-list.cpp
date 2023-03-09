//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList() {
    int n; // length of link list
    scanf("%d ", &n);

    char data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i) {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
  public:
    vector<Node*> findAnagrams(struct Node* head, string s) {
        vector<Node*>answer;
        if(!head) return answer;
        Node * left = head;
        Node * right = head;
        Node * temp = NULL;
        int cnt = 0;
        vector<int>freq2(26,0);
        vector<int>freq(26,0);
        for(char ch:s){
            freq2[ch-'a']++;
        }
        int len = s.length();
        while(right){
            freq[right->data-'a']++;
            bool match = true;
            for(int i=0;i<26;i++){
                if(freq[i] != freq2[i]){
                    match = false;
                    break;
                }
            }
            // for(int i=0;i<4;i++){
            //     cout<<freq[i]<<" ";
            // }cout<<"\n";
            cnt++;
            if(cnt < len){
                right = right->next;
            }
            else if(cnt == len){
                if(match){
                    temp = right->next;
                    right->next = NULL;
                    answer.push_back(left);
                    left = temp;
                    right = temp;
                    cnt = 0;
                    for(int i=0;i<26;i++){
                        freq[i] = 0;
                    }     
                }
                else{
                    freq[left->data-'a']--;
                    left = left->next;
                    right = right->next;
                    cnt--;
                }
            }
            // else{
            //     freq[left->data-'a']--;
            //     left = left->next;
            //     cnt--;
            // }
        }
        return answer;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        struct Node *head = inputList();

        string s;
        cin >> s;

        Solution obj;
        vector<Node *> res = obj.findAnagrams(head, s);

        for (int i = 0; i < res.size(); i++) {
            printList(res[i]);
        }

        if (res.size() == 0) cout << "-1\n";
    }
}

// } Driver Code Ends