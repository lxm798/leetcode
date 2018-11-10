#include<cstdlib>
#include<iostream>
#include<cstring>
#ifndef SKIPLIST_H
#define SKIPLIST_H


namespace lxm798 {
template<typename T, typename V>
class Node {
public:
    Node(int level, const T & t, const V &v) {
        this->t = t;
        this->v = v;
        this->level = level;
        this->nodes = (Node<T,V> **) malloc(sizeof(void *) * level);
        memset(this->nodes, 0, sizeof(void *) * level);
    }
    T t;
    V v;
    int level;
    Node<T, V> **nodes;
};
template<typename T, typename V>
class SkipList {
public:
    SkipList(int level) {
        this->level = level;
        head = new Node<T, V>(level, -1000, -1000);
    }

    void insert(const T &t, const V &v) {
        Node<T, V> * node2Insert = new Node<T, V>(level, t, v);
        Node<T, V> * node = head;
        Node<T, V> *update[level];
        memset(update, 0 ,sizeof(void *) *level);
        for (int l = level - 1 ; l >= 0; --l) {
            while (node->nodes[l] && node->nodes[l]->t < t){
                node = node->nodes[l];
            }
            update[l] = node;
        }
        int totalLevel = 1;
        while (totalLevel < level && rand()%2) {
            ++totalLevel;
        }
        for (int i = 0; i < totalLevel; ++i) {
            node2Insert->nodes[i] = update[i]->nodes[i];
            update[i]->nodes[i] = node2Insert;
        }
    }

    Node<T, V> * findNode(T t) {
        Node<T, V> * node = head;
        for (int l = level - 1 ; l >= 0; --l) {
            while (node->nodes[l] && node->nodes[l]->t < t){
                std::cout << "goon" << std::endl;
                node = node->nodes[l];
            }
            if (node->nodes[l]) {
                std::cout << node->nodes[l]->t << l << std::endl;
            }
            if (node->nodes[l] && !(node->nodes[l]->t < t) && !(t <node->nodes[l]->t)) {
                std::cout << "find inner" << node->nodes[l]->t << l << std::endl;
                return node->nodes[l];
            }
        }
        return NULL;
    }

    int update(const T &t, const V &v) {
        Node<T, V> * node = findNode(t);
        if (!node) {
            return 0;
        }
        node->v = v;
        return 1;
    }

    int remove(const T &t) {
        Node<T, V> *update[level];
       memset(update, 0, sizeof(void*) * level);
       Node<T,V>* node = head;
       for (int i = level - 1; i >=0; --i) {
           while(node->nodes[i] && node->nodes[i]->t < t) {
               node = node->nodes[i];
           }
           update[i] = node; 
       }
       Node<T,V> *toDelete = update[0]->nodes[0];
       if (!toDelete || toDelete->t != t) {
            return false;
       }
        for (int i =0 ; i < level; ++i) {
            update[i]->nodes[i] = toDelete->nodes[i];
        }
        free(toDelete->nodes);
        free(toDelete);
        return true;
    }

    void debug() {
        Node<T,V> * node = head;
        std::cout << "debug::start" << std::endl;
        while (node) {
            std::cout<< node->t << ":" << node->v << std::endl;
            node = node->nodes[0];
        }
        std::cout << "debug::stop" << std::endl;
    }
private:
    Node<T, V> * head;
    int level;
};
}

#endif // SKIPLIST_H
