#include <iostream>
#include <iomanip>
#include "functions.h"

/*********************************************/
/* Description:  */
/*********************************************/
void func(int* &value) {
    value = new int;
    *value = 3;
}


int main() {
    int* value = nullptr;
    func(value);
    cout << value << endl;

    return 0;
}
