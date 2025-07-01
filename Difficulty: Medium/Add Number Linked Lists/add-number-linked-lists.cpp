/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* rev(Node* head){
        if(!head || !head->next) return head;
        Node* c=head->next;
        Node* temp=c->next;
        Node* x=head;
        x->next = NULL;
        while(temp){
            c->next=x;
            x=c;
            c=temp;
            temp=temp->next;
        }
        c->next=x;
        return c;
    }
    Node* addTwoLists(Node* num1, Node* num2) {
    num1 = rev(num1);
    num2 = rev(num2);

    Node* head = NULL;
    Node* c = NULL;
    int cc = 0;

    while (num1 || num2 || cc) {
        int s = (num1 ? num1->data : 0) + (num2 ? num2->data : 0) + cc;
        cc = s / 10;
        Node* temp = new Node(s % 10);

        if (!head) {
            head = temp;
            c = head;
        } else {
            c->next = temp;
            c = c->next;
        }

        if (num1) num1 = num1->next;
        if (num2) num2 = num2->next;
    }

    Node* res = rev(head);

    // remove leading 0 (if it's not the only node)
    if (res && res->data == 0 && res->next != NULL) {
        Node* temp = res;
        res = res->next;
        delete temp;
    }

    return res;
}
};