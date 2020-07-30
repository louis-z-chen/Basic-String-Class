#ifndef STR_H
#define STR_H
#include <iostream>

//-----------------------------------------------
// This file is not complete. You will need to
// add prototypes for the needed member functions
// based on the usage of str_test.cpp.
//-----------------------------------------------

class Str {
public:

//Constructors
   /**
   * Default constructor should create a string
   * equal to ""
   */
  Str();

   /**
   * Character array constructor
   *  If s is NULL create a string that contains
   *  only the null character (i.e. "")
   */
   Str(const char* s);

  //copy constructor
  Str(const Str& rhs);

  //deconstructor
  ~Str();

//Comparison Operators
  //==
  bool operator==(const Str &rhs);

  //!=
  bool operator!=(const Str &rhs);

  //<
  bool operator<(const Str &rhs);

  //>
  bool operator>(const Str &rhs);

  //<=
  bool operator<=(const Str &rhs);

  //>=
  bool operator>=(const Str &rhs);


//String Concatenation Operators
    /**
    * String concatenation operator
    *  E.g. str s1; cout << s1 + " world" << endl;
    *  If rhs is NULL, simply return a copy of this Str
    */
    Str operator+(const char* rhs) const;

    Str operator+(const Str& rhs) const;

    friend Str operator+(const char* lhs, const Str& rhs);

//Assignment Operators
   /**
   * Assignment operator
   * If s is NULL, set this to a blank string ("")
   */
  Str& operator=(const char* s);

  Str& operator=(const Str& s);

   /**
   * Str concatenation-assignment operator
   *  E.g. s += t
   */
   Str& operator+=(const Str& s);

   /**
   * Char. array concatenation-assignment operator
   *  E.g. s += " more"
   *  If s is NULL simply return this Str
   */
   Str& operator+=(const char* s);

//I/O Stream Operators
     /**
    * istream (<<) operator
    */
   friend std::ostream& operator<<(std::ostream& istr, const Str& s);

   //>>
   friend std::istream& operator>>(std::istream& istr, Str& s);

//Accessor & Misc Functions
   /**
   * Return the size of the string (e.g. "Hello" => 5)
   */
   size_t size() const;

   /**
    * Non-const index operator
    *  E.g.  str s1("103");  s1[2] = '4';
    * Should throw std::out_of_range if invalid index is passed
    */
   char& operator[](unsigned int i);

   /**
    * Const index operator
    *  E.g. str s1("104");  char c = s1[2];
    * Should throw std::out_of_range if invalid index is passed
    */
   char const & operator[](unsigned int i) const;

   //function to test if empty
   bool empty() const;

private:
   char* data_;
   //new private variable to keep track of string length
   size_t strlength;
   //helper function to compare strings
   int compare(const Str& rhs) const;

 };

#endif
