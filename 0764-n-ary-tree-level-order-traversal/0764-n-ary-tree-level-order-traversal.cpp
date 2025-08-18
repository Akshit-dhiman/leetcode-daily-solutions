/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;

        if(!root) return ans;
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int levelsize = q.size();
            vector<int> currentlevel;

            for(int i=0; i<levelsize; i++){

                Node* node = q.front();
                q.pop();

                currentlevel.push_back(node->val);

                for(auto child: node->children){
                    if(child){
                        q.push(child);
                    }
                }
            }
            ans.push_back(currentlevel);
        }
        return ans;
    }
};