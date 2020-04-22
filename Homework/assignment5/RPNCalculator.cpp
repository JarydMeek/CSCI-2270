#include "RPNCalculator.hpp"

using namespace std;

  RPNCalculator::RPNCalculator() {
    stackHead = NULL;
  }
  RPNCalculator::~RPNCalculator() {
      while (stackHead != NULL) {
        pop();
      }
  }
  bool RPNCalculator::isEmpty() {
    return (stackHead == NULL);
  }
  void RPNCalculator::push(float num) {
    Operand * toPush = new Operand;
    toPush ->number = num;
    toPush -> next = stackHead;
    stackHead = toPush;

  }
  void RPNCalculator::pop() {
    if (isEmpty() == false) {
      Operand * toDelete = stackHead;
      stackHead = stackHead -> next;
      delete toDelete;
    } else if (stackHead == NULL) {
    cout << "Stack empty, cannot pop an item." << endl;
    }
  }
  Operand* RPNCalculator::peek() {
    if (stackHead != NULL) {
      return stackHead;
    } else {
      cout << "Stack empty, cannot peek." << endl;
      return NULL;
    }
  }
  bool RPNCalculator::compute(std::string symbol) {
    if (stackHead != NULL && stackHead -> next != NULL) {
      if (symbol == "+") {
        float firstOperand = stackHead -> number;
        pop();
        float secondOperand = stackHead -> number;
        pop();
        push(firstOperand+secondOperand);
        return true;
      } else if (symbol == "*") {
        float firstOperand = stackHead -> number;
        pop();
        float secondOperand = stackHead -> number;
        pop();
        push(firstOperand*secondOperand);
        return true;
      } else {
        cout << "err: invalid operation" << endl;
        return false;
      }
    } else {
        cout << "err: not enough operands" << endl;
        return false;
    }
  } 