#pragma once
#ifndef AWSOMEITERATOR_H
#define AWSOMEITERATOR_H

class AwsomeString;
// �y���u���p������ �}���w�~�� �r�|���w�y���� �r ���p�} �{�|�p���� ���������{�y, �~�� ���u���y�| �u�s�� �r���~�u�����y �����t�u�|���~��
// ���t�u�|�p�| �y���u���p������ �t�|�� ���t���q�����r�p
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
