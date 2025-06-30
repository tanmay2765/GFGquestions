/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        Node* s=head;
        Node* f=head;
        int c=1;
        while(f!=NULL && f->next!=NULL){
            s=s->next;
            f=f->next->next;
            if(s==f) break;
        }
        if (f == NULL || f->next == NULL) return 0;
        f=f->next;
        while(f!=s){
            c++;
            f=f->next;
        }
        return c;
    }
};