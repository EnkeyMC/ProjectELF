//
// Created by MOmac on 15.03.2019.
//

#ifndef PROJECTELF_MODELBASE_H
#define PROJECTELF_MODELBASE_H

#include <QObject>

class ModelBase : public QObject {
    Q_OBJECT
public:
    explicit ModelBase(QObject *parent = nullptr);

};


#endif //PROJECTELF_MODELBASE_H
