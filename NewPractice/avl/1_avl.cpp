#include<iostream>
using namespace std;

class Node {
public:
    int data;
    int bf;
    Node* left;
    Node* right;

    Node(int data) : data(data), bf(0), left(nullptr), right(nullptr) {}
    Node() : data(0), bf(0), left(nullptr), right(nullptr) {}
};

class AVL {
private:
    Node* root;

public:
    AVL();
    int height(Node* p);
    Node* llRotation(Node* p);
    Node* rrRotation(Node* p);
    Node* lrRotation(Node* p);
    Node* rlRotation(Node* p);
    Node* rInsert(Node* p, int key);
    void inorder(Node* p);
    Node* search(Node* p, int key);
    void insert(int key);
    void inorder();
    Node* search(int key);
};

AVL::AVL() {
    root = nullptr;
}

int AVL::height(Node* p) {
    if (!p) return 0;
    int x = height(p->left);
    int y = height(p->right);
    return x > y ? x + 1 : y + 1;
 }

Node* AVL::llRotation(Node* p) {
    Node* pl = p->left;
    p->left = pl->right;
    pl->right = p;
    p->bf = height(p->left) - height(p->right);
    pl->bf = height(pl->left) - height(pl->right);
    if (p == root)
        root = pl;
    return pl;
}

Node* AVL::rrRotation(Node* p) {
    Node* pr = p->right;
    p->right = pr->left;
    pr->left = p;
    p->bf = height(p->left) - height(p->right);
    pr->bf = height(pr->left) - height(pr->right);
    if (p == root)
        root = pr;
    return pr;
}

Node* AVL::rlRotation(Node* p) {
    Node* pr = p->right;
    Node* prl = pr->left;
    pr->left = prl->right;
    p->right = prl->left;
    prl->right = pr;
    prl->left = p;
    p->bf = height(p->left) - height(p->right);
    pr->bf = height(pr->left) - height(pr->right);
    prl->bf = height(prl->left) - height(prl->right);
    if (p == root)
        root = prl;
    return prl;
}

Node* AVL::lrRotation(Node* p) {
    Node* pl = p->left;
    Node* plr = pl->right;
    pl->right = plr->left;
    p->left = plr->right;
    plr->left = pl;
    plr->right = p;
    p->bf = height(p->left) - height(p->right);
    pl->bf = height(pl->left) - height(pl->right);
    plr->bf = height(plr->left) - height(plr->right);
    if (p == root)
        root = plr;
    return plr;
}

Node* AVL::rInsert(Node* p, int key) {
    if (p == nullptr) {
        Node* t = new Node(key);
        if (root == nullptr) root = t;
        return t;
    }

    if (key < p->data)
        p->left = rInsert(p->left, key);
    else if (key > p->data)
        p->right = rInsert(p->right, key);

    p->bf = height(p->left) - height(p->right);

    if (p->bf == 2 && p->left->bf == 1)
        return llRotation(p);
    if (p->bf == 2 && p->left->bf == -1)
        return lrRotation(p);
    if (p->bf == -2 && p->right->bf == -1)
        return rrRotation(p);
    if (p->bf == -2 && p->right->bf == 1)
        return rlRotation(p);

    return p;
}

void AVL::inorder(Node* p) {
    if (p) {
        inorder(p->left);
        std::cout << " " << p->data;
        inorder(p->right);
    }
}

Node* AVL::search(Node* p, int key) {
    while (p != nullptr) {
        if (key == p->data)
            return p;
        else if (key < p->data)
            p = p->left;
        else
            p = p->right;
    }
    return nullptr;
}

void AVL::insert(int key) {
    root = rInsert(root, key);
}

void AVL::inorder() {
    inorder(root);
    std::cout << std::endl;
}

Node* AVL::search(int key) {
    return search(root, key);
}

int main() {
    AVL tree;
    tree.insert(30);
    tree.insert(50);
    tree.insert(40);
    tree.insert(20);
    tree.insert(10);
    tree.insert(42);
    tree.insert(46);

    tree.inorder();

    Node* temp = tree.search(2);
    if (temp != nullptr)
        std::cout << "Element found: " << temp->data << std::endl;
    else
        std::cout << "Element not found" << std::endl;

    return 0;
}
