#include "Node.h"
#include <iostream>

using namespace std;

Node::Node(int nullValue) {
    number = nullValue;
    children = nullptr;
}

void Node::insert(int x, Node* currentNode, int k, int n, Node*root, int nullVaule)
{
    int numberOfChildren;
    int temp = x;
    while (true) {

        if (currentNode == root) {
            numberOfChildren = n;
        }
        else {
            numberOfChildren = k;
        }

        if (currentNode->number == nullVaule) //jesli jest jeszcze nie ma numeru
        {
            currentNode->number = x;
            return;
        }

        if (currentNode->children == nullptr) {
            currentNode->children = new Node * [numberOfChildren];
            for (int i = 0; i < numberOfChildren; i++) {
                currentNode->children[i] = nullptr;
            }
        }

        int div = temp % numberOfChildren;
        temp = temp / numberOfChildren;

        // jesli dziecko jeszcze nie istnieje
        if (currentNode->children[div] == nullptr)
        {
            currentNode->children[div] = new Node(nullVaule);
        }

        currentNode = currentNode->children[div];
    }
}

void Node::printt(Node* currentNode, int n, int k, Node* root, int nullVaule)
{
    int numberOfChildren;

    if (currentNode == root) {
        numberOfChildren = n;
    }
    else {
        numberOfChildren = k;
    }

    if (currentNode->number != nullVaule) {
        cout << currentNode->number << " ";
    }

    if (currentNode->children == nullptr)
    {
        return;
    }
    for (int i = 0; i < numberOfChildren; i++)
    {
        if (currentNode->children[i] == nullptr)
        {
            continue;
        }
        printt(currentNode->children[i], n, k, root, nullVaule);
    }
}

//zwalnanie pamieci drzewa
void Node::freeWholeTrie(Node* currentNode, int n, int k, Node* root)
{
    int numberOfChildren;

    if (currentNode == root) {
        numberOfChildren = n;
    }
    else {
        numberOfChildren = k;
    }

    if (currentNode->children != nullptr)
    {
        for (int i = 0; i < numberOfChildren; i++)
        {
            if (currentNode->children[i] == nullptr)
                continue;
            freeWholeTrie(currentNode->children[i], n, k, root);
        }
    }
    if (currentNode == root)return;
    delete[] currentNode->children;
    delete currentNode;
}

Node* Node::lookForElement(Node* currentNode, int x, int n, int k, Node* root)
{
    int temp = x;
    int div;
    while (true)
    {
        int numberOfChildren;

        if (currentNode == root) {
            numberOfChildren = n;
        }
        else {
            numberOfChildren = k;
        }

        if (currentNode==nullptr)
        {
            return nullptr;
        }
        if (currentNode->number == x) {
            return currentNode;
        }
        if (currentNode->children == nullptr) {
            return nullptr;
        }

        div = temp % numberOfChildren;
        temp = temp / numberOfChildren;
        if (currentNode->children != nullptr) {
            currentNode = currentNode->children[div];
        }
        else if (currentNode->children == nullptr) {
            break;
        }
    }
    //jak nie zostal znaleziony
    return nullptr;
}


void Node::deleteElement(Node* deleteNode, int n, int k, Node* root, int nullVaule)
{

    // jesli nie ma dzieci, to po prostu usun
    if (deleteNode->children == nullptr) {
        deleteNode->number = nullVaule;
        return;
    }

    Node* candidateToDelete = deleteNode;
    while (candidateToDelete->children != nullptr)
    {
        int numberOfChildren;

        if (candidateToDelete == root) {
            numberOfChildren = n;
        }
        else {
            numberOfChildren = k;
        }

        bool isFound = false;
        for (int i = 0; i < numberOfChildren; i++)
        {
            if (candidateToDelete->children[i] != nullptr && candidateToDelete->children[i]->number!=nullVaule)
            {
                candidateToDelete = candidateToDelete->children[i];
                isFound = true;
                break;
            }
        }
        if (isFound == false) {
            break; // nie ma dalszych dzieci zajetych
        }
    }
    deleteNode->number = candidateToDelete->number;
    candidateToDelete->number = nullVaule;
}