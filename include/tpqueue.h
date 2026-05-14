// Copyright 2025 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
  struct Item {
    T data;
    Item* next;
  };
  Item* head;
  Item* tail;

 public:
  TPQueue() : head(nullptr), tail(nullptr) {}

  ~TPQueue() {
    while (head) {
      pop();
    }
  }

  void push(const T& val) {
    Item* temp = new Item;
    temp->data = val;
    temp->next = nullptr;

    if (!head) {
      head = temp;
      tail = temp;
    } else if (val.prior > head->data.prior) {
      temp->next = head;
      head = temp;
    } else {
      Item* current = head;
      while (current->next && current->next->data.prior >= val.prior) {
        current = current->next;
      }
      temp->next = current->next;
      current->next = temp;
      if (temp->next == nullptr) {
        tail = temp;
      }
    }
  }

  T pop() {
    if (!head) {
      return T();
    }
    Item* temp = head;
    T data = head->data;
    head = head->next;
    if (!head) {
      tail = nullptr;
    }
    delete temp;
    return data;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
