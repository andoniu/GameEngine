#include <iostream>

int cnt = 0;


template <typename S>
struct GE {
    void run() {
        S s;
        mm(s);
    }

    template <int p=0>
    int mm(const S& s) {
    }

//    template <>
//    int mm<5>(const S& s) {
//        mm(s);
//    }
};

template <>
template <>
int GE<int>::mm<5>(const int& ) {}





int main() {
    GE<int> x;
    x.run();
}
