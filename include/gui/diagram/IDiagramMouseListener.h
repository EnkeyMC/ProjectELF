//
// Created by MOmac on 16.04.2019.
//

#ifndef PROJECTELF_IDIAGRAMMOUSELISTENER_H
#define PROJECTELF_IDIAGRAMMOUSELISTENER_H

#include "core/IMouseListener.h"
#include "core/IVerticalBinaryTreeNode.h"
#include "core/Hoverable.h"

class IDiagramMouseListener : virtual public IMouseListener,
        virtual public IVerticalBinaryTreeNode, virtual public Hoverable
{

};


#endif //PROJECTELF_IDIAGRAMMOUSELISTENER_H
