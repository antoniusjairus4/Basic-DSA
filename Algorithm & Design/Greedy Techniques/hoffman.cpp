#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    char ch;
    int freq;
    Node *left;
    Node *right;

    Node(char c, int f){
        ch = c;
        freq = f;
        left = nullptr;
        right = nullptr;
    }
};

struct compare{

    bool operator()(Node *a, Node *b){
        return a -> freq > b -> freq;
    }
};

void printNode(Node *root, string ch){

    if(root == nullptr){
        return;
    }

    if(root -> left == nullptr && root -> right == nullptr){
        if(ch == ""){
            ch = "0";
        }

        cout << root -> ch << " : " << ch << endl;
    }

    else{
        printNode(root -> left, ch + "0");
        printNode(root -> right, ch + "1");
    }
}

int main()
{
    int n;
    cin >> n;

    priority_queue <Node*, vector < Node*>, compare> pq;

    for(int i = 0; i < n; i++){
        int fr;
        char ch;

        cin >> ch >> fr;
        Node *newnode = new Node(ch, fr);
        pq.push(newnode);
    }

    while(pq.size() > 1){
        Node *a = pq.top();
        pq.pop();

        Node *b = pq.top();
        pq.pop();

        Node *parent = new Node('$', a -> freq + b -> freq);
        parent -> left = a; 
        parent -> right = b;

        pq.push(parent);
    }

    printNode(pq.top(), "");
    
    return 0;
}