#ifndef ELFVALUECONVERTER_H
#define ELFVALUECONVERTER_H

#include <QString>
#include <QObject>
#include <ELFTypes.h>

class ELFValueConverter
{
public:
    static QString eiClassToDisp(unsigned char value);
    static QString eiDataToDisp(unsigned char value);
    static QString eiOsabiToDisp(unsigned char value);
    static QString eTypeToDisp(elf::Elf_Half value);
    static QString eMachineToDisp(elf::Elf_Half value);
    static QString eVersionToDisp(elf::Elf_Word value);

private:
    template<typename TInt>
    static QString unknownValue(TInt value) {
        return QString(QObject::tr("Unknown (0x")) + QString::number(value, 16) + ")";
    }

    static QString tr(const char *s);

    ELFValueConverter();
};

#endif // ELFVALUECONVERTER_H
