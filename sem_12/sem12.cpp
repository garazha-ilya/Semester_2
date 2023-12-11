#include <iostream>
using namespace std;

template <typename T>
class MyClass
{
public:
    MyClass(T val) : m_val(val) {}
    void print() { std::cout << m_val << std::endl; }
    MyClass &operator++()
    {
        ++m_val;
        return *this;
    }

private:
    T m_val;
};

int main()
{
    // 1
    //const MyClass<int> object = 3.14;
    //object.print();
    // не будет компилироваться, так как метод print() не const, тем самым нет гарантий, что этот метод не меняет константный объект

    // 2
    //MyClass<const int> object = 3.14;
    //(++object).print();
    // const int не скомпилируется, так как мы будем пытаться сделать операцию изменения с константным объектом внутри класса

    // 3
    //(++MyClass<int>(3.14)).print();
    // здесь создаётся экземпляр класса MyClass от 3.14, который неявно преобразуется в 3, после чего вызывается префиксный оператор
    // а затем, метод print(), так как int поддерживает изменение, то всё пройдёт корректно


    return 0;
}