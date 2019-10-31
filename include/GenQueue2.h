#include <iostream>
template <class T>
class GenQueue2{
  public:
    GenQueue2(int maxSize);
    ~GenQueue2();
    void insert(T data);
    T remove();
    T peek();
    bool isFull();
    bool isEmpty();
    int getSize();

  private:
    int head;
    int tail;
    int mSize;
    int numElements;
    T *myQueue;

};

template <class T>
GenQueue2<T>::GenQueue2(int maxSize){
  myQueue = new T[maxSize];
  mSize = maxSize;
  numElements = 0;
  head = 0;
  tail = -1;

}
template <class T>
GenQueue2<T>::~GenQueue2(){
  delete myQueue;

}
template <class T>
void GenQueue2<T>::insert(T data){
  if(isFull()){
    T* newArr = new T[2*mSize];
    for(int i = 0; i < mSize; ++i){
      newArr[i] = myQueue[i];
    }
    mSize *= 2;
    delete myQueue;
    myQueue = newArr;
  }
  myQueue[++tail] = data;
  ++numElements;
}
template <class T>
T GenQueue2<T>::remove(){
  T c;
  c = myQueue[head];
  ++head;
  --numElements;
  return c;
}

template <class T>
T GenQueue2<T>::peek(){
  return myQueue[head];
}

template <class T>
bool GenQueue2<T>::isFull(){
  return (numElements == mSize);
}
template <class T>
bool GenQueue2<T>::isEmpty(){
  return (numElements == 0);
}

template <class T>
int GenQueue2<T>::getSize(){
  return numElements;
}
