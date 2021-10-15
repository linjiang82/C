#ifndef ORDER_TABLE_H
#define ORDER_TABLE_H

#include <map>
#include <stddef.h>
#include <string.h>
using namespace std;
enum Associative { LEFT = 0, RIGHT };
enum Operator { MUL = 0, DIV, ADD, MIN };
struct Order {
  int order;
  Associative asso;
};

Order order1 = {2, LEFT};
Order order2 = {3, LEFT};
map<char, struct Order> op = {
    {'+', order1}, {'-', order1}, {'*', order2}, {'/', order2}};
#endif
