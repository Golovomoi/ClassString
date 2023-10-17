#pragma once
#ifndef AWSOMESTRING_H
#define AWSOMESTRING_H
#include "../headers/AwsomeIterator.h"

class AwsomeString{
public:
    AwsomeString();
    AwsomeString(const char*);
    AwsomeIterator begin();
    AwsomeIterator end();

private:
    size_t size;
    char* data;
};
#endif // AWSOMESTRING_H
