//
// Created by MOmac on 15.04.2019.
//

#ifndef PROJECTELF_IQUADTREENODE_H
#define PROJECTELF_IQUADTREENODE_H

#include <QRect>

#include "core/IContains.h"

class IVerticalBinaryTreeNode : virtual public IContains {
public:
    virtual QRect getBounds() const = 0;
};


#endif //PROJECTELF_IQUADTREENODE_H
