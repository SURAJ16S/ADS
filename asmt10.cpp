#include <iostream>

using namespace std;

class BTreeNode {
public:
    int *keys;
    int t;
    BTreeNode **children;
    int numKeys;
    bool leaf;

    BTreeNode(int t, bool leaf) {
        this->t = t;
        this->leaf = leaf;
        this->keys = new int[2 * t - 1];
        this->children = new BTreeNode *[2 * t];
        this->numKeys = 0;
    }

    void traverse() {
        int i;
        for (i = 0; i < numKeys; i++) {
            if (!leaf) {
                children[i]->traverse();
            }
            cout << keys[i] << " ";
        }
        if (!leaf) {
            children[i]->traverse();
        }
    }

    void insertNonFull(int k) {
        int i = numKeys - 1;

        if (leaf) {
            while (i >= 0 && keys[i] > k) {
                keys[i + 1] = keys[i];
                i--;
            }
            keys[i + 1] = k;
            numKeys++;
        } else {
            while (i >= 0 && keys[i] > k) {
                i--;
            }

            if (children[i + 1]->numKeys == 2 * t - 1) {
                splitChild(i + 1, children[i + 1]);

                if (keys[i + 1] < k) {
                    i++;
                }
            }
            children[i + 1]->insertNonFull(k);
        }
    }

    void splitChild(int i, BTreeNode *y) {
        BTreeNode *z = new BTreeNode(y->t, y->leaf);
        z->numKeys = t - 1;

        for (int j = 0; j < t - 1; j++) {
            z->keys[j] = y->keys[j + t];
        }

        if (!y->leaf) {
            for (int j = 0; j < t; j++) {
                z->children[j] = y->children[j + t];
            }
        }

        y->numKeys = t - 1;

        for (int j = numKeys; j >= i + 1; j--) {
            children[j + 1] = children[j];
        }

        children[i + 1] = z;

        for (int j = numKeys - 1; j >= i; j--) {
            keys[j + 1] = keys[j];
        }

        keys[i] = y->keys[t - 1];
        numKeys++;
    }

    friend class BTree;
};

class BTree {
public:
    BTreeNode *root;
    int t;

    BTree(int t) {
        this->root = nullptr;
        this->t = t;
    }

    void traverse() {
        if (root != nullptr) {
            root->traverse();
        }
    }

    void insert(int k) {
        if (root == nullptr) {
            root = new BTreeNode(t, true);
            root->keys[0] = k;
            root->numKeys = 1;
        } else {
            if (root->numKeys == 2 * t - 1) {
                BTreeNode *s = new BTreeNode(t, false);
                s->children[0] = root;
                s->splitChild(0, root);

                int i = 0;
                if (s->keys[0] < k) {
                    i = 1;
                }
                s->children[i]->insertNonFull(k);
                root = s;
            } else {
                root->insertNonFull(k);
            }
        }
    }
};

int main() {
    int degree;
    cout << "Enter the minimum degree of the B-tree: ";
    cin >> degree;
    BTree tree(degree);

    int numElements, value;
    cout << "Enter the number of elements to insert: ";
    cin >> numElements;

    for (int i = 0; i < numElements; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;
        tree.insert(value);
    }

    cout << "Traversal of the B-tree: ";
    tree.traverse();
    cout << endl;

    return 0;
}
