#include <iostream>
using namespace std;

class B;
class A
{
public:
    B * b;
    int id;
    int element;
public:
    A(B * pa, int element_, int id_) { b = pa; element = element_; id = id_; }
    void attack(int power);
};

class B
{
public:
    A * a[1000];
    int total;
public:
    B() {total = 0;}
    void produce();
};

void A::attack(int power)
{
    element -= power;
    if ( element <= 0 )
    {
        delete this;
        b->a[id-1] = NULL;
    }
}

void B::produce()
{
    a[total] = new A(this, 10, total+1);
    total += 1;
}

int main(void)
{
    B base;
    
    cout << (base.a[0] == NULL) << endl;
    
    base.produce();
    base.produce();
    base.produce();
    cout << (base.a[0] == NULL) << endl;
    
    base.a[0]->attack(10);
    cout << (base.a[0] == NULL) << endl;
    
    cout << "----------" << endl;
    cout << (base.a[1] == NULL) << endl;
    base.a[1]->attack(10);
    cout << (base.a[1] == NULL) << endl;
    cout << (base.a[2] == NULL) << endl;
    
    return 0;
}