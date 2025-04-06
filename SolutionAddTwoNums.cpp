#include <stdio.h>
#include <iostream>
#include <list>

//edanglobus

class Solution {
public:
    std::list<int> addTwoNumbers(const std::list<int>& l1, const std::list<int>& l2) {
        std::list<int> result; // empty list for result
        int carry = 0; // carry in

        auto itr_l1 = l1.begin(); // itr to the beginnig of l1
        auto itr_l2 = l2.begin(); // itr to the beginnig of l2
        
        // while loop until both lists in == .end()
        while (itr_l1 != l1.end() || itr_l2 != l2.end()) {
            int val_l1 = (itr_l1 != l1.end()) ? *(itr_l1++) : 0; // if not in the end then the curr value then ++itr else = 0
            int val_l2 = (itr_l2 != l2.end()) ? *(itr_l2++) : 0; // same for l2

            result.push_back((val_l1 + val_l2) % 10 + carry); // pushing back to res the last digit + carry
            carry = (val_l1 + val_l2) / 10; // calculating carry for next iteration
        }
        if (carry) // in case OverFlow
            result.push_back(carry);

        return result; // return result list
    }
};


int main() {
    Solution one;
    std::list<int> l1 = { 2, 7, 3, 9 };
    std::list<int> l2 = { 5, 6, 4, 1 };

    std::list<int> result = one.addTwoNumbers(l1, l2);

    for (int val : result) {
        std::cout << val << std::endl;
    }

    return 0;
}
