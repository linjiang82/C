#include "orderTable.h"
#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

extern map<char, struct Order> op;
class Calc {
private:
  stack<char> ops;
  queue<string> output;
  string input;
  bool flag; // indicate a number finished
  Operator hashit(string a) {
    if (a == "*")
      return MUL;
    if (a == "/")
      return DIV;
    if (a == "+")
      return ADD;
    if (a == "-")
      return MIN;
  };

public:
  Calc() {
    ops = {};
    output = {};
    input = "";
    flag = false;
  }
  stack<char> getOps() { return ops; }
  void getInput(string input) { this->input = input; }
  // using shunting yard algorithm
  // void printstack() {
  // while (!ops.empty()) {
  // cout << ops.top();
  // ops.pop();
  //}
  //}
  // void printqueue() {
  // while (!output.empty()) {
  // cout << output.front() << endl;
  // output.pop();
  //}
  //}
  void parseInput() {
    string temp = "";
    string s = "";
    for (char &inputChar : input) {
      switch (inputChar) {
      case '9':
      case '8':
      case '7':
      case '6':
      case '5':
      case '4':
      case '3':
      case '2':
      case '1':
      case '0':
        if (flag == true) {
          flag = false;
          temp = "";
        }
        if (flag == false) {
          temp += inputChar;
        }
        break;
      case '(':
      case ')':
      case '+':
      case '-':
      case '*':
      case '/': {
        flag = true;
        output.push(temp);
        if (ops.empty() || inputChar == '(' || inputChar == ')') {
          ops.push(inputChar);
          break;
        }
        while (!ops.empty() && (op[inputChar].order < op[ops.top()].order ||
                                (op[ops.top()].order == op[inputChar].order &&
                                 op[inputChar].asso == LEFT))) {
          output.push((string){ops.top()});
          ops.pop();
        }
        ops.push(inputChar);
        break;
      }
      default:
        break;
      }
    };
    output.push(temp); // push the last number to the queue.
    while (!ops.empty()) {
      output.push((string){ops.top()});
      ops.pop();
    }
  } // end of parseInput

  int calculate() {
    stack<int> calStack = {};
    while (!output.empty()) {
      switch (hashit(output.front())) {
      case MUL: {
        output.pop();
        int a1 = calStack.top();
        calStack.pop();
        int a2 = calStack.top();
        calStack.pop();
        calStack.push(a1 * a2);
        break;
      }
      case DIV: {
        output.pop();
        int a1 = calStack.top();
        calStack.pop();
        int a2 = calStack.top();
        calStack.pop();
        calStack.push(a2 / a1);
        break;
      }
      case ADD: {
        output.pop();
        int a1 = calStack.top();
        calStack.pop();
        int a2 = calStack.top();
        calStack.pop();
        calStack.push(a1 + a2);
        break;
      }
      case MIN: {
        output.pop();
        int a1 = calStack.top();
        calStack.pop();
        int a2 = calStack.top();
        calStack.pop();
        calStack.push(a2 - a1);
        break;
      }
      default:
        calStack.push(stoi(output.front()));
        output.pop();
        break;
      }
    }
    return calStack.top();
  } // end of calculate
};

int main(int argc, char *argv[]) {
  Calc calc;
  calc.getInput(argv[1]);
  calc.parseInput();
  cout << calc.calculate();

  return 0;
}
