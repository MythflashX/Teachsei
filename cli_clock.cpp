#include<iostream>
#include<string>
#include<random>
#include"static_array.h"


struct clock_parts
{
  StaticArray<std::string, 152> cli_clock
  {
    "      ", "      ",  "      ",   "  12  ",   "      ", "      ", "      ","\n",
    "      ", "      ",  "      ",   "      ",   "      ", "      ", "      ","\n",
    "      ", "      ",  "      ",   "      ",   "      ", "      ", "      ","\n",
    "      ", "      ",  "  11  ",   "      ",   "  01  ", "      ", "      ","\n",
    "      ", "      ",  "       ",  "      ",   "      ", "      ", "      ","\n",
    "      ", "      ",  "       ",  "      ",   "      ", "      ", "      ","\n",
    "      ", "  10  ",  "      ",  "       ",   "      ", "  02  ", "      ","\n",
    "      ", "       ", "      ",  "       ",   "      ", "      ", "      ","\n",
    "      ", "       ", "      ",  "       ",   "      ", "      ", "      ","\n",
    "  09  ", "      ",  "      ",   "      ",   "      ", "      ", "  03  ","\n",
    "      ", "      ",  "      ",   "      ",   "     ",  "      ", "      ","\n",
    "      ", "      ",  "      ",   "       ",  "      ", "      ", "      ","\n",
    "      ", "  08  ",  "      ",   "      ",   "      ", "  04  ", "      ","\n",
    "      ", "      ",  "      ",   "      ",   "      ", "      ", "      ","\n",
    "      ", "      ",  "      ",   "      ",   "      ", "      ", "      ","\n",
    "      ", "      ",  "  07  ",   "      ",   "  05  ", "      ", "      ","\n",
    "      ", "      ",  "      ",   "      ",   "      ", "      ", "      ","\n",
    "      ", "      ",  "      ",   "      ",   "      ", "      ", "      ","\n",
    "      ", "      ",  "      ",   "  06  ",   "      ", "      ", "      ","\n",
  };
  StaticArray<std::string, 10> one  { "67","    /  ", "59" ,"     / ", "36","  /   ", "44" ," /    ", "52","/     "};
  StaticArray<std::string, 10> two  { "75","      ", "76","------", "77","--/   ",  "69"," /    ", "61","  /   " };
  StaticArray<std::string,  6> three{ "75","      ", "76","------", "77","------" };
  StaticArray<std::string, 10> four { "75","     ", "76","------", "77","-\\    ", "85","  \\  ", "93"," \\   " };
  StaticArray<std::string, 10> five { "83","    \\", "91","     \\", "100","\\    ", "108"," \\   ", "116","  \\  " };
  StaticArray<std::string, 16> six  { "83","   |  ", "91","   |  ", "99","   |  ", "107","   |  ", "115","   |  ", "123", "   |  ", "131", "   |  ", "139","   |  " };
  StaticArray<std::string, 10> seven{ "83","  /   ", "91"," /    ", "99","/     ", "106","     /", "114","    / " };
  StaticArray<std::string, 10> eight{ "75","      ", "74","------", "73","     /", "81","    / ", "89","   /  "  };
  StaticArray<std::string,  6> nine { "75","      ", "74","------", "73","------" };
  StaticArray<std::string, 10> ten  { "75","      ", "74","------", "73","     \\" ,"65","    \\ ", "57","   \\  " };
  StaticArray<std::string, 10>eleven{ "67"," \\    ", "59","\\     ", "51","\\     ", "42","     \\", "34","    \\ " };
  StaticArray<std::string, 16>twelve{ "67","  |   ", "59","  |   ", "27","   |  ", "35","  |   ", "43","  |   ", "51", "   |   ", "19", "   |   ", " 11","   |   " };
};

int ran_gen( int min = 1, int max = 12 )
{
  std::random_device rd{};
  std::mt19937 seed{ rd() };
  std::uniform_int_distribution<> generator( min, max );

  return generator( seed );
}

