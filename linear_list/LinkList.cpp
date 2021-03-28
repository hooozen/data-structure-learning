/**
 * 单链表
 */

#include <iostream>
using namespace std;

template <typename DataType>
struct Node {
  DataType data;
  Node<DataType>* next;
};

template <typename DataType>
class LinkList {
 public:
  LinkList();
  LinkList(DataType a[], int n);
  ~LinkList(){};
  int getLength();
  DataType get(int i);
  int locate(DataType x);
  void insert(int i, DataType x);
  DataType remove(int i);
  void printList();

 private:
  Node<DataType>* first;
};

template <typename DataType>
int LinkList<DataType>::getLength() {
  int i = 0;
  Node<DataType>* s = first;
  while (s -> next != NULL) {
    s = s -> next;
    i++;
  }
  return i;
}

template <typename DataType>
DataType LinkList<DataType>::get(int i) {
  if (i < 1) throw "位置下溢";
  int n = 1;
  Node<DataType>* s = first;
  while (s -> next != NULL) {
    s = s -> next;
    if (i == n) return s -> data;
    n++;
  }
  throw "位置上溢";
}

template <typename DataType>
int LinkList<DataType>::locate(DataType x) {
  Node<DataType>* s = first;
  int i = 1;
  while (s->next != NULL) {
    s = s->next;
    if (s->data == x) return i;
    i++;
  }
  return 0;
}

template <typename DataType>
void LinkList<DataType>::insert(int i, DataType x) {
  if (i < 1) throw "位置下溢";
  Node<DataType>* s = new Node<DataType>;
  s = first;
  int n = 0;
  while (n < i - 1) {
    if (s->next == NULL) throw "位置上溢";
    s = s->next;
    n++;
  }
  Node<DataType>* node = new Node<DataType>;
  node->data = x;
  node->next = s->next;
  s->next = node;
}

template <typename DataType>
DataType LinkList<DataType>::remove(int i) {
  if (i < 1) throw "位置下溢";
  if (first->next->next == NULL) throw "空链表!";
  Node<DataType>* s;
  s = first;
  int n = 0;
  while (n < i - 1) {
    s = s->next;
    if (s == NULL) throw "位置上溢";
    n++;
  }
  DataType x = s->next->data;
  s->next = s->next->next;

  return x;
}

template <typename DataType>
void LinkList<DataType>::printList() {
  Node<DataType>* s;
  cout << "head"
       << "->";
  s = first->next;
  while (s->next != NULL) {
    cout << s->data << "->";
    s = s->next;
  }
  cout << s->data << "->"
       << "end" << endl;
}

template <typename DataType>
LinkList<DataType>::LinkList() {
  Node<DataType> head;
  head.next = NULL;
  first = &head;
}

template <typename DataType>
LinkList<DataType>::LinkList(DataType a[], int n) {
  first = new Node<DataType>;
  first->next = NULL;
  Node<DataType>* r = first;
  for (int i = 0; i < n; i++) {
    Node<DataType>* s = new Node<DataType>;
    s->data = a[i];
    r->next = s;
    r = s;
  }
  r->next = NULL;
}


// test
int main() {
  char a[4] = {'a', 'b', 'c', 'd'};
  LinkList<char> list(a, 4);
  list.printList();
  cout << "lenght of link list:" << list.getLength() << endl;
  list.insert(1, '0');
  cout << list.getLength() << endl;
  list.insert(1, '1');
  cout << list.getLength() << endl;
  list.insert(5, 'd');
  list.printList();
  try {
    // list.remove(0);
    list.remove(5);
  } catch (const char* err) {
    cout << err;
  }
  list.remove(3);
  list.printList();
  cout << list.get(3) << endl;
  cout << list.locate('d') << endl;
}
