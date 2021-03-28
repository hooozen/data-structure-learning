#include <iostream>

#include "SeqList.cpp"

using namespace std;

int main() {
  // SeqList<int> list;
  char a[3] = {'a', 'b', 'c'};
  SeqList<char> list(a, 3);
  cout << "length: " << list.getLength() << endl;
  cout << "insert 4 element..." << endl;
  list.insert(4, '1');
  list.insert(4, '2');
  list.insert(4, '3');
  list.insert(4, '4');
  cout << "length: " << list.getLength() << endl;
  list.printList();
  cout << endl;
  cout << "remove at 2" << endl;
  list.remove(2);
  cout << "length: " << list.getLength() << endl;
  list.printList();
  cout << endl;
  cout << "element 'a' is at " << list.locate('a') << endl;
  cout << "length: " << list.getLength() << endl;
  cout << "which element is at position 2 is " << list.get(2) << endl;
}
