#include <iostream>
using namespace std;
// TODO 123

class Base
{
    private:
        int x = 0;
    public:
        friend void foo(const Base& x);
};



class not_Base : public Base
{
    private:
        int x = 1;
};

class not_Base_with_friend : public Base
{
    private:
        int x = 2;
    public:
        friend void foo(const not_Base_with_friend& x);
};

void foo(const Base& x)
{
    cout << "Here is" << " " <<  x.x << endl;
}

void foo(const not_Base_with_friend& x)
{
    cout << "Here is" << " " <<  x.x << endl;
}

int main()
{
    Base a;
    not_Base b;
    not_Base_with_friend c;
    foo(b); // prints 0
    foo(c); // prints 2
    // friends are not inherited
    return 0;
}
