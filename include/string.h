#ifndef STRING_H
#define STRING_H

#include "string_details.h"

typedef char*         string_iterator;
typedef const char*   string_const_iterator;

/**
 *  @param this Reference to %string.
 *  @returns A read/write iterator that points to the
 *           first character in non-empty %string.
 */
#define string_begin(this)        ((this)->buffer)

/**
 *  @param this Reference to %string.
 *  @returns A read/write reverse iterator that points to the
 *           last character in non-empty %string.
 */
#define string_rbegin(this)       (string_begin(this) + string_size(this) - 1)

/**
 *  @param this Reference to %string.
 *  @returns A read/write iterator that points one past the last
 *           character in non-empty %string.
 */
#define string_end(this)          (string_begin(this) + string_size(this))

/**
 *  @param this Reference to %string.
 *  @returns A read/write reverse iterator that points to one
 *           before the first character in non-empty %string.
 */
#define string_rend(this)         (string_begin(this) - 1)

/**
 *  @brief Provides read/write access to the data contained in the %string.
 *  @param __i The index of the character to access.
 *
 *  This function provides for safer data access.  The index is
 *  first checked that it is in the range of the string.
 */
#define string_at(this, __i)      ((this)->buffer[__i < string_len(this) ? __i : string_len(this)])

/**
 *  @param this Reference to %string.
 *  @returns Provides read/write access to the first
 *           character in non-empty %string.
 */
#define string_front(this)        (*string_begin(this))

/**
 *  @param this Reference to %string.
 *  @returns Provides read/write access to the the last
 *           character in non-empty %string.
 */
#define string_back(this)         (*string_rbegin(this))

/* Returns the total number of characters that the %string can hold before needing to allocate more memory. */
#define string_capacity(this)     ((this)->capacity)

/* Returns the number of characters in the %string. */
#define string_len(this)          ((this)->length)

/* Returns the number of characters in the %string. */
#define string_size(this)         string_len(this)

/* Returns true if the %string is empty. */
#define string_empty(this)        (string_size(this) == 0)

/* Construct an empty %string. */
#define string_new()              string_constructor()

/**
 *  @brief  Constructs the %string.
 *  @param __s A null-terminated string.
 * 
 *  This function constructs the %string with copies of the
 *  characters in @a __s.
 */
extern string string_from(const char* __s);

/**
 *  @brief Assigns a string to this %string.
 *  @param this Reference to %string.
 *  @param __s A null-terminated string.
 *
 *  This function fills the %string with copies of the characters 
 *  in  @a __s.
 *
 *  Note that the assignment completely changes the %string and
 *  that the resulting %string's length is the same as the number
 *  of characters assigned.
 */
extern void string_assign(string* this, const char* __s);

/**
 *  @brief Append a single character.
 *  @param this Reference to %string.
 *  @param __x  Character to append.
 */    
extern void string_push(string* this, char __x);

/**
 *  @brief  Removes last character.
 *  @param  this Reference to %string.
 */
extern void string_pop(string* this);

/**
 *  @brief Append a string to this %string.
 *  @param this Reference to %string.
 *  @param __s A string to append.
 */
extern void string_append(string* this, const char* __s);

/**
 *  @brief Inserts a single character before specified iterator.
 *  @param this Reference to %string.
 *  @param __position Iterator into the %string.
 *  @param __x Character to insert.
 *  @return Iterator that points to the inserted character.
 *
 *  This function will insert a copy of the given character before
 *  the specified location.  Note that this kind of operation
 *  could be expensive for %string and if it is frequently
 *  used the user should consider using linked list.
 */
extern string_iterator string_insert(string* this, string_iterator __position, char __x);

/**
 *  @brief Inserts a string into this %string.
 *  @param this Reference to %string.
 *  @param __position Iterator into the %string.
 *  @param __s A string to insert.
 *  @return Iterator that points to first character in
 *          the inserted string.
 *
 *  This function will insert copies of the characters in
 *  string @a __s into the %string before the location
 *  specified by @a position.
 *
 *  Note that this kind of operation could be expensive for a
 *  %string and if it is frequently used the user should
 *  consider using linked list.
 */
extern string_iterator string_insert_str(string* this, string_iterator __position, const char* __s);

/**
 *  @brief Remove a character at given position.
 *  @param this Reference to %string.
 *  @param __position Iterator pointing to character to be erased.
 *  @return  Iterator pointing to the next character (or string_end()).
 *
 *  This function will erase the character at the given position and thus
 *  shorten the %string by one.
 *
 *  Note This operation could be expensive and if it is
 *  frequently used the user should consider using linked list.
 */
