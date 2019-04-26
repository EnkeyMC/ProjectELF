//
// Created by MOmac on 26.04.2019.
//

#ifndef PROJECTELF_ICONTAINS_H
#define PROJECTELF_ICONTAINS_H

#include <QRect>

class IContains {
public:
    virtual bool contains(const QPoint &point) const = 0;
};


#endif //PROJECTELF_ICONTAINS_H
