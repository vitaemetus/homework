#include <cstddef>
#include <iostream>

template <typename T>
class Array
{
public: 
    explicit Array(std::size_t sz, const T& value){
        m_start = new T[sz];
        m_size = sz;
        for (std::size_t i = 0; i < sz; i++){
            *(m_start + i*sizeof(T)) = value;
        }
    }

    Array(const Array &);
    //   конструктор копирования, который создает
    //   копию параметра. Считайте, что для типа
    //   T определен оператор присваивания.
    //
    
    Array(const Array &&);
    //   конструктор перемещения
    //

    ~Array();
    //   деструктор, если он вам необходим.
    //

    Array& operator=(const Array &);
    //   оператор копирующего присваивания.
    //

    Array& operator=(Array &&);
    //   оператор перемещающего присваивания.
    //

    size_t size() const;
    //   возвращает размер массива (количество
    //                              элементов).
    //

    T& operator[](size_t idx);
    const T& operator[](size_t idx) const;
    //   две версии оператора доступа по индексу.

    void print(){
        for (std::size_t i = 0; i < m_size; i++){
            std::cout<<*(m_start+i*sizeof(T))<<' ';
        }
    }

private:
    T* m_start;
    std::size_t m_size;
};

int main(){
    Array<int> a(10, 0);
    a.print();
    return 0;
}
