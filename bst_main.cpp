#include "binsearchtree.h"
#include <iostream>
using namespace std;

int main() {
    bstree *bst = new bstree();
    cout << "Adding" << endl;
    bst->insert(30); bst->print_in();
    bst->insert(20); bst->print_in();
    bst->insert(40); bst->print_in();
    bst->insert(10); bst->print_in();
    bst->insert(50); bst->print_in();
    bst->insert(45);
    cout << endl;

    cout << "Searching" << endl;
    node* n = bst->search(40); cout<<n<<" "<<n->data<<endl;
    cout << bst->getRoot()->right <<" "<<bst->getRoot()->right->data<<endl;
    n = bst->search(13);
    if(n) cout<<"found"<<endl;
    else cout<<"notfound"<<endl;
    cout << endl;

    cout << "All orders" << endl;
    bst->print_pre();
    bst->print_in();
    bst->print_post();
    cout << endl;

    cout << "Removing" << endl;
    bst->remove(10); bst->print_in();
    bst->insert(10); bst->print_in();
    cout << bst->getRoot()->left <<" "<< bst->getRoot()->left->left <<" "<< bst->getRoot()->left->right << endl;
    bst->remove(20); bst->print_in();
    cout << bst->getRoot()->left << endl;
    cout << bst->getRoot()->left << " " << bst->getRoot()->left->data << endl;
    cout << endl;



    cout << "------------------------------------------" << endl;



    //Create then delete
    //   30 50 75 100 113 144 178
    delete bst; bst = new bstree();
    bst->insert(100);
    bst->insert(50); bst->insert(30); bst->insert(75);
    bst->insert(144); bst->insert(178); bst->insert(113);
    bst->print_in();
    delete bst;

    //Create again
    //   31 51 76  101  114 145 179
    bst = new bstree();
    bst->insert(101);
    bst->insert(51); bst->insert(31); bst->insert(76);
    bst->insert(145); bst->insert(179); bst->insert(114);
    bst->print_in();
    cout<<endl;

    //Find
    node *ptr;
    ptr = bst->search(51);
    if(ptr!=NULL) cout<<ptr<<" "<<ptr->data<<endl;
    ptr = bst->search(57);
    if(ptr==NULL) cout<<"notfound"<<endl;
    cout<<endl;

    //Remove
    cout << "Nothing Removed" << endl;
    bst->remove(130); bst->print_in();
    cout << endl;

    //Real remove
    cout << "Now Removing" << endl;
    //   31 45  51  66 76   101   114 120  145  179 189
    cout << "Added" << endl;
    bst->insert(45); bst->insert(66); bst->insert(120); bst->insert(189);
    bst->print_in(); bst->print_pre();
    cout << "Removed 114" << endl;
    bst->remove(114);
    bst->print_in(); bst->print_pre();
    cout << "Removed 51" << endl;
    bst->remove(51);
    bst->print_in(); bst->print_pre();
    cout << "Removed 101" << endl;
    bst->remove(101);
    bst->print_in(); bst->print_pre();
    cout << bst->getRoot()->data << endl;
    cout << endl;

    //Sucky Tree
    cout << "All Lefts" << endl;
    delete bst;
    bst = new bstree();
    bst->insert(100); bst->insert(90); bst->insert(80); bst->insert(70);
    bst->insert(60); bst->insert(50); bst->insert(40); bst->insert(30);
    bst->insert(20); bst->insert(10); bst->insert(0);
    cout << " - Removed 100" << endl;
    cout << "Root " << bst->getRoot()->data << " at " << bst->getRoot() << endl;
    bst->remove(100);
    bst->print_in(); bst->print_pre();
    cout << "Root " << bst->getRoot()->data << " at " << bst->getRoot() << endl;
    cout << " - Removed 70" << endl;
    cout << "Root " << bst->getRoot()->data << " at " << bst->getRoot() << endl;
    bst->remove(70);
    bst->print_in(); bst->print_pre();
    cout << "Root " << bst->getRoot()->data << " at " << bst->getRoot() << endl;
    cout << endl;
    cout << "All Rights" << endl;
    delete bst;
    bst = new bstree();
    bst->insert(0); bst->insert(10); bst->insert(20); bst->insert(30);
    bst->insert(40); bst->insert(50); bst->insert(60); bst->insert(70);
    bst->insert(80); bst->insert(90); bst->insert(100);
    cout << " - Removed 0" << endl;
    cout << "Root " << bst->getRoot()->data << " at " << bst->getRoot() << endl;
    bst->remove(0);
    bst->print_in(); bst->print_pre();
    cout << "Root " << bst->getRoot()->data << " at " << bst->getRoot() << endl;
    cout << " - Removed 50" << endl;
    bst->remove(50);
    cout << "Root " << bst->getRoot()->data << " at " << bst->getRoot() << endl;
    bst->print_in(); bst->print_pre();
    cout << "Root " << bst->getRoot()->data << " at " << bst->getRoot() << endl;
    cout << endl;



}


