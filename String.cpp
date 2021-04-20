#include"String.h"

String::String(char* str, const int length){
	if (length < 0)
	{
		_value = nullptr;
		_length = 0;
		return;
	}
	_value = new char[length];
	if (str != nullptr)
		for (int i = 0; i < length; i++)
			_value[i] = str[i];
	_length = length;
}

String::String(const String& other) :
	String(other._value, other._length)
{}

String& String::operator= (const String& other){
	if (this == &other)
		return *this;
	for (int i = 0; i < other._length; i++)
		*(_value + i) = *(other._value + i);
	_length = other._length;
	return *this;
}

int String::Compare(String& other) {
	int minLength = _length < other._length ? _length : other._length;
	for (int i = 0; i < minLength; i++)
	{
		int thisValue = std::tolower(_value[i]);
		int otherValue = std::tolower(other._value[i]);
		if (thisValue < otherValue)
			return 1;
		else if (thisValue > otherValue)
			return -1;
	}

	if (_length < other._length)
		return -1;
	if (_length > other._length)
		return 1;
	return 0;
}

int String::getLength()
{
	return _length;
}

void String::setLength(int value)
{
	if (value < 0)
		return;
	char* copy = std::move(_value);
	_value = new char[value];
	for (int i = 0; i < _length; i++)
		_value[i] = copy[i];
	_length = value;
}

char& String::operator[](int index)
{
	if (index > _length)
		throw;
	return *(_value + index);
}

String::~String()
{
	delete[] _value;
}

std::ostream& operator<<(std::ostream& out, const String& str)
{
	for (int i = 0; i < str._length; i++)
		out << str._value[i];

	return out;
}

String& operator+(String& first, String& second)
{
	String& res = *(new String());
	res.setLength(first.getLength() + second.getLength());
	for (int i = first.getLength(); i < res.getLength(); i++)
		res[i] = second[i - first.getLength()];

	return res;
}
