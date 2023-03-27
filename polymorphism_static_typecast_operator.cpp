#include <iostream>
using namespace std;
// Un-related Types
class B;
class A { int i_; public:
A(int i = 0) : i_(i) { cout << "A::A(i)\n"; }
operator int() { cout << "A::operator int()\n"; return i_; }
};
class B { public:
operator A() { cout << "B::operator A()\n"; return A(); }
};
int main() { A a; B b; int i = 5;
// B ==> A
a = b; // B::operator A()
a = static_cast<A>(b); // B::operator A()
a = (A)b; // B::operator A()
// A ==> int
i = a; // A::operator int()
i = static_cast<int>(a); // A::operator int()
i = (int)a; // A::operator int()
}