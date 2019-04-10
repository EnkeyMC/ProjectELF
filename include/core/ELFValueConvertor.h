#ifndef ELFVALUECONVERTOR_H
#define ELFVALUECONVERTOR_H

#include <QString>
#include <QObject>
#include <ELFTypes.h>

class ELFValueConvertor
{
public:
    static QString eiClassToDisp(unsigned char value);
    static QString eiDataToDisp(unsigned char value);
    static QString eTypeToDisp(elf::Elf_Half value);
    static QString eMachineToDisp(elf::Elf_Half value);
    static QString eVersionToDisp(elf::Elf_Word value);

private:
    template<typename TInt>
    static QString unkownValue(TInt value) {
        return QString(QObject::tr("Unkown (0x")) + QString::number(value, 16) + ")";
    }

    ELFValueConvertor();
};

#endif // ELFVALUECONVERTOR_H
