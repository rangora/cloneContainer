/** 배열을 이용한 리스트 구현.(C style) **/
#include <iostream>
#include "Vector.h"

using namespace std;


int main() {
//    List<int>* vec = new Vector<int>;
    Vector<int> vec;
    vec.listInsert(1);
    vec.listInsert(2);
//    vec.listShow();

    return 0;
}
