#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include "Node.h"

using namespace std;

int main()
{
    int numberOfTests;
    scanf("%d", &numberOfTests);

    int minNumber, maxNumber;

    scanf("%d", &minNumber);
    scanf("%d", &maxNumber);

    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);

    int nullValue = minNumber - 1;
    Node root = Node(nullValue); //stworzenie korzenia
    root.children = new Node * [n];
    int numberOfChildren = n;

    for (int i = 0; i < numberOfChildren; i++) {
        root.children[i] = new Node(nullValue);
    }

    for (int i = 0; i < numberOfTests; i++)
    {
        char specialCharacter;
        int x; //klucz w drzewie
        scanf(" %c", &specialCharacter);

        if (specialCharacter == 'I') {

            scanf("%d", &x);

            if (root.lookForElement(&root, x, n, k, &root) != nullptr) {
                cout << x << " exist" << endl;
            }

            else {
                root.insert(x, &root, k, n, &root, nullValue);
            }
        }

        else if (specialCharacter == 'P') {
            root.printt(&root, n, k, &root, nullValue);
            cout << endl;
        }
        else if (specialCharacter == 'D') {
            scanf("%d", &x);
            Node* elementDoUsuniecia = root.lookForElement(&root, x, n, k, &root);
            if (elementDoUsuniecia == nullptr) {
                cout << x << " not exist" << endl;
            }

            else {
                root.deleteElement(elementDoUsuniecia, n, k, &root, nullValue);
            }
        }

        else if (specialCharacter == 'L') {
            scanf("%d", &x);
            Node* node = root.lookForElement(&root, x, n, k, &root);
            if (node != nullptr) {
                cout << x << " exist" << endl;
            }
            else {
                cout << x << " not exist" << endl;
            }
        }
    }
    root.freeWholeTrie(&root, n, k, &root);
    delete[] root.children;
    
    return 0;
}