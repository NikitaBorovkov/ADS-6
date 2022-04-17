// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
 private:
  T arr[10];
  int first, last;

 public:
    TQueue(): first(0), last(0) {}
    int getSize() {
      return last - first;
    }
    void push(T x) {
      if (getSize() >= size) {
        throw std::string("Full!");
      } else {
        int count = last - 1;
        while (count >= last && x.prior > arr[count % size].prior) {
          arr[(count + 1) % size] = arr[count % size];
          count--;
        }
        arr[(count + 1) % size] = x;
        last++;
      }
    }
    T Pop() {
      if (first == last) {
        throw std::string("Empty!");
      } else {
        return arr[(first++) % size];
      }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
