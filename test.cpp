template <int k>
class C1 {
    int val = k;
};

template <typename C>
struct P {
    C<3> c;
};

int main() {
    P<C1> p;
}
