#include <iostream>
#include "foo.h"
using namespace std;

template <typename T>
void foo(T) { cout << "1" << endl; }
template <typename T>
void foo(T *) { cout << "2" << endl; }
template <>
void foo<char *>(char *) { cout << "3" << endl; }
template <>
void foo<char>(char *) { cout << "4" << endl; }


class Person {
public:
Person(const char* name, size_t age) : m_name(name), m_age(age) {}
private:
const char* m_name;
size_t m_age;
};

// --------- 5 ---------
template <typename T1, typename T2>
decltype(auto) sum(const T1 & left, const T2 & right) {
    auto result = left + right;
return result;
} // В качестве возврщаемого значения будет выбран более общий типа данных, поэтому с помощью decltype мы создаём возвращаемое значение переданного типа

int main()
{
    // --------- 1 ---------
    int i = int(); // <-- конструктор типа int
    foo(i); // <-- выведется 1, так как спецификаторы другого типа, то есть самым частным случаем является шаблон 1
    foo(&i); // <-- выведется 2, так как снова спецификаторы имеют тип, отличный от данного и более частным решением есть шаблон функции от T с аргументом
    // функции являющимся указателем на переменную типа T
    // --------- 2 ---------
    char c = char(); // <-- конструктор типа char
    foo(c); // <-- здесь вновь нет подходящего спецификатора для аргумента типа char, поэтому наиболее частным является шаблон 1
    foo(&c); // <-- мы вызываем специализацию для ссылки на char, при этом выбирается более частная специализация с приоритетом char
    // --------- 3 ---------
    // Не была вызвана перегрузка номер 3.
    // Вызов происходит следующим образом:
    char * f = new char();
    foo<char *>(f);
    // Такой вызов вызывает третью перегрузку, так как мы указываем какая именно специализация нам нужна
    // --------- 4 ---------
    //Person* ptr = new Person; <-- не работает в связи с тем, что у класса Person отсутсвует конструктор по умолчанию
    // Чтобы заработало нужно или создать конструктор по умолчанию, или добавить передачу параметров
    // --------- 6 ---------
    foo(10); // В c++ файлы компилируются отдельно, а шаблоны будут создавать свою версию программы для каждого вида параметров, с которыми его используют
    // в этом случае этого не произойдёт, так как cpp файлы встретятся только на этапе линковки, а не на этапе компиляции, и функция не будет знать
    // о том, что её используют в main()
    return 0;
}