//
// Taken from http://tuttlem.github.io/2014/08/18/getting-istream-to-work-off-a-byte-array.html
// Used in tests to pass byte arrays as input streams
//

#ifndef PROJECTELF_MEMSTREAM_H
#define PROJECTELF_MEMSTREAM_H

#include <stdint.h>
#include <streambuf>
#include <istream>

class membuf : public std::basic_streambuf<char> {
public:
    membuf(const char *p, size_t l) {
        setg((char*)p, (char*)p, (char*)p + l);
    }

    void set_data(const char *p, size_t l) {
        setg((char*)p, (char*)p, (char*)p + l);
    }
};

class memstream : public std::istream {
public:
    explicit memstream(const char *p = nullptr, size_t l = 0) :
            std::istream(&_buffer),
            _buffer(p, l) {
        rdbuf(&_buffer);
    }

    void set_data(const char *p, size_t l) {
        _buffer.set_data(p, l);
        rdbuf(&_buffer);
    }

private:
    membuf _buffer;
};

#endif //PROJECTELF_MEMSTREAM_H
