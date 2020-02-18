/** clone Vector container of STL vector **/
#include <iostream>
#include "Vector.h"

using namespace std;


int main() {

    Vector<int> vec;
//    vec.reserve(2);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(2);
    vec.push_back(4);
    vec.push_back(5);
    vec.showAll();

    return 0;
}
