// #include <iostream>

const int MaxSize = 100;

template <typename DataType>
class SeqList {
 public:
  SeqList();
  SeqList(DataType a[], int n);
  ~SeqList(){};
  int getLength();
  DataType get(int i);
  int locate(DataType x);
  void insert(int i, DataType x);
  DataType remove(int i);
  void printList();

 private:
  DataType data[MaxSize];
  int length = 0;
};

template <typename DataType>
SeqList<DataType>::SeqList() {
  length = 0;
}

template <typename DataType>
SeqList<DataType>::SeqList(DataType a[], int n) {
  if (n > MaxSize) throw "参数非法";
  for (int i = 0; i < n; i++) data[i] = a[i];
  length = n;
}

template <typename DataType>
int SeqList<DataType>::getLength() {
  return length;
}

template <typename DataType>
DataType SeqList<DataType>::get(int i) {
  if (i < 1 && i > length) throw "查找位置非法";
  return data[i - 1];
}

template <typename DataType>
int SeqList<DataType>::locate(DataType x) {
  for (int i = 0; i < length; i++)
    if (data[i] == x) return i + 1;
  return 0;
}

template <typename DataType>
void SeqList<DataType>::insert(int i, DataType x) {
  if (length > MaxSize - 1) throw "链表已满，无法插入";
  if (i < 1 || i > length + 1) throw "非法位置";
  for (int j = length; j > i - 1; j--) data[j] = data[j - 1];
  length++;
  data[i - 1] = x;
}

template <typename DataType>
DataType SeqList<DataType>::remove(int i) {
  if (i < 1 || i > length) throw "非法位置";
  DataType temp = data[i - 1];
  for (int j = i - 1; j < length; j++) {
    data[j] = data[j + 1];
  }
  length--;
  return temp;
}

template <typename DataType>
void SeqList<DataType>::printList() {
  for (int i = 0; i < length; i++) {
    std::cout << data[i] << " --> ";
  }
  std::cout << "end";
}
