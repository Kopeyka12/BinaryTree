#pragma once
//@avtor Мирошин В. И.
//Абстрактный класс Итератора 
template <typename T>
// абстрактный класс итератора
class AbsIterator
{
public:
    // оператор перехода на следующий элемент
    virtual AbsIterator<T>& operator++() = 0;
    //virtual void operator++(int) const {};
    // оператор получения данных их элемента
    virtual T operator*() const = 0;
    // операторы сравнения
    virtual bool operator==(const AbsIterator& o) const = 0;
    virtual bool operator!=(const AbsIterator& o) const = 0;

};