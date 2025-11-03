//
// Created by Ethan Brothers on 10/20/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        if (size >= 64) { cerr << "Heap overflow\n"; return;}
        data[size] = idx;
        upheap(size++,weightArr);
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        if (size == 0) return -1;
        const int result = data[0];
        data[0] = data[size - 1];
        size--;
        if (size > 0) downheap(0, weightArr);
        return result;
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        while (pos > 0) {
            int parent = (pos - 1) / 2;
            int a = data[pos], b = data[parent];

            if (weightArr[a] < weightArr[b]) {
                swap(data[pos], data[parent]);
                pos = parent;
            } else break;
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        while (true) {
            int left = pos * 2 + 1;
            int right = left + 1;
            int smallest = pos;

            if (left < size &&
                weightArr[data[left]] < weightArr[data[smallest]]) { smallest = left; }
            if (right < size &&
                weightArr[data[right]] < weightArr[data[smallest]]) { smallest = right; }
            if (smallest == pos) break;

            swap(data[pos], data[smallest]);
            pos = smallest;
        }
    }
};

#endif