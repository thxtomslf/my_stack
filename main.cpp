#include <iostream>
#include <cmath>
#include <string>

struct List {
    int data;
    List *next;
};

List *addNewItem(List *start, int a);
List *sum(List *l1, List *l2, List *l3, int xz = 0);
int print(List *l);

int main() {
    List *stack1 = nullptr;
    List *stack2 = nullptr;
    List *stack3 = nullptr;

    int len = 0;
    int num = 0;

    std::cout << "Enter length of number\n";
    std::cin >> len;
    std::cout << "Enter numbers\n";
    for (size_t i = 0; i < len; ++i) {
        std::cin >> num;
        stack1 = addNewItem(stack1, num);
    }
    std::cout << "Enter numbers\n";
    for (size_t i = 0; i < len; ++i) {
        std::cin >> num;
        stack2 = addNewItem(stack2, num);
    }

    stack3 = sum(stack1, stack2, stack3, 0);
    print(stack3);
    return 0;
}


List *addNewItem(List *start, int a) {
    List *newItem = new List;
    newItem->data = a;
    newItem->next = start;
    return newItem;
}

List *sum(List *l1, List *l2, List *l3, int xz) {
    if (l1 == nullptr) {
        if (xz != 0) {
            l3 = addNewItem(l3, xz);
        }
        return l3;
    }
    int a = l1->data + l2->data + xz;
    xz = a / 10;
    a = a % 10;
    l3 = addNewItem(l3, a);
    l1 = l1->next;
    l2 = l2->next;
    sum(l1, l2, l3, xz);
}

int print(List *l) {
    if (l == nullptr) {
        return 0;
    }
    std::cout << l->data;
    l = l->next;
    print(l);
}
