#include <stdio.h>
#include <iostream>

using namespace std;

struct element {
    int value;
    element* pointer;
    element() {
        value = 0;
        pointer = NULL;
    }
};

struct TreeElement {
    int value;
    TreeElement* right;
    TreeElement* left;

    TreeElement() {
        value = 0;
        right = NULL;
        left = NULL;
    }
};

void Input(TreeElement*& el, int v) {
    if (el == NULL) {
        el = new TreeElement();
        el->value = v;
    }
    else if (el->value > v) {
        Input(el->left, v);
    }
    else if (el->value < v) {
        Input(el->right, v);
    }
}

void Output(TreeElement* el) {
    if (el != NULL) {
        Output(el->left);
        cout << el->value << " ";
        Output(el->right);
    }
}

void spis(TreeElement* el, element*& first, element*& p){
    if (el != NULL) {
        spis(el->left, first, p);
        element* pl = new element();
        pl->value = el ->value;
        if (first == NULL) {
            first = pl;
            p = pl;
        }
        else {
            p->pointer = pl;
            p = pl;
        }
        spis(el->right, first, p);
    }
}

void Detach(TreeElement* root, TreeElement* el){
    if (root == NULL || el == NULL) {
        return;
    }
    else if (root->left == el) {
        root->left = NULL;
    }
    else if (root->right == el) {
        root->right = NULL;
    }
    {
        Detach(root->left, el);
        Detach(root->right, el);
    }
}

void Remove(TreeElement* el) {
    if (el != NULL) {
        Remove(el->left);
        Remove(el->right);
        delete el;
    }
}

TreeElement* Find(TreeElement* el, int v) {
    TreeElement* result = NULL;
    if (el == NULL) {
        result = NULL;
    }
    else if (el->value == v) {
        result = el;
    }
    else {
        result = Find(el->left, v);
        if (result == NULL) {
            result = Find(el->right, v);
        }
    }
    return result;
}

void Out(element* l) {
    while (l != NULL) {
        cout << l->value << " ";
        l = l->pointer;
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    TreeElement* root = NULL;
    cout << "Введите колличесвто элементов дерева: ";
    int n, m;
    cin >> n;
    cout << "Введите элементы дерева: ";
    for (int i = 0; i < n; i++) {
        cin >> m;
        Input(root, m);
    }

    Output(root);
    cout << endl;
    int r;
    cout << "Введите корень,который хотите удалить: ";
    cin >> r;

    TreeElement* e = Find(root, r);
    Detach(root, e);
    Remove(e);
    Output(root);
    cout << endl;

    element* first = NULL;
    element* p = NULL;
    spis(root, first, p);
    Out(first);

    system("pause");
}
