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
    AwsomeString moved = std::move(sit);
    moved += sat;
    moved += "333";
    AwsomeString conStr = "123" + AwsomeString("456");
    AwsomeString conStr1 = AwsomeString("ab") + "bc";
    AwsomeString conStr2 = conStr + conStr1;
    std::cout << "Strings!\n";
}
