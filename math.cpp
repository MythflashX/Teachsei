#include<iostream>
#include<random>
#include<ctime>

template< typename T >
T add( T x, T y ) { return x+y; }
template< typename T >
T sub( T x, T y ) { return x-y; }
template< typename T >
T mul( T x, T y ) { return x*y; }
template< typename T >
T div( T x, T y ) { return x/y; }

template< typename T>
T ran_gen( int min = 0, int max = 9 )
{
  std::random_device rd;
  std::mt19937 seed{ rd() };
  std::uniform_int_distribution<> generator( min, max );

  return generator( seed );
}

char generate_operator( int input, int& answer, int& first_value, int& second_value )
{
  switch( input )
  {
    case 0 : answer = first_value + second_value; return '+';
    case 1 : second_value = ran_gen<int>( 0, first_value ); answer = first_value - second_value; return '-';
    case 2 : answer = first_value * second_value; return '*';
    case 3 : second_value = ran_gen<int>( 0, first_value ); answer = first_value / second_value; return '/';
    default: return 'E';
  }
}

void operation( int& point )
{
  int first_value{ ran_gen<int>() };
  int second_value{ ran_gen<int>() };
  int answer;
  char math_operator{ generate_operator( ran_gen<int>( 0, 1 ), answer, first_value, second_value ) };

  std::cout<<"\tLEARN MATH!\n\n";
  std::cout<<"Points : "<<point<<"\n\n";
  std::cout<<"\t "<<first_value<<' '<<math_operator<<' '<<second_value <<" = ";
  int input;
  std::cin>>input;


  if( input == answer )
  {
    std::cout<<"\t "<<first_value<<' '<<math_operator<<' '<<second_value <<" = "<<answer<<'\n';
    std::cout<<"\n\tCorrect!!!\n\n";
    point++;
  }
  else
  {
    std::cout<<"\t "<<first_value<<' '<<math_operator<<' '<<second_value <<" = "<<answer<<'\n';
    std::cout<<"\n\tWrong!!!\n\n";
    point = 0;
  }
}

int main()
{
  int point{ 0 };
  while( true )
    operation( point );

  return 0;
}
