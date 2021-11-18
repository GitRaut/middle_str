#include "middle_str.h"

bool itc_isDigit(unsigned char c)
{
    if((c >= '0') and (c <= '9'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

unsigned char itc_toUpper(unsigned char c)
{
    if((c >= 97) and (c <= 122))
    {
        return c - 32;
    }
    return c;
}

unsigned char itc_changeCase(unsigned char c)
{
    if((c >= 97) and (c <= 122))
    {
        return itc_toUpper(c);
    }
    else if ((c >= 65) and (c <= 90))
    {
        return c + 32;
    }
    return c;
}

bool itc_compare(string S1, string S2)
{
    int count = 0;
    for(int i = 0; i < itc_len(S1); i++)
    {
        if(S1[i] == S2[i])
        {
            count++;
        }
    }
    if((itc_len(S1) == itc_len(S2)) and (count == itc_len(S1)))
    {
        return true;
    }
    return false;
}
