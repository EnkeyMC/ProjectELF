//
// Created by MOmac on 15.04.2019.
//

#ifndef PROJECTELF_IQUADTREENODE_H
#define PROJECTELF_IQUADTREENODE_H

#include <QRect>

class IVerticalBinaryTreeNode {
public:
    virtual QRect getBoundingBox() const = 0;
    virtual bool contains(const QPoint &point) const = 0;
};


#endif //PROJECTELF_IQUADTREENODE_H
