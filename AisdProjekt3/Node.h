#ifndef NODE_H
#define NODE_H

//trie
struct Node {
    int number;
    Node** children;

    Node(int nullValue);

    // metody
    void insert(int x, Node* currentNode, int k, int n, Node* root, int nullValue);
    void printt(Node* currentNode, int n, int k, Node* root, int nullValue);
    Node* lookForElement(Node* currentNode, int x, int n, int k, Node* root);
    void deleteElement(Node* deleteNode, int n, int k, Node* root, int nullValue);
    void freeWholeTrie(Node* currentNode, int n, int k, Node* root);
};

#endif