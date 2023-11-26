#include <cstddef>
#include <iostream>

template <typename T>
class Array
{
public: 
    explicit Array(std::size_t sz, const T& value){
        m_start = new T[sz];
        m_size = sz;
        for (std::size_t i = 0; i < m_size; i++){
            *(m_start + i*sizeof(T)) = value;
        }
    }

    Array(const Array& arr){
        m_start = new T[arr.m_size];
        m_size = arr.m_size;
        for (std::size_t i = 0; i < m_size; i++){
            *(m_start + i*sizeof(T)) = *(arr.m_start + i*sizeof(T));
        }
    }

    Array(Array && arr){
        m_start = arr.m_start;
        m_size = arr.m_size;
        arr.m_size=0;
        arr.m_start=nullptr;
    }

    Array& operator=(const Array & arr){
        if (m_size < arr.m_size){
            delete m_start;
            m_start = new T[arr.m_size];
        }
        for (std::size_t i = 0; i < arr.m_size; i++){
            *(m_start + i*sizeof(T)) = *(arr.m_start + i*sizeof(T));
        }
        m_size = arr.m_size;
        return *this;
    }

    size_t size() const{
        return m_size;
    }

    T& operator[](size_t idx){
        return *(m_start + idx*sizeof(T));
    }
    const T& operator[](size_t idx) const{
        return *(m_start + idx*sizeof(T));
    }

    void print(){
        for (std::size_t i = 0; i < m_size; i++){
            std::cout<<*(m_start+i*sizeof(T))<<' ';
        }
        std::cout<<"\n";
    }

private:
    T* m_start;
    std::size_t m_size;
};

int main(){
    Array<int> a(10, 2);
    a.print();

    Array b(std::move(a));
    b.print();
    std::cout<<a.size()<<std::endl;

    Array<int> c(10, 1);
    a = c;
    a.print();
    b.print();
    
    return 0;
}
