#ifndef BST_H
#define BST_H
#include <iostream>

struct node{
    int data;
    node *left, *right;
    bool isLeaf() {return left==NULL && right==NULL;}
};


class bstree{
public:
    bstree() {root_ptr = NULL;}
    ~bstree() {clear_tree(root_ptr);}
    node* getRoot() {return root_ptr;}
    void print_in() {print_in(root_ptr); std::cout<<std::endl;}
    void print_pre() {print_pre(root_ptr); std::cout<<std::endl;}
    void print_post() {print_post(root_ptr); std::cout<<std::endl;}

    void clear_tree(node*& root) {
        if(root!=NULL){
            clear_tree(root->left);
            clear_tree(root->right);
            delete root; root=NULL;
        }
    }
    void insert(int val) {
        if(root_ptr==NULL) {
            root_ptr = new node();
            root_ptr->data=val;
            root_ptr->left = root_ptr->right = NULL;
        }
        else insert(root_ptr, val);
    }
    node* search(int val) {
        node* ptr = root_ptr;
        while(ptr!=NULL) {
            if(ptr->data == val) {return ptr;}
            else if(ptr->data>val) ptr=ptr->left;
            else ptr=ptr->right;
        }
        return ptr;
    }
    void remove(int val) {
        if(root_ptr!=NULL) {
            node* toRemove = search(val);
            if(toRemove!=NULL) {
                node* parent = findParent(root_ptr, val);
                if(toRemove->isLeaf()) {
                    if(toRemove==root_ptr) root_ptr=NULL;
                    else {
                        if(parent->right==toRemove) parent->right=NULL;
                        else parent->left=NULL;
                    }
                }
                else if(toRemove->right==NULL) {
                    if(toRemove==root_ptr) root_ptr=toRemove->left;
                    else {
                        if(parent->right==toRemove) parent->right=toRemove->left;
                        else parent->left=toRemove->left;
                    }
                }
                else if(toRemove->left==NULL) {
                    if(toRemove==root_ptr) root_ptr=toRemove->right;
                    else {
                        if(parent->right==toRemove) parent->right=toRemove->right;
                        else parent->left=toRemove->right;
                    }
                }
                else {
                    node *toSwap = toRemove;
                    toSwap = toSwap->left;
                    while(toSwap->right != NULL) toSwap=toSwap->right;
                    node *toSwapParent = findParent(toRemove, toSwap->data);
                    toRemove->data = toSwap->data;
                    toSwapParent->right = toSwap->left;
                }
            }
        }
    }
// -------------------------------------------------------------------------------- //
// -------------------------------------------------------------------------------- //
private:
    node *root_ptr;
    void print_in(node*& root) {
        if(root!=NULL){print_in(root->left); std::cout<<root->data<<" "; print_in(root->right);}
    }
    void print_pre(node*& root) {
        if(root!=NULL){std::cout<<root->data<<" "; print_pre(root->left); print_pre(root->right);}
    }
    void print_post(node*& root) {
        if(root!=NULL){print_post(root->left); print_post(root->right); std::cout<<root->data<<" ";}
    }

    void insert(node*& root, int val) {
        if(root==NULL){
            root = new node(); root->data=val; root->left = root->right = NULL;
        }
        else if (root->data>val) insert(root->left, val);
        else insert(root->right, val);
    }
    node* findParent(node*& root, int val) {
        //If root is NULL, or val!=root data and root isLeaf
        if(root==NULL) return NULL;
        else if(root->data!=val && root->isLeaf()) return NULL;
        //Return root if right/left not NULL and right/left->data==val
        if(root->right!=NULL && root->right->data==val) return root;
        else if (root->left!=NULL && root->left->data==val) return root;
        else if (root->data>val) return findParent(root->left, val);
        else return findParent(root->right, val);
    }
};
#endif
