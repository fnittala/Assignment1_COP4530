#include <iostream>
#include <cstdlib>

using namespace std;

class Node {
    public:
        char data;
        Node *next;
        Node *prev;
};

class Stack {
    public:
        Stack();
        void push(char element);
        char pop();
        char display();
        int capacity;
    private:
        Node *head;
};


Stack::Stack(){
    head = NULL;
};

void Stack::push(char element){
    Node *new_node = new Node;
    new_node->data = element;
    new_node->next = NULL;
    
    if (head == NULL) {
        new_node->prev = NULL;
    } else {
        new_node->prev = head;
    }
    head = new_node;
};

char Stack::pop() {
    if (head == NULL) {
        cout << "Stack is empty" << endl;
        return '\0';
    } else {
        char redata = head->data;
        head = head->prev;
        if (head != NULL){
            head->next = NULL;
            return redata;
        } else {
            return '\0';
        }
    }
};

char Stack::display(){
    if (head == NULL) {
        return '\0';
    }
    return head->data;
};

int TestStack(string string_test){
    Stack s = Stack();
    for (int i = 0; i < string_test.length(); i++){
        if (string_test[i] == '(' || string_test[i] == '{' || string_test[i] == '[') {
            s.push(string_test[i]);
        } 
        else if (string_test[i] == ')' || string_test[i] == ']' || string_test[i] == '}'){
            if ((string_test[i] == ')') && s.display() != '(') {
                return 0;
            }
            else if ((string_test[i] == ']') && (s.display() != '[')) {
                return 0;
            }
            else if ((string_test[i] == '}') && (s.display() != '{')) {
                return 0;
            }
            else {
                s.pop();
            }
        }
    }
    if (s.display() != '\0') {
        return 0;
    }
    return 1;
}
    


int main(){
    string test1 = "{{{{}}}[][]((())";    // * False
    string test2 = "(%TT{>><]]]%%%%%%)";  // * False
    string test3 = "(((((()))))){}{}{}[][][][[[]]]"; // * True
    string test4 = "{{{@23+6767}}}*<45>(a+b)[]"; // * True
    string test5 = "(a+b)"; // * True
    string test6 = "(((((a+b %%%%%####3422222222222)))))[]{}[]"; // * True
    string test7 = "[[[{{()}}]]]"; // * True
    string test8 = "((((((}}}}}}"; // * False
    string test9 = "Aaaaaaaa+bbbb({}{}{}[][][]tttttt + %^$)"; // * True
    string test10 = "@@@@@@@@@@@@@@@@@@@@@@@$$%%T$%$%$$%{}()%%%%%%%%%%%%%%%%%%%%%%%%%%%% "; // * True

    cout << TestStack(test1) << endl;
    return 0;
}
