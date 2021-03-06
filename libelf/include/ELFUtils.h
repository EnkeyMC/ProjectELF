/*
Copyright (C) 2001-2015 by Serge Lamikhov-Center

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.


This file is taken from ELFIO project with few modifications: https://github.com/serge1/ELFIO/blob/master/elfio/elf_types.hpp
*/

#ifndef PROJECTELF_ELFUTILS_H
#define PROJECTELF_ELFUTILS_H

#include <vector>

#include "ELFTypes.h"

#define ELFIO_GET_SET_SIZE_ACCESS( TYPE, NAME, FIELD ) \
    TYPE get_##NAME() const override              \
    {                                             \
        if (!header_valid) return 0;              \
        return elf.get_converter()( FIELD );      \
    }                                             \
    void set_##NAME( TYPE value ) override        \
    {                                             \
        if (!header_valid) return;                \
        FIELD = value;                            \
        FIELD = elf.get_converter()( FIELD );     \
    }                                             \
    size_t get_sizeof_##NAME() const override     \
    {                                             \
        return sizeof(FIELD);                     \
    }

#define ELFIO_GET_SET_SIZE_ACCESS_DECL( TYPE, NAME ) \
    virtual TYPE get_##NAME() const = 0;             \
    virtual void set_##NAME( TYPE value ) = 0;       \
    virtual size_t get_sizeof_##NAME() const = 0

namespace elf {

//------------------------------------------------------------------------------
class endianess_converter {
public:
//------------------------------------------------------------------------------
    endianess_converter()
    {
        need_conversion = false;
    }

//------------------------------------------------------------------------------
    void
    setup( const unsigned char elf_file_encoding )
    {
        need_conversion = ( elf_file_encoding != get_host_encoding() );
    }

//------------------------------------------------------------------------------
    uint64_t
    operator()( uint64_t value ) const
    {
        if ( !need_conversion ) {
            return value;
        }
        value =
                ( ( value & 0x00000000000000FFull ) << 56 ) |
                ( ( value & 0x000000000000FF00ull ) << 40 ) |
                ( ( value & 0x0000000000FF0000ull ) << 24 ) |
                ( ( value & 0x00000000FF000000ull ) <<  8 ) |
                ( ( value & 0x000000FF00000000ull ) >>  8 ) |
                ( ( value & 0x0000FF0000000000ull ) >> 24 ) |
                ( ( value & 0x00FF000000000000ull ) >> 40 ) |
                ( ( value & 0xFF00000000000000ull ) >> 56 );

        return value;
    }

//------------------------------------------------------------------------------
    int64_t
    operator()( int64_t value ) const
    {
        if ( !need_conversion ) {
            return value;
        }
        return (int64_t)(*this)( (uint64_t)value );
    }

//------------------------------------------------------------------------------
    uint32_t
    operator()( uint32_t value ) const
    {
        if ( !need_conversion ) {
            return value;
        }
        value =
                ( ( value & 0x000000FF ) << 24 ) |
                ( ( value & 0x0000FF00 ) <<  8 ) |
                ( ( value & 0x00FF0000 ) >>  8 ) |
                ( ( value & 0xFF000000 ) >> 24 );

        return value;
    }

//------------------------------------------------------------------------------
    int32_t
    operator()( int32_t value ) const
    {
        if ( !need_conversion ) {
            return value;
        }
        return (int32_t)(*this)( (uint32_t)value );
    }

//------------------------------------------------------------------------------
    uint16_t
    operator()( uint16_t value ) const
    {
        if ( !need_conversion ) {
            return value;
        }
        value =
                ( ( value & 0x00FF ) <<  8 ) |
                ( ( value & 0xFF00 ) >>  8 );

        return value;
    }

//------------------------------------------------------------------------------
    int16_t
    operator()( int16_t value ) const
    {
        if ( !need_conversion ) {
            return value;
        }
        return (int16_t)(*this)( (uint16_t)value );
    }

//------------------------------------------------------------------------------
    int8_t
    operator()( int8_t value ) const
    {
        return value;
    }

//------------------------------------------------------------------------------
    uint8_t
    operator()( uint8_t value ) const
    {
        return value;
    }

//------------------------------------------------------------------------------
private:
//------------------------------------------------------------------------------
    unsigned char
    get_host_encoding() const
    {
        static const int tmp = 1;
        if ( 1 == *(const char*)&tmp ) {
            return ELFDATA2LSB;
        }
        else {
            return ELFDATA2MSB;
        }
    }

//------------------------------------------------------------------------------
private:
    bool need_conversion;
};


//------------------------------------------------------------------------------
inline
uint32_t
elf_hash( const unsigned char *name )
{
    uint32_t h = 0, g;
    while ( *name ) {
        h = (h << 4) + *name++;
        g = h & 0xf0000000;
        if ( g != 0 )
            h ^= g >> 24;
        h &= ~g;
    }
    return h;
}

//------------------------------------------------------------------------------
template <typename T>
inline std::vector<T>& operator+= (std::vector<T> &lhs, const std::vector<T> &rhs)
{
    lhs.insert(lhs.end(), rhs.begin(), rhs.end());
    return lhs;
}

//------------------------------------------------------------------------------
template <typename T>
inline std::vector<T> operator+ (std::vector<T> lhs, const std::vector<T> &rhs)
{
    lhs += rhs;
    return lhs;
}

} // namespace elf

#endif //PROJECTELF_ELFUTILS_H
