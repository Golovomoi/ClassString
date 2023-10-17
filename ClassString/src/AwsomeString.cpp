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
    delete[] _data;
    CopyData(other._data);
    return *this;
}

AwsomeString& AwsomeString::operator=(const char* str)
{
    delete[] _data;
    CopyData(str);
    return *this;
}

AwsomeString& AwsomeString::operator+=(const AwsomeString& other)
{
    AddString(other._data);
    return *this;
}

AwsomeString& AwsomeString::operator+=(const char* str)
{
    AddString(str);
    return *this;
}

AwsomeString AwsomeString::operator+(const AwsomeString& other) const
{
    AwsomeString result(_data);
    result += other._data;
    return result;
}

AwsomeString AwsomeString::operator+(const char* str) const
{
    AwsomeString result(_data);
    result += str;
    return result;
}

AwsomeString operator+(const char*str, const AwsomeString& aStr)
{
    AwsomeString result(str);
    result += aStr._data;
    return result;
}

AwsomeString::~AwsomeString()
{
    delete[] _data;
    _data = nullptr;
}

void AwsomeString::AddString(const char* str)
{
    size_t adStrLen = GetStrLength(str);
    // „„„…„„ „q„ „}„€„w„~„€ „q„„|„€ „r„€„ƒ„„€„|„„x„€„p„„„„ƒ„‘ „€„„„„y„}„y„x„p„ˆ„y„u„z „y „~„u „r„ƒ„u„s„t„p „r„„t„u„|„‘„„„ „~„€„r„…„ „„p„}„‘„„„, „~„€ „r „x„p„t„p„~„y„y „‘„r„~„€ „…„{„p„x„p„~„€ „‰„„„€ „„„„€„s„€ „t„u„|„p„„„ „~„u „~„p„t„€.
    char* newData = new char[_size + adStrLen + 1];
    for (auto i = 0; i < _size; i++){
        newData[i] = _data[i];
    }
    for (auto i = 0; i < adStrLen; i++) {
        newData[i + _size] = str[i];
    }

    _size = _size + adStrLen;
    newData[_size] = '\0';
    delete[] _data;
    _data = newData;
}

//„}„€„w„~„€ „q„„|„€ „q„ „y„ƒ„„€„|„„x„€„r„p„„„ strlen, „~„€ „ƒ„t„u„|„p„ „r„ƒ„v „ƒ„r„€„v.
size_t AwsomeString::GetStrLength(const char* str) const
{
    size_t length = 0;
    while (str[length] != '\0'){
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
    // „{„€„„y„‚„…„u„} „t„p„~„~„„u „y „~„p „r„ƒ„‘„{„y„z „ƒ„|„…„‰„p„z „„‚„€„r„u„‚„‘„u„}, „‰„„„€ „~„u „r„„|„p„x„y„} „x„p „s„‚„p„~„y„ˆ„ „r„„t„u„|„u„~„~„€„z „„p„}„‘„„„y, „r „„‚„€„„„y„r„~„€„} „ƒ„|„…„‰„p„u „€„q„‚„u„x„p„u„} „„„p„} „s„t„u „„p„}„‘„„„ „{„€„~„‰„p„u„„„ƒ„‘.
    while ((i < _size) && (data[i] != '\0')){
        _data[i++] = data[i];
    }
    _data[_size] = '\0';
}