template<int part_size>
void edit_clock( StaticArray<std::string, 152>& cli_clock, StaticArray<std::string, part_size>& part, bool hand )
{
  int length;
  if( hand == 0 )
    length = part.get_size() - 3;
  else
    length = part.get_size();

  for( int count{ 0 }; count < length; count++ )
  {
    int index{ stoi( part[ count ] ) };
    cli_clock[ index ] = part[ count += 1 ];
  }
}

void assign( int number, clock_parts& obj, bool hand )
{
  switch( number )
  {
    case 1 : edit_clock( obj.cli_clock, obj.one, hand );    break;
    case 2 : edit_clock( obj.cli_clock, obj.two, hand );    break;
    case 3 : edit_clock( obj.cli_clock, obj.three, hand );  break;
    case 4 : edit_clock( obj.cli_clock, obj.four, hand );   break;
    case 5 : edit_clock( obj.cli_clock, obj.five, hand );   break;
    case 6 : edit_clock( obj.cli_clock, obj.six, hand );    break;
    case 7 : edit_clock( obj.cli_clock, obj.seven, hand );  break;
    case 8 : edit_clock( obj.cli_clock, obj.eight, hand );  break;
    case 9 : edit_clock( obj.cli_clock, obj.nine, hand );   break;
    case 10: edit_clock( obj.cli_clock, obj.ten, hand );    break;
    case 11: edit_clock( obj.cli_clock, obj.eleven, hand ); break;
    case 12: edit_clock( obj.cli_clock, obj.twelve, hand ); break;
  }
}

void visual( int& hour, int& minute )
{
  clock_parts obj;
  assign( hour, obj, 0 );
  assign( minute, obj, 1 );

  obj.cli_clock.print();
}

void usr_inpt( int& inpt_hour, int& inpt_minute )
{
  std::cout<<"Enter -> ";
  std::cin>>inpt_hour>>inpt_minute;
}

void check( int hour, int minute, int inpt_hour, int inpt_minute )
{
  if( hour == inpt_hour && minute == inpt_minute )
  {
    if( hour > 1 )
    {
      std::cout<<"\t"<<hour<<" hours & "<<minute<<" minutes\n";
      std::cout<<"\t"<<inpt_hour<<" hours & "<<inpt_minute<<" minutes\n";
    }
    else
    {
      std::cout<<"\t"<<hour<<" hour & "<<minute<<" minutes\n";
      std::cout<<"\t"<<inpt_hour<<" hours & "<<inpt_minute<<" minutes\n";
    }

    std::cout<<"\n\t CORRECT!!!\n\n";
  }

  else
  {
    if( hour > 1 )
    {
      std::cout<<"\t"<<hour<<" hours & "<<minute<<" minutes\n";
      std::cout<<"\t"<<inpt_hour<<" hours & "<<inpt_minute<<" minutes\n";
    }
    else
    {
      std::cout<<"\t"<<hour<<" hour & "<<minute<<" minutes";
      std::cout<<"\t"<<inpt_hour<<" hour & "<<inpt_minute<<" minutes\n";
    }

    std::cout<<"\n\t WRONG!!!\n\n";
  }
}

void stencil();
void run()
{
  std::cout<<"\t\t LEARN TIME!\n\n";
  int hour  { ran_gen() };
  int minute{ ran_gen() };
  int inpt_hour, inpt_minute;
  visual( hour, minute );
  usr_inpt( inpt_hour, inpt_minute );
  minute *= 5;
  check( hour, minute, inpt_hour, inpt_minute );
}

int main()
{
  while( true )
    run();

  return 0;
}

