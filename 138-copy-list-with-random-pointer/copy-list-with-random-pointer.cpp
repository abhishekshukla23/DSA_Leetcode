/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return head;
        Node* head2=new Node(head->val);
        Node* temp1=head->next;
        Node* temp2=head2;
        unordered_map<Node*,Node*>mp;
        mp[head]=head2;
        while(temp1){
           Node* newNode=new Node(temp1->val);
           mp[temp1]=newNode;
           temp2->next=newNode;
           temp2=newNode;
           temp1=temp1->next;
        }
        temp1=head;
        temp2=head2;
         while(temp1){
            if(temp1->random!=NULL){
               temp2->random=mp[temp1->random];
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return head2;
      
        
        
    }
};