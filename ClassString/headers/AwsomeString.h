#pragma once
#ifndef AWSOMESTRING_H
#define AWSOMESTRING_H
#include "../headers/AwsomeIterator.h"

class AwsomeString{
public:
    AwsomeString();
    AwsomeString(const char*);
    AwsomeString (const AwsomeString&);
    AwsomeString(AwsomeString&& other) noexcept;

    char* GetRawData() const;
    size_t GetLength() const;

    AwsomeIterator begin();
    AwsomeIterator end();

    AwsomeString& operator=(const AwsomeString&);
    AwsomeString& operator=(const char*);
    AwsomeString& operator+=(const AwsomeString& other);
    AwsomeString& operator+=(const char*);

    ~AwsomeString();

private:
    void AddString(const char*);
    size_t GetStrLength(const char*) const;
    void CopyData(const char*);
    size_t _size;
    char* _data;
};
#endif // AWSOMESTRING_H
