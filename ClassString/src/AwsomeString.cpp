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

AwsomeIterator AwsomeString::begin() const
{
    return AwsomeIterator(_data);
}

AwsomeIterator AwsomeString::end() const
{
    if (_size == 0) {
        return nullptr;
    }
    // для того чтобы итератор указывал на значение за последним элементом всегда имеем одну ячейку с символом '\0'
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

bool AwsomeString::operator<(const AwsomeString& str) const
{
    auto first = this->begin();
    auto second = str.begin();

    while (first != this->end()) {
        if (second == str.end())
            return false;
        int firstChar, secondChar;
        // согласно задаче нам нужно сравнивать строки игнорируя регистр
        firstChar = std::tolower(*first);
        secondChar = std::tolower(*second);
        if (firstChar == secondChar) {
            ++first;
            ++second;
            continue;
        }
        return firstChar < secondChar;
    }
    return true;
}

AwsomeString operator+(const char*str, const AwsomeString& aStr)
{
    AwsomeString result(str);
    result += aStr._data;
    return result;
}

std::ostream& operator<<(std::ostream& os, const AwsomeString& str)
{
    os << str._data;
    return os;
}

std::istream& operator>>(std::istream& is, AwsomeString& str)
{
    // считываем строки такой максимальной длинны.
    char buffer[1024];
    is.getline(buffer, sizeof(buffer));

    delete[] str._data;
    str.CopyData(buffer);

    return is;
}

AwsomeString::~AwsomeString()
{
    delete[] _data;
    _data = nullptr;
}

void AwsomeString::AddString(const char* str)
{
    size_t adStrLen = GetStrLength(str);
    // тут бы можно было воспользоаться оптимизацией и не всегда выделять новую память, но в задании явно указано что этого делать не надо.
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

//можно было бы использовать strlen, но сделаю всё своё.
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
    // создаем на один элемент больше чтобы на него указывал итератор и этот же символ будет '\0'
    _data = new char[_size + 1];
    // копируем данные и на всякий случай проверяем, что не вылазим за границы выделенной памяти, в противном случае обрезаем там где память кончается.
    while ((i < _size) && (data[i] != '\0')){
        _data[i++] = data[i];
    }
    _data[_size] = '\0';
}
