#ifndef STATIC_ARRAY_H
#define STATIC_ARRAY_H

#include<iostream>
#include<initializer_list>
#include<cassert>

template <typename T, int size>
class StaticArray
{
  private:
    T m_data[ size ];

  public:
    StaticArray() = default;
    StaticArray( std::initializer_list<T> list )
    {
      int count{ 0 };
      for( T element : list )
      {
        m_data[ count ]  = element;
        count++;
      }
    }

    T& operator[]( int index ) { return m_data[ index ]; }

    void print()
    {
      for( int count{ 0 }; count < size; count++ )
        std::cout<<m_data[ count ];
    }

    void indices( int line_skip )
    {
      for( int count{ 0 }; count < size; count++ )
      {
        if( ( count % line_skip ) == 0 )
          std::cout<<std::endl;
        std::cout<<count<<'\t';
      }
    }

    int get_size() const { return size; }
};

#endif
