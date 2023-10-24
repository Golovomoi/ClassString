#pragma once
#ifndef AWSOMEITERATOR_H
#define AWSOMEITERATOR_H

class AwsomeString;
// итератор можно вложить в сам класс строки, но решил его вынести отдельно
// сделал итератор для удобства
class AwsomeIterator
{
private:
    char* ptr;
public:
    AwsomeIterator(char* p);

    char& operator*();
    AwsomeIterator& operator++();
    bool operator!=(const AwsomeIterator&) const;
    bool operator==(const AwsomeIterator&) const;
};

#endif // AWSOMEITERATOR_H
