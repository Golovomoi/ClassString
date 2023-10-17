#include "../headers/AwsomeIterator.h"

AwsomeIterator::AwsomeIterator(char* p) : ptr(p){}

char& AwsomeIterator::operator*()
{
    return *ptr;
}

AwsomeIterator& AwsomeIterator::operator++()
{
    ptr++;
    return *this;
}

bool AwsomeIterator::operator!=(const AwsomeIterator& other) const
{
    return ptr != other.ptr;
}
