//
// Created by MOmac on 10.03.2019.
//

#include "gui/diagram/CondensedDiagramLayout.h"
#include "gui/diagram/DiagramLayout.h"

#define ARROW_SPACE_WIDTH 40
#define REFERENCE_HEIGHT 1000
#define COLUMN_WIDTH 200

CondensedDiagramLayout::CondensedDiagramLayout(DiagramScene *diagram) : DiagramLayout(diagram) {

}

void CondensedDiagramLayout::layoutNodes() {
    for (auto &linkNode : linkColumnSortedNodes) {
        linkNode->setNodeRect(
                QRect(
                        0 + ARROW_SPACE_WIDTH,
                        static_cast<int>(REFERENCE_HEIGHT * linkNode->getProportionalPosition()),
                        COLUMN_WIDTH * linkNode->getColspan(),
                        static_cast<int>(REFERENCE_HEIGHT * linkNode->getProportionalSize())
                )
        );
    }

    for (auto &execNode : execColumnSortedNodes) {
        execNode->setNodeRect(
                QRect(
                        COLUMN_WIDTH + ARROW_SPACE_WIDTH,
                        static_cast<int>(REFERENCE_HEIGHT * execNode->getProportionalPosition()),
                        COLUMN_WIDTH * execNode->getColspan(),
                        static_cast<int>(REFERENCE_HEIGHT * execNode->getProportionalSize())
                )
        );
    }

    auto linkNodeIterator = linkColumnSortedNodes.begin();
    auto execNodeIterator = execColumnSortedNodes.begin();
    int heightCompensation = 0, currentY = 0;
    DiagramNode *linkNode, *execNode;

//    while (linkNodeIterator != m_linkColumnSortedNodes.end()
//            && execNodeIterator != m_execColumnSortedNodes.end())
//    {
//        linkNode = *linkNodeIterator;
//        execNode = *execNodeIterator;
//
        // link node started
//        if (linkNode->getNodeRect().top() >= currentY) {
            // link node has height
//            if (linkNode->getNodeRect().height() > 0) {
                // link node height is smaller than minimal height
//                if (linkNode->getNodeRect().height() < linkNode->getMinHeight()) {
                    // exec node starts inside link node
//                    if (execNode->getNodeRect().top() > linkNode->getNodeRect().top()
//                        && execNode->getNodeRect().top() < linkNode->getNodeRect().bottom())
//                    {
                        // move exec node to reflect position in file
//                        double execNodeStartRelativeToLinkNode =
//                                (execNode->getNodeRect().top() - linkNode->getNodeRect().top())
//                                /
//                                static_cast<double>(linkNode->getNodeRect().height());
//
//                        int newExecPosition = static_cast<int>(
//                                linkNode->getMinHeight() * execNodeStartRelativeToLinkNode + linkNode->getNodeRect().top());
//
//                        execNode->moveTop(newExecPosition);
//                    }
//
//                    if (execNode->getNodeRect().bottom() > linkNode->getNodeRect().top()
//                        && execNode->getNodeRect().bottom() < linkNode->getNodeRect().bottom())
//                    {
//                        double execNodeBottomRelativeToLinkNode =
//                                (execNode->getNodeRect().bottom() - linkNode->getNodeRect().top())
//                                /
//                                static_cast<double>(linkNode->getNodeRect().height());
//
//                        int newExecBottom = static_cast<int>(
//                                linkNode->getMinHeight() * execNodeBottomRelativeToLinkNode + linkNode->getNodeRect().top()
//                                );
//                        execNode->setBottom(newExecBottom);
//                    }
//
//                    linkNode->setHeight(linkNode->getMinHeight());
//                    heightCompensation += linkNode->getMinHeight() - linkNode->getNodeRect().height();
//                }
//            }
//        }
//    }
}

void CondensedDiagramLayout::paint(QPainter *painter) const {
    for (const auto &linkNode : linkColumnSortedNodes)
        linkNode->paint(painter);

    for (const auto &execNode : execColumnSortedNodes)
        execNode->paint(painter);
}

