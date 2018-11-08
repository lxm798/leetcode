#include <iostream>
#include "skiplist.h"
using namespace std;

int main()
{
    lxm798::SkipList<int> skiplist(20);
    skiplist.insert(0);
    skiplist.insert(1);
    skiplist.insert(-1);
    lxm798::Node<int> * node = skiplist.findNode(-1);
    cout << "Hello World!" << endl;
    return 0;
}
