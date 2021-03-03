#include <stdint.h>

char stringBuffer[128];
char *int_to_string(int64_t value)
{
    if (value == 0)
    {
        stringBuffer[0] = '0';
        stringBuffer[1] = '\0';
        return stringBuffer;
    }

    int intSize = 0;
    uint64_t number;
    int isNegative = 0;
    if (value < 0)
    {
        number = -value;
        isNegative = 1;
    }
    else
    {
        number = value;
    }
    while (number > 0)
    {
        number /= 10;
        intSize++;
    }
    if (isNegative)
    {
        stringBuffer[intSize + 1] = '\0';
        stringBuffer[0] = '-';
        intSize++;
        number = -value;
    }
    else
    {
        stringBuffer[intSize] = '\0';
        number = value;
    }
    while (number != 0)
    {
        intSize--;
        stringBuffer[intSize] = number % 10 + 48;
        number /= 10;
    }

    return stringBuffer;
}

char *float_to_string(float value, int round)
{
    if (value == 0)
    {
        stringBuffer[0] = '0';
        stringBuffer[1] = '\0';
        return stringBuffer;
    }
    if (round < 0)
    {
        round = 0;
    }
    if (round > 10)
    {
        round = 10;
    }
    int mulit = 1;
    for (int x = 0; x < round; x++)
    {
        mulit *= 10;
    }

    value *= mulit;
    uint64_t roundedValue;
    int isNegative = 0;
    if (value < 0)
    {
        roundedValue = value * -1;
        isNegative = 1;
    }
    else
    {
        roundedValue = value;
    }
    int nSize = 0;
    uint64_t temp = roundedValue;
    while (temp != 0)
    {
        nSize++;
        temp /= 10;
    }
    if (isNegative)
    {
        stringBuffer[nSize + 2] = '\0';
        stringBuffer[0] = '-';
        nSize++;
    }
    else
    {
        stringBuffer[nSize + 1] = '\0';
    }
    temp = 0;
    while (roundedValue != 0)
    {
        if (temp == round)
        {
            stringBuffer[nSize] = '.';
        }
        else
        {
            stringBuffer[nSize] = roundedValue % 10 + 48;
            roundedValue /= 10;
        }
        nSize--;
        temp++;
    }
    return stringBuffer;
}

char *hex_to_string(uint64_t value, uint64_t size)
{
    size *= 2;
    stringBuffer[size] = '\0';
    for (int i = size - 1; i >= 0; i--)
    {
        int temp = 0;
        int x2 = 1;
        for (int x = 0; x < 4; x++)
        {
            temp += (x2) * (value & 1);
            x2 <<= 1;
            value >>= 1;
        }
        if (temp < 10)
        {
            stringBuffer[i] = temp + 48;
        }
        else
        {
            stringBuffer[i] = temp + 55;
        }
    }

    return stringBuffer;
}