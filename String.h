#pragma once
#include <iostream>

class String{
public:
	String(char* str = nullptr, const int length = 0);
	String(const String& other);
	String(String&& other) noexcept :
		_value(std::move(other._value)),
		_length(std::exchange(other._length, 0)) {
		other._value = nullptr;
	};

	String& operator= (const String& other);
	friend std::ostream& operator<< (std::ostream& out, const String& str);

	int Compare(String& other);

	int getLength();
	void setLength(int value);

	char& operator[] (int index);

	~String();

private:
	char* _value;
	int _length;
};

String& operator+ (String& first, String& second);