/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

// Class Solution
class Solution {
  public:
    // Function to count the number of leaf nodes in a binary tree.
    void leaf(Node* root,int& c){
        if(!root) return;
        if(root->left==NULL && root->right==NULL) c++;
        leaf(root->left,c);
        leaf(root->right,c);
    }
    int countLeaves(Node* root) {
        // write code here
        int c=0;
        leaf(root,c);
        return c;
    }
};