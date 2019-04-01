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
    membuf(const char *p, size_t size) {
        setg(const_cast<char*>(p), const_cast<char*>(p), const_cast<char*>(p) + size);
    }

    void set_data(const char *p, size_t size) {
        setg(const_cast<char*>(p), const_cast<char*>(p), const_cast<char*>(p) + size);
    }

protected:
    pos_type seekoff(off_type off, std::ios_base::seekdir dir, std::ios_base::openmode openmode) override {
        if (dir == std::ios_base::cur)
            gbump(static_cast<int>(off));
        else if (dir == std::ios_base::end)
            setg(eback(), egptr() + off, egptr());
        else if (dir == std::ios_base::beg)
            setg(eback(), eback() + off, egptr());
        return gptr() - eback();
    }

    pos_type seekpos(pos_type pos, std::ios_base::openmode openmode) override {
        return seekoff(pos - pos_type(off_type(0)), std::ios_base::beg, openmode);
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
