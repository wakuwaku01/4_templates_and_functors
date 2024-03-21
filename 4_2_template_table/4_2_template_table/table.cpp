// 4_2_template_table

#include <iostream>

template <class T>
class Table {
private:
    int rows;
    int columns;
    T** table = nullptr;

public:
 
    Table (const Table& rhs) { operator=(rhs); }
 
    Table& operator=(const Table& rhs)
    {
        if (this == &rhs) return *this;
        return *this;
    }

    //Table(const Table&) = delete; //конструктор копирования
    //Table & operator= (const Table&) = delete; //оператор присваивания

    Table(int rows_count, int columns_count) : rows(rows_count), columns(columns_count) 
    {
        table = new T * [rows];
        for (int i = 0; i < rows; i++) 
        {
            table[i] = new T[columns];
        }
    }

    ~Table() {
        for (int i = 0; i < rows; i++) 
        {
            delete[] table[i];
        }
        delete[] table;
    }

    T* operator[](int i) 
    {
        return table[i];
    }

    T* operator[](const int i) const 
    {
        return table[i];
    }

    int size() const 
    {
        return rows * columns;
    }
};

int main()
{
    setlocale(LC_ALL, "Rus");

    auto test = Table <int>(2, 3);
    test[0][0] = 4;
    std::cout << test[0][0] << std::endl;
    std::cout << "Size: " << test.size() << std::endl;

    {
        Table<int> t1(2, 3);
        Table<int> t2(2, 3);
        t1 = t2;
    } // Программа упадет здесь?

    {
        Table<double> t1(2, 3);
        Table<double> t3(t1);
    }

    return 0;
}
