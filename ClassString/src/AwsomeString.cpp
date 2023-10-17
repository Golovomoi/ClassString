#include "../headers/AwsomeString.h"

AwsomeString::AwsomeString()
{
    _size = 0;
    _data = new char[1];
    _data[0] = '\0';
}

AwsomeString::AwsomeString(const char* str)
{
    CopyData(str);
}

AwsomeString::AwsomeString(const AwsomeString& other)
{
    CopyData(other._data);
}

AwsomeString::AwsomeString(AwsomeString&& other) noexcept
{
    _data = other._data;
    _size = other._size;

    other._data = nullptr;
    other._size = 0;
}

char* AwsomeString::GetRawData() const
{
    return _data;
}

size_t AwsomeString::GetLength() const
{
    return _size;
}

AwsomeIterator AwsomeString::begin()
{
    return AwsomeIterator(_data);
}

AwsomeIterator AwsomeString::end()
{
    if (_size == 0) {
        return nullptr;
    }
    // „t„|„‘ „„„€„s„€ „‰„„„€„q„ „y„„„u„‚„p„„„€„‚ „…„{„p„x„„r„p„| „~„p „x„~„p„‰„u„~„y„u „x„p „„€„ƒ„|„u„t„~„y„} „„|„u„}„u„~„„„€„} „r„ƒ„u„s„t„p „y„}„u„u„} „€„t„~„… „‘„‰„u„z„{„… „ƒ „ƒ„y„}„r„€„|„€„} '\0'
    return AwsomeIterator(_data + _size + 1);
}

AwsomeString& AwsomeString::operator=(const AwsomeString& other)
{
    if (this == &other) {
        return *this;
    }
    delete _data;
    CopyData(other._data);
    return *this;
}

AwsomeString& AwsomeString::operator=(const char* str)
{
    delete _data;
    CopyData(str);
    return *this;
}

AwsomeString::~AwsomeString()
{
    delete _data;
    _data = nullptr;
}

size_t AwsomeString::GetStrLength(const char* str) const
{
    size_t length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}

void AwsomeString::CopyData(const char* data)
{
    size_t i = 0;
    _size = GetStrLength(data);
    // „ƒ„€„x„t„p„u„} „~„p „€„t„y„~ „„|„u„}„u„~„„ „q„€„|„„Š„u „‰„„„€„q„ „~„p „~„u„s„€ „…„{„p„x„„r„p„| „y„„„u„‚„p„„„€„‚ „y „„„„€„„ „w„u „ƒ„y„}„r„€„| „q„…„t„u„„ '\0'
    _data = new char[_size + 1];
    while ((i < _size) && (data[i] != '\0'))
    {
        _data[i++] = data[i];
    }
    _data[_size] = '\0';
}
