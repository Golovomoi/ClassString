#include "../headers/AwsomeString.h"

AwsomeString::AwsomeString()
{
    size = 0;
    data = new char(1);
}

AwsomeString::AwsomeString(const char* str)
{
    size = 0;
    while (str[size] != '\0')
    {
        size++;
    }
    data = new char(size + 1);
}

AwsomeIterator AwsomeString::begin()
{
    return AwsomeIterator(data);
}

AwsomeIterator AwsomeString::end()
{
    if (size == 0)
        return nullptr;
    // „t„|„‘ „„„€„s„€ „‰„„„€„q„ „y„„„u„‚„p„„„€„‚ „…„{„p„x„„r„p„| „~„p „x„~„p„‰„u„~„y„u „x„p „„€„ƒ„|„u„t„~„y„} „w„|„u„}„u„~„„„€„} „r„ƒ„u„s„t„p „y„}„u„u„} „€„t„~„… „ƒ„r„€„q„€„t„~„…„ „‘„‰„u„z„{„… „r „{„€„~„ˆ„u „~„p „{„€„„„€„‚„…„ „„„…„„ „y „ƒ„ƒ„„|„p„u„}„ƒ„‘ „‡„€„„„ „„„p„} „y „}„…„ƒ„€„‚
    return AwsomeIterator(data + size + 1);
}
