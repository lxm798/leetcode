#ifndef SKIPLIST_H
#define SKIPLIST_H


namespace lxm798 {
template<typename T>
class Node {
public:
    Node(int level, const T & t) {
        this->t = t;
        this->level = level;
        this->nodes = (Node<T> *) malloc(sizeof(Node<T> *) * level);
    }
    T t;
    int level;
    Node<T> *nodes;
};
template<typename T>
class SkipList {
public:
    SkipList(int level) {
        this->level = level;
        head = new Node<T>(level, -1);
    }

    void insert(T t) {
        Node<T> * node2Insert = new Node<T>(level, t);
        Node<T> * node = head;
        Node<T> *update[level];
        for (int l = level - 1 ; l >= 0; --l) {
            while (node && node->nodes[l]->t < t){
                update[l] = node;
                node = node->nodes[l];
            }
        }
        for (int i = 0; i<level && rand() % 2; ++i) {
            update[i]->nodes[i] = node2Insert;
        }
    }

    Node<T> * findNode(T t) {
        Node<T> * node = head;
        for (int l = level - 1 ; l >= 0; --l) {
            while (node && node->nodes[l]->t < t){
                node = node->nodes[l];
            }
            if (!(node && node->nodes[l]->t < t) && !(t <node->nodes[l]->t)) {
                return node;
            }
        }
        return NULL;
    }
private:
    Node<T> * head;
    int level;
};
}

#endif // SKIPLIST_H
