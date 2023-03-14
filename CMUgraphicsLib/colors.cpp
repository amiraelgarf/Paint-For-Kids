/* 
See "version.h" for version info and copyright information
This file was last modified on 05.16.1999
*/

#include "colors.h"

bool operator==(color a, color b) {

  return ((a.ucRed == b.ucRed) && (a.ucGreen == b.ucGreen) && (a.ucBlue == b.ucBlue));

}

bool operator!=(color a, color b) {

  return !(a == b);
  
}

string color::Color_to_String() const
{
	if (*this == RED)
		return "RED";
	if(*this==BLUE)
		return "BLUE";
	if(*this==BLACK)
		return "BLACK";
	if(*this==YELLOW)
		return "YELLOW";
	if(*this==ORANGE)
		return "ORANGE";
	if (*this==GREEN)
		return "GREEN";
	return "invalid";
}
void color::String_to_Color(string s)
{
	if (s=="BLACK")
		*this=BLACK;
	if (s=="YELLOW")
		*this=YELLOW;
	if (s=="ORANGE")
		*this=ORANGE;
	if (s=="RED")
		*this=RED;
	if (s=="GREEN")
		*this=GREEN;
	if (s=="BLUE")
		*this=BLUE;
}