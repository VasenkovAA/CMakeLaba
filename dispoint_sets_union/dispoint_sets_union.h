#ifndef _DISPOINT_SETS_UNION_H_
#define _DISPOINT_SETS_UNION_H_
#include <iostream>

#define CDispointSetsUnion_MaxSize 5000

class CDispointSetsUnion {
public:
    CDispointSetsUnion(size_t numItems) {
        if (numItems >= CDispointSetsUnion_MaxSize) { throw std::logic_error("MaxSize has been overloaded"); }
        ItemsCount = numItems;
        parent = new size_t[numItems];
        rank = new size_t[numItems];
        for (size_t i = 0; i < numItems; ++i) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    ~CDispointSetsUnion() {
        delete[] parent;
        delete[] rank;
    }

    size_t find(size_t x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void setUnion(size_t x, size_t y) {
        size_t xRoot = find(x);
        size_t yRoot = find(y);
        if (xRoot == yRoot) {
            return;
        }
        if (rank[xRoot] < rank[yRoot]) {
            parent[xRoot] = yRoot;
        }
        else if (rank[xRoot] > rank[yRoot]) {
            parent[yRoot] = xRoot;
        }
        else {
            parent[yRoot] = xRoot;
            ++rank[xRoot];
        }
    }
    size_t getCount() {
        return ItemsCount;
    };

private:
    size_t ItemsCount;
    size_t* parent;
    size_t* rank;
};


#endif _DISPOINT_SETS_UNION_H_