extern string_iterator string_erase(string* this, string_iterator __position);

/**
 *  @brief Remove a range of characters.
 *  @param __first Iterator pointing to the first character to be erased.
 *  @param __last Iterator pointing to one past the last character to be
 *                erased.
 *  @return  Iterator pointing to the character pointed to by @a __last
 *           prior to erasing (or string_end()).
 *
 *  This function will erase the characters in the range
 *  [__first,__last) and shorten the %string accordingly.
 *
 *  Note This operation could be expensive and if it is
 *  frequently used the user should consider using linked list.
 */
string_iterator string_erase_range(string* this, string_iterator __first, string_iterator __last);

/**
 *  @brief Attempt to preallocate enough memory for specified number of characters.
 *  @param this Reference to %string.
 *  @param __n Number of characters required.
 */
extern void string_reserve(string* this, size_t __n);

/**
 *  @brief Resizes the %string to the specified number of characters.
 *  @param __size Number of characters the %string should contain.
 *
 *  This function will %resize the %string to the specified
 *  number of characters.  If the number is smaller than the
 *  %string's current size the %string is truncated, otherwise
 *  zero-initialized characters are appended.
 */
extern void string_resize(string* this, size_t __size);

/**
 *  @brief A non-binding request to reduce string_capacity() to string_size().
 *  @param this Reference to %string.
 */
extern void string_shrink_to_fit(string* this);

/**
 *  @brief Moves the resources of a %string.
 *  @param this Reference to %string.
 *  @return A %string holding the resources of @a this.
 */
extern string string_move(string* this);

/**
 *  @brief Copy the %string.
 *  @param this Reference to %string.
 *  @return Deep copy of @a this.
 */
extern string string_copy(const string* this);

/**
 *  @brief Swap contents of two %strings.
 *  @param __first Reference to the first %string.
 *  @param __second Reference to the second %string.
 *
 *  This exchanges the elements between two strings in constant time.
 */
extern void string_swap(string* __first, string* __second);

/**
 *  @param this Reference to %string.
 *  @return A const pointer to null-terminated contents.
 *
 *  This is a handle to internal data.  Do not modify or dire things may
 *  happen.
 */
extern const char* string_c_str(string* this);

/**
 *  @brief Erases all the characters.
 *  @param this Reference to %string.
 */
#define string_clear(this)   (string_size(this) = 0)

/**
 *  @brief Erases the %string.
 *  @param this Reference to %string.
 */
extern void string_destructor(string* this);

/**
 *  @brief Erases const %string.
 *  @param this Reference to const %string.
 */
extern void string_const_destructor(const string* this);

/* Compares two %strings. */
extern int string_compare(string* __ls, string* __rs);

/* Compares %string to C string. */
extern int string_compare_c(string* __ls, const char* __rs);

/* Compares C string to %string. */
extern int string_c_compare(const char* __ls, string* __rs);

/* Sort predicate */
extern int string_ascending(const void* __ls, const void* __rs);

/* Sort predicate */
extern int string_descending(const void* __ls, const void* __rs);

/** 
 * @brief Read a line from stream into a string.
 * @param this Buffer to store into.
*/
extern void string_getline(string* this);

/* Convert short to %string. */
extern string string_from_i16(short __val);

/* Convert int to %string. */
extern string string_from_i32(int __val);

/* Convert long signed int to %string. */
extern string string_from_i64(long signed int __val);

/* Convert unsigned short to %string. */
extern string string_from_u16(unsigned short __val);

/* Convert unsigned int to %string. */
extern string string_from_u32(unsigned int __val);

/* Convert long unsigned int to %string. */
extern string string_from_u64(long unsigned int __val);

/* Convert float to %string. */
extern string string_from_f32(float __val);

/* Convert double to %string. */
extern string string_from_f64(double __val);

/* Convert long double to %string. */
extern string string_from_f128(long double __val);

/* Converts a number to %string. */
#define to_string(__val) ({                           \
    _Generic((__val),                                 \
        char                     : string_from_i16,   \
        unsigned char            : string_from_u16,   \
        short                    : string_from_i16,   \
        unsigned short           : string_from_u16,   \
        int                      : string_from_i32,   \
        unsigned int             : string_from_u32,   \
        long signed int          : string_from_i64,   \
        long unsigned int        : string_from_u64,   \
        long long int            : string_from_i64,   \
        unsigned long long int   : string_from_u64,   \
        float                    : string_from_f32,   \
        double                   : string_from_f64,   \
        long double              : string_from_f128   \
        )(__val);                                     \
})

#endif
