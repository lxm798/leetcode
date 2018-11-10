#include <iostream>
#include "skiplist.h"
using namespace std;

int main()
{
    lxm798::SkipList<int,int> skiplist(20);
    skiplist.insert(0, 0);
    skiplist.insert(1, 0);
    skiplist.insert(-1, 0);
    lxm798::Node<int, int> * node = skiplist.findNode(1);
    if (node) {
        cout<< "find" << node->t << endl;
    } else {
        cout << "not find" << endl;
    }
    skiplist.debug();
    skiplist.remove(0);
    skiplist.debug();
    skiplist.insert(3, 0);
    skiplist.debug();
    skiplist.update(3,90);
    skiplist.debug();
    cout << "Hello World!" << endl;
    return 0;
}
