// Time Complexity insert and delete O(1) and get element O(n) where n is the position of the node
//Space Complexity O(1)


class Node{
public:
    int val;
    Node *next;

    Node(int value){
        val=value;
        next=NULL;
    }

};


class MyLinkedList {
public:
    Node *head=new Node(INT_MIN);
    int pos=0;

    MyLinkedList() {

    }

    int get(int index) {

        if(index<0 || index>=pos){
            return -1;
        }


        Node *copyHead=head->next;
        while(index--){

            copyHead=copyHead->next;
        }




            return copyHead->val;

    }

    void addAtHead(int val) {
        addAtIndex(0,val);
    }

    void addAtTail(int val) {
         addAtIndex(pos,val);
    }

    void addAtIndex(int index, int val) {
        if(index<0 || index>pos){
            return ;
        }

        else{
            Node *copyHead=head;

            while(index--){
                copyHead=copyHead->next;
            }
            Node *temp=copyHead->next;
            Node *newNode=new Node(val);
            copyHead->next=newNode;
            newNode->next=temp;
            copyHead=head->next;
            pos++;
        }
    }

    void deleteAtIndex(int index) {
         if(index<0 || index>=pos)
            return ;
        else{
            Node *copyHead=head;

            while(index--){
                copyHead=copyHead->next;
            }
            Node *temp=copyHead->next;
            if(temp)
                copyHead->next=temp->next;
            delete temp;
            pos--;

        }
    }
};
