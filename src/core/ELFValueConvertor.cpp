#include "core/ELFValueConvertor.h"

QString ELFValueConvertor::eiClassToDisp(unsigned char value)
{
    switch (value) {
    case ELFCLASS32:
        return "32-bit";
    case ELFCLASS64:
        return "64-bit";
    default:
        return unkownValue(value);
    }
}

QString ELFValueConvertor::eiDataToDisp(unsigned char value)
{
    switch (value) {
    case ELFDATA2LSB:
        return QObject::tr("LSB, 2's complement");
    case ELFDATA2MSB:
        return QObject::tr("MSB, 2's complement");
    default:
        return unkownValue(value);
    }
}

QString ELFValueConvertor::eTypeToDisp(elf::Elf_Half value)
{
    switch (value) {
    case ET_NONE:
        return QObject::tr("None (ET_NONE)");
    case ET_REL:
        return QObject::tr("Relocatable (ET_REL)");
    case ET_EXEC:
        return QObject::tr("Executable (ET_EXEC)");
    case ET_DYN:
        return QObject::tr("Shared (ET_DYN)");
    case ET_CORE:
        return QObject::tr("Core (ET_CORE)");
    default:
        return unkownValue(value);
    }
}

QString ELFValueConvertor::eMachineToDisp(elf::Elf_Half value)
{
    switch (value) {
    case EM_NONE:
        return QObject::tr("No machine");
    case EM_M32:
        return QObject::tr("AT&T WE 32100");
    case EM_SPARC:
        return QObject::tr("SPARC");
    case EM_386:
        return QObject::tr("Intel 80386");
    case EM_68K:
        return QObject::tr("Motorola m68k family");
    case EM_88K:
        return QObject::tr("Motorola m88k family");
    case EM_486:
        return QObject::tr("Intel 80486");
    case EM_860:
        return QObject::tr("Intel 80860");
    case EM_MIPS:
        return QObject::tr("MIPS R3000");
    case EM_S370:
        return QObject::tr("IBM System/370");
    case EM_MIPS_RS3_LE:
        return QObject::tr("MIPS R3000 little-endian");
    case EM_PARISC:
        return QObject::tr("HPPA");
    case EM_960:
        return QObject::tr("Intel 80960");
    case EM_PPC:
        return QObject::tr("PowerPC");
    case EM_PPC64:
        return QObject::tr("64-bit PowerPC");
    case EM_S390:
        return QObject::tr("IBM S/390");
    case EM_SPU:
        return QObject::tr("Sony/Toshiba/IBM SPU");
    case EM_V800:
        return QObject::tr("NEC V800 series");
    case EM_FR20:
        return QObject::tr("Fujitsu FR20");
    case EM_RH32:
        return QObject::tr("TRW RH32");
    case EM_MCORE:
        return QObject::tr("Motorola MCore");
    case EM_ARM:
        return QObject::tr("ARM");
    case EM_OLD_ALPHA:
        return QObject::tr("Digital Alpha");
    case EM_SH:
        return QObject::tr("Renesas SuperH");
    case EM_SPARCV9:
        return QObject::tr("SPARC v9 64-bit");
    case EM_TRICORE:
        return QObject::tr("Siemens Tricore");
    case EM_ARC:
        return QObject::tr("ARC Cores");
    case EM_H8_300:
        return QObject::tr("Renesas H8/300");
    case EM_H8_300H:
        return QObject::tr("Renesas H8/300H");
    case EM_H8S:
        return QObject::tr("Renesas H8S");
    case EM_H8_500:
        return QObject::tr("Renesas H8/500");
    case EM_IA_64:
        return QObject::tr("Intel IA-64 ");
    case EM_MIPS_X:
        return QObject::tr("Stanford MIPS-X");
    case EM_COLDFIRE:
        return QObject::tr("Motorola Coldfire");
    case EM_68HC12:
        return QObject::tr("Motorola M68HC12");
    case EM_MMA:
        return QObject::tr("Fujitsu Multimedia Accelerator");
    case EM_PCP:
        return QObject::tr("Siemens PCP");
    case EM_NCPU:
        return QObject::tr("Sony nCPU embedded RISC processor");
    case EM_NDR1:
        return QObject::tr("Denso NDR1");
    case EM_STARCORE:
        return QObject::tr("Motorola StarCore");
    case EM_ME16:
        return QObject::tr("Toyota ME16");
    case EM_ST100:
        return QObject::tr("STMicroelectronics ST100");
    case EM_TINYJ:
        return QObject::tr("Advanced Logic Corp. Tiny3");
    case EM_X86_64:
        return QObject::tr("AMD x86-64");
    case EM_PDSP:
        return QObject::tr("Sony DSP");
    case EM_PDP10:
        return QObject::tr("Digital Equipment Corp. PDP-10");
    default:
        return unkownValue(value);
    }
}

QString ELFValueConvertor::eVersionToDisp(elf::Elf_Word value)
{
    switch (value) {
    case EV_NONE:
        return QObject::tr("Invalid (0x0)");
    case EV_CURRENT:
        return QObject::tr("Current (0x1)");
    default:
        return unkownValue(value);
    }
}

ELFValueConvertor::ELFValueConvertor() = default;
