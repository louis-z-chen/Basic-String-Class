//Problem 6

#include <iostream>
#include <stdexcept>
#include <cstring>
#include "str.h"

using namespace std;

//Constructors
Str::Str(){
	data_ = new char[0];
	strlength = 0;
}

Str::Str(const char* s){
	if ( s[0] == '\0'){
		data_ = new char[0];
		strlength = 0;
	}
	else{
		size_t charcount = 0;
		while( s[charcount] != '\0'){
			charcount++;
		}
		data_ = new char[charcount];
		for (size_t i = 0; i < charcount; i++){
			data_[i] = s[i];
		}
		strlength = charcount;
	}
}

Str::Str(const Str& rhs){
	data_ = new char[rhs.size()];
	for (size_t i = 0; i < rhs.size(); i++){
		data_[i] = rhs[i];
	}
	strlength = rhs.size();
}

Str::~Str(){
	delete[] data_;
}

//Comparison Operators
bool Str::operator==(const Str &rhs){
	bool temp;
	if (compare(rhs) == 0){
		temp = true;
	}
	else{
		temp = false;
	}
	return temp;
}

bool Str::operator!=(const Str &rhs){
	bool temp;
	if (compare(rhs) != 0){
		temp = true;
	}
	else{
		temp = false;
	}
	return temp;
}

bool Str::operator<(const Str &rhs){
	bool temp;
	if (compare(rhs) < 0){
		temp = true;
	}
	else{
		temp = false;
	}
	return temp;
}

bool Str::operator>(const Str &rhs){
	bool temp;
	if (compare(rhs) > 0){
		temp = true;
	}
	else{
		temp = false;
	}
	return temp;
}

bool Str::operator<=(const Str &rhs){
	bool temp;
	if (compare(rhs) <= 0){
		temp = true;
	}
	else{
		temp = false;
	}
	return temp;
}

bool Str::operator>=(const Str &rhs){
	bool temp;
	if (compare(rhs) >= 0){
		temp = true;
	}
	else{
		temp = false;
	}
	return temp;
}

//String Concatenation Operators
Str Str::operator+(const char* rhs) const{
	if(rhs[0] == '\0'){
		return *this;
	}
	Str temp = *this;
	return (temp += Str(rhs));
}

Str Str::operator+(const Str& rhs) const{
	if(rhs.empty()){
		return *this;
	}
	Str temp = *this;
	return (temp += rhs);
}

Str operator+(const char* lhs, const Str& rhs){
	Str temp;
	size_t lhscount = Str(lhs).size();
	size_t newlength = lhscount + rhs.size();
	char* newdata = new char[newlength];
	for (size_t i = 0; i < lhscount; i++){
		newdata[i] = lhs [i];
	}
	for (size_t i = 0; i < rhs.size(); i++){
		newdata[lhscount + i] = rhs[i];
	}
	delete[] temp.data_;
	temp.data_ = newdata;
	temp.strlength = newlength;
	return temp;
}

//Assignment Operators

Str& Str::operator=(const char* s){
	if(compare(Str(s)) == 0){
		return *this;
	}
	else{
		delete[] data_;
		size_t charcount = Str(s).size();
		data_ = new char[charcount];
		for (size_t i = 0; i < charcount; i++){
			data_[i] = s[i];
		}
		strlength = charcount;
	}
	return *this;
}

Str& Str::operator=(const Str& s){
	if(compare(Str(s)) == 0){
		return *this;
	}
	else{
		delete[] data_;
		size_t newlength = s.size();
		data_ = new char[newlength];
		for (size_t i = 0; i < newlength; i++){
			data_[i] = s[i];
		}
		strlength = newlength;
	}
	return *this;
}

Str& Str::operator+=(const Str& s){
	if(s.size() == 0){
		return *this;
	}
	size_t newlength = strlength + s.size();
	char* newdata = new char[newlength];
	for (size_t i = 0; i < strlength; i++){
		newdata[i] = data_[i];
	}
	delete[] data_;
	for (size_t i = 0; i < s.size(); i++){
		newdata[strlength + i] = s[i];
	}
	strlength = newlength;
	data_ = newdata; 
	return *this;
}


Str& Str::operator+=(const char* s){
	if (s[0] == '\0'){
		return *this;
	}
	size_t charcount = 0;
	while( s[charcount] != '\0'){
		charcount++;
	}
	size_t newlength = strlength + charcount;
	char* newdata = new char[newlength];
	for (size_t i = 0; i < strlength; i++){
		newdata[i] = data_[i];
	}
	delete[] data_;
	for (size_t i = 0; i < charcount; i++){
		newdata[strlength + i] = s[i];
	}
	strlength = newlength;
	data_ = newdata; 
	return *this;
}

//I/O Stream Operators
std::ostream& operator<<(std::ostream& istr, const Str& s){
	if(!s.empty()){
		for (size_t i = 0; i < s.size(); i++){
			istr << s[i];
		}
	}
	else{
		istr << "";
	}
	return istr;
}

std::istream& operator>>(std::istream& istr, Str& s){
  std::string stemp;
  istr >> stemp;
  s = stemp.c_str();
  return istr;
}


//Accessor & Misc Functions
size_t Str::size() const{
	return strlength;
}

char& Str::operator[](unsigned int i){
	if (i >= strlength){
		throw std::out_of_range("Index is out of range");
	}
	return data_[i];
}

char const & Str::operator[](unsigned int i) const{
	if (i >= strlength){
		throw std::out_of_range("Index is out of range");
	}
	return data_[i];
}

bool Str::empty() const{
	if(strlength == 0){
		return true;
	}
	else{
		return false;
	}
}

//Private helper function
int Str::compare(const Str& rhs) const{
	if(empty() && rhs.empty()){
		return 0;
	}
	if(!empty() || !rhs.empty()){
		if (strlength > rhs.strlength){
			return 1;
		}
		else if (strlength < rhs.strlength){
			return -1;
		}
	}
	return strcmp(data_, rhs.data_);
}