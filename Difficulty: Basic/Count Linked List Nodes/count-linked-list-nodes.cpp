/* Link list node */
/*
struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
}; */

class Solution {
  public:
    // Function to count nodes of a linked list.
    int getCount(struct Node* head) {

        // Code here
        struct Node* c=head;
        int cc=0;
        while(c!=NULL){
            cc++;
            c=c->next;
        }
        return cc;
    }
};