#ifndef PROJECTELF_VERSION_H
#define PROJECTELF_VERSION_H

#include <string>

namespace Version {
    const int MAJOR = 0;
    const int MINOR = 2;
    const int REVISION = 0;

    inline const std::string toString() {
        return std::to_string(MAJOR) + "." + std::to_string(MINOR) + "." + std::to_string(REVISION);
    }
}

#endif //PROJECTELF_VERSION_H
