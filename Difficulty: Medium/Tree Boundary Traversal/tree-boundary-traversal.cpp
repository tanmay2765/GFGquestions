/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

/*class Solution {
  public:
    void left(Node* root,vector<int>& arr){
        if(!root || (!root->left && !root->right)) return;
        arr.push_back(root->data);
        left(root->left,arr);
    }
    void right(Node* root,vector<int>& arr){
        if(!root || (!root->left && !root->right)) return;
        if (find(arr.begin(), arr.end(), root->data) == arr.end()) arr.push_back(root->data);
        left(root->right,arr);
    }
    void leaf(Node* root,vector<int>& arr){
        if(!root) return;
        if(!root->left && !root->right) if (find(arr.begin(), arr.end(), root->data) == arr.end()) {
            arr.push_back(root->data);}
        leaf(root->left,arr);
        leaf(root->right,arr);
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> arr;
        left(root,arr);
        leaf(root,arr);
        right(root,arr);
        return arr;
    }
};*/
class Solution {
  public:
    void left(Node* root, vector<int>& arr) {
        if (!root || (!root->left && !root->right)) return;  // Skip leaves
        arr.push_back(root->data);
        if (root->left)
            left(root->left, arr);
        else
            left(root->right, arr);
    }

    void right(Node* root, vector<int>& arr, vector<int>& temp) {
        if (!root || (!root->left && !root->right)) return;  // Skip leaves
        if (root->right)
            right(root->right, arr, temp);
        else
            right(root->left, arr, temp);
        
        if (find(arr.begin(), arr.end(), root->data) == arr.end())
            temp.push_back(root->data);  // Post-order: store to temp and reverse later
    }

    void leaf(Node* root, vector<int>& arr) {
        if (!root) return;
        if (!root->left && !root->right) {
            if (find(arr.begin(), arr.end(), root->data) == arr.end())
                arr.push_back(root->data);
        }
        leaf(root->left, arr);
        leaf(root->right, arr);
    }

    vector<int> boundaryTraversal(Node* root) {
        vector<int> arr;
        if (!root) return arr;
        
        arr.push_back(root->data); // Always include root
        
        left(root->left, arr);
        leaf(root, arr);
        
        vector<int> rightNodes;
        right(root->right, arr, rightNodes);
        arr.insert(arr.end(), rightNodes.begin(), rightNodes.end());

        return arr;
    }
};
