#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <iostream>
#include <stdexcept>
#include "BSNode.h"

template<typename T>
class BSTree {
private:
    int nelem;
    BSNode<T>* root;

    const BSNode<T>* search(BSNode<T>* n, T e) const {
        if (n == nullptr) {
            throw std::runtime_error("No se encontró el elemento");
        } else if (n->elem < e) {
            return search(n->right, e);
        } else if (n->elem > e) {
            return search(n->left, e);
        } else {
            return n;
        }
    }

    BSNode<T>* insert(BSNode<T>* n, T e) {
        if (n == nullptr) {
            nelem++;
            return new BSNode<T>(e);
        } else if (n->elem == e) {
            throw std::runtime_error("Este objeto ya existe");
        } else if (n->elem < e) {
            n->right = insert(n->right, e);
        } else {
            n->left = insert(n->left, e);
        }
        return n;
    }

    void print_in_order(std::ostream& out, BSNode<T>* n) const {
        if (n != nullptr) {
            print_in_order(out, n->left);
            out << n->elem << " ";
            print_in_order(out, n->right);
        }
    }

    BSNode<T>* remove(BSNode<T>* n, T e) {
        if (n == nullptr) {
            throw std::runtime_error("Elemento no encontrado");
        } else if (n->elem < e) {
            n->right = remove(n->right, e);
        } else if (n->elem > e) {
            n->left = remove(n->left, e);
        } else {
            if (n->left != nullptr && n->right != nullptr) {
                n->elem = max(n->left);
                n->left = remove_max(n->left);
            } else {
                BSNode<T>* old = n;
                n = (n->left != nullptr) ? n->left : n->right;
                delete old;
                nelem--;
            }
        }
        return n;
    }

    T max(BSNode<T>* n) const {
        if (n == nullptr) {
            throw std::runtime_error("Elemento no encontrado");
        } else if (n->right != nullptr) {
            return max(n->right);
        } else {
            return n->elem;
        }
    }

    BSNode<T>* remove_max(BSNode<T>* n) {
        if (n->right == nullptr) {
            BSNode<T>* left = n->left;
            delete n;
            return left;
        } else {
            n->right = remove_max(n->right);
            return n;
        }
    }

    void delete_cascade(BSNode<T>* n) {
        if (n != nullptr) {
            delete_cascade(n->left);
            delete_cascade(n->right);
            delete n;
        }
    }

    int depth(BSNode<T>* n) const {
        if (n == nullptr) {
            return -1;
        }
        int left_depth = depth(n->left);
        int right_depth = depth(n->right);
        return 1 + std::max(left_depth, right_depth);
    }

public:
    BSTree() : nelem(0), root(nullptr) {}

    int size() const {
        return nelem;
    }

    T search(T e) const {
        return search(root, e)->elem;
    }

    T operator[](T e) const {
        return search(e);
    }

    void insert(T e) {
        root = insert(root, e);
    }

    void remove(T e) {
        root = remove(root, e);
    }

    int depth() const {
        return depth(root);
    }

    friend std::ostream& operator<<(std::ostream& out, const BSTree<T>& bst) {
        bst.print_in_order(out, bst.root);
        return out;
    }

    ~BSTree() {
        delete_cascade(root);
    }
};

#endif

