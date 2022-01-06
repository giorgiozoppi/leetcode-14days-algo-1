#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include "linkedlist.h"
using std::begin;
using std::end;

int main() {
    linked_list<int> naive_list{10};
    naive_list.append(20);
    naive_list.append(40);
    naive_list.append(20);
    auto v = std::find(begin(naive_list), end(naive_list), 20);
    std::cout << *v;
    std::cout << std::endl;
    
}