void stencil()
{
  StaticArray<std::string, 152> cli_clock
  {
    "      ", "      ",  "      ",   "  12  ",   "      ", "      ", "      ","\n",
    "      ", "      ",  "      ",   "   |  ",   "      ", "      ", "      ","\n",
    "      ", "      ",  "      ",   "   |  ",   "      ", "      ", "      ","\n",
    "      ", "      ",  "  11  ",   "   |  ",   "  01  ", "      ", "      ","\n",
    "      ", "      ",  "    \\  ",  "  |  ",   "  /   ", "      ", "      ","\n",
    "      ", "      ",  "     \\",  "   |  ",   " /    ", "      ", "      ","\n",
    "      ", "  10  ",  "      \\",  "  |  ",   "/     ", "  02  ", "      ","\n",
    "      ", "   \\  ", "      ",  " \\ | /",  "      ",  "  /   ", "      ","\n",
    "      ", "    \\ ", "      ",  "  \\|/ ",  "      ",  " /    ", "      ","\n",
    "  09  ", "------",  "------",   "---|--",   "------", "------", "  03  ","\n",
    "      ", "    / ",  "      ",   "  /|\\",   "     ",  "   \\ ", "      ","\n",
    "      ", "   /  ",  "      ",   " / | \\",  "      ", "  \\  ", "      ","\n",
    "      ", "  08  ",  "      ",   "/  |  ",   "\\    ", "  04  ", "      ","\n",
    "      ", "      ",  "     /",   "   |  ",   " \\   ", "      ", "      ","\n",
    "      ", "      ",  "    / ",   "   |  ",   "  \\  ", "      ", "      ","\n",
    "      ", "      ",  "  07  ",   "   |  ",   "  05  ", "      ", "      ","\n",
    "      ", "      ",  "      ",   "   |  ",   "      ", "      ", "      ","\n",
    "      ", "      ",  "      ",   "   |  ",   "      ", "      ", "      ","\n",
    "      ", "      ",  "      ",   "  06  ",   "      ", "      ", "      ","\n",
  };
}

StaticArray<std::string, 152> cli_clock_whole
{
  "      ", "      ",  "      ",   "  12  ",   "      ", "      ", "      ","\n",
  "      ", "      ",  "      ",   "   |  ",   "      ", "      ", "      ","\n",
  "      ", "      ",  "      ",   "   |  ",   "      ", "      ", "      ","\n",
  "      ", "      ",  "  11  ",   "   |  ",   "  01  ", "      ", "      ","\n",
  "      ", "      ",  "    \\ ",  "   |  ",   "  /   ", "      ", "      ","\n",
  "      ", "      ",  "     \\",  "   |  ",   " /    ", "      ", "      ","\n",
  "      ", "  10  ",  "      ",  "\\  |  ",   "/     ", "  02  ", "      ","\n",
  "      ", "   \\  ", "      ",  " \\ | /",   "      ", "  /   ", "      ","\n",
  "      ", "    \\ ", "      ",  "  \\|/ ",   "      ", " /    ", "      ","\n",
  "  09  ", "------",  "------",   "---|--",   "------", "------", "  03  ","\n",
  "      ", "    / ",  "      ",   "  /|\\",   "     ",  "   \\ ", "      ","\n",
  "      ", "   /  ",  "      ",   " / | \\",  "      ", "  \\  ", "      ","\n",
  "      ", "  08  ",  "      ",   "/  |  ",   "\\    ", "  04  ", "      ","\n",
  "      ", "      ",  "     /",   "   |  ",   " \\   ", "      ", "      ","\n",
  "      ", "      ",  "    / ",   "   |  ",   "  \\  ", "      ", "      ","\n",
  "      ", "      ",  "  07  ",   "   |  ",   "  05  ", "      ", "      ","\n",
  "      ", "      ",  "      ",   "   |  ",   "      ", "      ", "      ","\n",
  "      ", "      ",  "      ",   "   |  ",   "      ", "      ", "      ","\n",
  "      ", "      ",  "      ",   "  06  ",   "      ", "      ", "      ","\n",
};

