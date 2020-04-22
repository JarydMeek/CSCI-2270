#include "ProducerConsumer.hpp"
#include <iostream>

using namespace std;

ProducerConsumer::ProducerConsumer() {
    queueFront = 0;
    queueEnd = 0;
    counter = 0;
}
  bool ProducerConsumer::isEmpty(){
      if (counter == 0) {
          return true;
      } else {
          return false;
      }
  }

  bool ProducerConsumer::isFull() {
      if (counter >= SIZE) {
          return true;
      } else {
          return false;
      }
  }
  void ProducerConsumer::enqueue(string item) {
    queue[queueEnd] = item;
      if (isFull() == false) {
        if (queueEnd == 19) {
            queueEnd = 0;
        }else {
            queueEnd++;
        }
        counter++;

      } else {
          cout << "Queue full, cannot add new item" << endl;
      }
  }
  void ProducerConsumer::dequeue() {
      if(isEmpty() == false) {
        if (queueFront == 19) {
            queueFront = 0;
        }else {
            queueFront++;
        }
        counter--;
      } else {
          cout << "Queue empty, cannot dequeue an item" << endl;
      }
  }
  string ProducerConsumer::peek() {
      if(isEmpty() == true) { 
       cout << "Queue empty, cannot peek" << endl;
       return "";
      } else {
        return queue[queueFront];
      }
  }
  int ProducerConsumer::queueSize() {
      return counter;
  } 
