/** clone Vector container of STL vector **/
#include <iostream>
#include "Vector.h"

using namespace std;


int main() {

    Vector<int> vec;
    vec.reserve(2);
    vec.push_back(1);
    vec.push_back(2);

    cout << vec.at(1) << endl;
    cout << vec.at(5) << endl;

    return 0;
}
