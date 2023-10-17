#pragma once
#ifndef AWSOMEITERATOR_H
#define AWSOMEITERATOR_H

class AwsomeString;
// „y„„„u„‚„p„„„€„‚ „}„€„w„~„€ „r„|„€„w„y„„„ „r „ƒ„p„} „{„|„p„ƒ„ƒ „ƒ„„„‚„€„{„y, „~„€ „‚„u„Š„y„| „u„s„€ „r„„~„u„ƒ„„„y „€„„„t„u„|„„~„€
// „ƒ„t„u„|„p„| „y„„„u„‚„p„„„€„‚ „t„|„‘ „…„t„€„q„ƒ„„„r„p
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
