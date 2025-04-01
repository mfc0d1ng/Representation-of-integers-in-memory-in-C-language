#ifndef TO_BITS_H
#define TO_BITS_H

#include "string.h"

/**
 * @brief Get the representation of a signed 8-bit integer in memory into a string of bits.
 * @param __bits Buffer to store the bits into.
 * @param __val Integer value.
 */
extern void i8_to_bits(string* __bits, signed char __val);

/**
 * @brief Get the representation of unsigned 8-bit integer in memory into a string of bits.
 * @param __bits Buffer to store the bits into.
 * @param __val Integer value.
 */
extern void u8_to_bits(string* __bits, unsigned char __val);

/**
 * @brief Get the representation of a signed 16-bit integer in memory into a string of bits.
 * @param __bits Buffer to store the bits into.
 * @param __val Integer value.
 */
extern void i16_to_bits(string* __bits, signed short __val);

/**
 * @brief Get the representation of unsigned 16-bit integer in memory into a string of bits.
 * @param __bits Buffer to store the bits into.
 * @param __val Integer value.
 */
extern void u16_to_bits(string* __bits, unsigned short __val);

/**
 * @brief Get the representation of a signed 32-bit integer in memory into a string of bits.
 * @param __bits Buffer to store the bits into.
 * @param __val Integer value.
 */
extern void i32_to_bits(string* __bits, signed int __val);

/**
 * @brief Get the representation of unsigned 32-bit integer in memory into a string of bits.
 * @param __bits Buffer to store the bits into.
 * @param __val Integer value.
 */
extern void u32_to_bits(string* __bits, unsigned int __val);

/**
 * @brief Get the representation of a signed 64-bit integer in memory into a string of bits.
 * @param __bits Buffer to store the bits into.
 * @param __val Integer value.
 */
extern void i64_to_bits(string* __bits, signed long __val);

/**
 * @brief Get the representation of unsigned 64-bit integer in memory into a string of bits.
 * @param __bits Buffer to store the bits into.
 * @param __val Integer value.
 */
extern void u64_to_bits(string* __bits, unsigned long __val);

#endif