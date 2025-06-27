// Time Complexity : O(N) N is #of nodes
// Space Complexity : O(1)  
// Did this code successfully run on Leetcode : Yes

// Your code here along with comments explaining your approach:
// 1. Traverse using BFS on original graph. If duplicate node of this node is not created create it. To check if it's created use hashmap storing node address.
// 2. If it's first new node store it as head. Add all neighbors to this node and update hashmap=crea_node. 
// 3. Store all neighbors for this node.

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        queue<Node*> q;
        q.push(node);
        map<Node*,Node*> mp;
        int fl=0;
        Node* ans=nullptr;
        if(node == nullptr){
            return ans;
        }
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            vector<Node*> t_next=(temp->neighbors);
            Node* crea_node;
            if(mp[temp]==nullptr){
                crea_node = new Node(temp->val);
                if(fl==0){ans=crea_node;fl=1;}
                mp[temp]=crea_node;
            }else{crea_node=mp[temp];}
            vector<Node*> child_next;
            for(int i=0;i<t_next.size();i++){
                if(mp[t_next[i]]==nullptr){
                    Node* child_node = new Node(t_next[i]->val);
                    child_next.push_back(child_node);
                    mp[t_next[i]]=child_node;
                    q.push(t_next[i]);
                }else{
                    child_next.push_back(mp[t_next[i]]);
                }
            }
            
            crea_node->neighbors = child_next;
        
        }
        return ans;
    }
};

