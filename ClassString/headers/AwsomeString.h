#pragma once
#ifndef AWSOMESTRING_H
#define AWSOMESTRING_H
#include <iostream>
#include "../headers/AwsomeIterator.h"

class AwsomeString{
public:
    AwsomeString();
    AwsomeString(const char*);
    AwsomeString (const AwsomeString&);
    AwsomeString(AwsomeString&&) noexcept;

    char* GetRawData() const;
    size_t GetLength() const;

    AwsomeIterator begin() const;
    AwsomeIterator end() const;

    AwsomeString& operator=(const AwsomeString&);
    AwsomeString& operator=(const char*);
    AwsomeString& operator+=(const AwsomeString& );
    AwsomeString& operator+=(const char*);
    AwsomeString operator+(const AwsomeString&) const;
    AwsomeString operator+(const char*) const;
    bool operator<(const AwsomeString&)const;
    // „u„ƒ„|„y „y„ƒ„„€„|„Ž„x„€„r„p„„„Ž „„„„€„„ „€„„u„‚„p„„„€„‚, „„„€ „r„p„w„~„€ „ƒ„€„‡„‚„p„~„y„„„Ž „u„s„€ „r „„u„‚„u„}„u„~„~„€„z, „‰„„„€„q„ „r „t„p„|„Ž„~„u„z„Š„u„} „}„€„w„~„€ „q„„|„€ „r„„x„r„p„„„Ž „t„u„ƒ„„„‚„…„{„„„€„‚.
    friend AwsomeString operator+(const char*, const AwsomeString&);
    friend std::ostream& operator<<(std::ostream&, const AwsomeString&);
    friend std::istream& operator>>(std::istream&, AwsomeString&);
    

    ~AwsomeString();

private:
    void AddString(const char*);
    size_t GetStrLength(const char*) const;
    void CopyData(const char*);
    size_t _size;
    char* _data;
};
#endif // AWSOMESTRING_H
