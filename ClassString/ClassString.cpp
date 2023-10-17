#include <iostream>
#include <string>
#include "headers/AwsomeString.h"

int main()
{
    AwsomeString* st = new AwsomeString("qqwwee");
    AwsomeString sat = "asd";
    AwsomeString sit = "123";
    sat = "ggffdd";
    AwsomeString sot(sat);
    sit = sot;
    std::cout << "Strings!\n";
}
