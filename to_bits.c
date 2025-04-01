#include <stdio.h>
#include <stdlib.h>
#include "include/string.h"

void i8_to_bits(string* __bits, signed char __val)
{
    for (signed char i = 0, mask = 1, size = sizeof(__val) * 8; i < size; i++)
    {
        string_insert(__bits, string_begin(__bits), (__val & mask << i) ? '1' : '0');
    }
}

void u8_to_bits(string* __bits, unsigned char __val)
{
    for (unsigned char i = 0, mask = 1, size = sizeof(__val) * 8; i < size; i++)
    {
        string_insert(__bits, string_begin(__bits), (__val & mask << i) ? '1' : '0');
    }
}

void i16_to_bits(string* __bits, signed short __val)
{
    for (signed short i = 0, mask = 1, size = sizeof(__val) * 8; i < size; i++)
    {
        string_insert(__bits,string_begin(__bits), (__val & mask << i) ? '1' : '0');
    }
}

void u16_to_bits(string* __bits, unsigned short __val)
{
    for (unsigned short i = 0, mask = 1, size = sizeof(__val) * 8; i < size; i++)
    {
        string_insert(__bits, string_begin(__bits), (__val & mask << i) ? '1' : '0');
    }
}

void i32_to_bits(string* __bits, signed int __val)
{
    for (signed int i = 0, mask = 1, size = sizeof(__val) * 8; i < size; i++)
    {
        string_insert(__bits, string_begin(__bits), (__val & mask << i) ? '1' : '0');
    }
}

void u32_to_bits(string* __bits, unsigned int __val)
{
    for (unsigned int i = 0, mask = 1, size = sizeof(__val) * 8; i < size; i++)
    {
        string_insert(__bits, string_begin(__bits), (__val & mask << i) ? '1' : '0');
    }
}

void i64_to_bits(string* __bits, signed long __val)
{
    for (signed long i = 0, mask = 1, size = sizeof(__val) * 8; i < size; i++)
    {
        string_insert(__bits, string_begin(__bits), (__val & mask << i) ? '1' : '0');
    }
}

void u64_to_bits(string* __bits, unsigned long __val)
{
    for (unsigned long i = 0, mask = 1, size = sizeof(__val) * 8; i < size; i++)
    {
        string_insert(__bits, string_begin(__bits), (__val & mask << i) ? '1' : '0');
    }
}
