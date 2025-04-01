#ifndef STRING_DETAILS_H
#define STRING_DETAILS_H

typedef struct string
{
    char* buffer;
    size_t length;
    size_t capacity;
}string;

#define string_constructor()    {.buffer = NULL, .length = 0, .capacity = 0}

#endif