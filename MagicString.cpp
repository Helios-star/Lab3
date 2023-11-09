/* 
 * File:   MagicString.cpp
 * Purpose: provide the definition of the MagicString class
 *
 * Author: (your name)
 *
 */
#include <iostream>
#include <stack>
#include "MagicString.h"

// initialize str with ini_str passing as a parameter
MagicString::MagicString(string ini_str)
{
  str = ini_str;
}

// return the current value of the private data member: str
string MagicString::getString() const
{
  return str;
}

// set the value of str to be the passed in parameter input_str
void MagicString::setString(string input_str)
{
  str = input_str;
}

// return a reverse string
// using a loop to implement
// Note that the private data member named str, has not been changed
string MagicString::rev_loop() const
{
  int strLength = str.length();
  string tempString = str;
  int n = strLength - 1;   // The value for the last possibile charcter
  int i = 0;     // The value for the first possibile charcter.
  while(i <= n)
    {
      swap(tempString[i], tempString[n]);    // Switches the charcters at their given positions.
      n -= 1;        // Decreases by 1 each loop
      i += 1;        // Increases by 1 each loop
    }         // Loop will end when the position marker 'i' passes 'n'.
  return tempString;
}

// return a reverse string
// using recursion to implement
// Note that the private data member named str, has not been changed
string MagicString::rev_recursion() const
{
  if (str.length() <= 1) { return str;} // Base case
  char firstLetter = str[0];        // Gathers the first letter of the str
  string shorter = str.substr(1, str.length() -  1);    // Creates a string thatthat no longer has the first letter.
  MagicString tempString(shorter);   // Creates an object for recursion
  return tempString.rev_recursion() + firstLetter; // Creates a recursion which moves the first letter to the end each time.
}

// return a reverse string
// using a stack to implement
// Note that the private data member named str, has not been changed
string MagicString::rev_stack() const
{
  // Places the string into a stack.
  stack<char> rev_string;
  string tempString = str;
  for (int i = 0; i < str.length(); i++)
    {
      // Pushes the charcters into the stack.
      rev_string.push(str[i]);
    }

  for (int i = 0; i < str.length(); i++)
    {
      // Pops the charcters back onto string.
      tempString[i] = rev_string.top();
      rev_string.pop();
    }
  return tempString;
}

// return true if str is a palindrome
// otherwise return false
// A palindrome is defined as a sequence of characters which reads the same backward as forward
// calling member function to  implement
// Note that the private data member named str, has not been changed
bool MagicString::isPalindrome() const
{
  MagicString temp(str);
  string tempString = temp.rev_stack();
  if( str == tempString)
    {return true;}
  else
    {return false;}
}
        
// return true if str is a palindrome
// otherwise return false
// A palindrome is defined as a sequence of characters which reads the same backward as forward
// using recursion to implement
// Note that the private data member named str, has not been changed
bool MagicString::isPalindrome_recursion() const
{
  // Base case.
  if (str.length() <= 1)
    {return true;}
  else
    {
      MagicString shorter(str.substr(1, str.length() - 2));
      bool firstPair = str[0] == str[str.length() - 1 ];
      return ( firstPair && shorter.isPalindrome_recursion());
    }
}
        
// displays str followed by a new line marker
// to the standard output
void MagicString::print() const
{
  std::cout << str << std::endl;
}
