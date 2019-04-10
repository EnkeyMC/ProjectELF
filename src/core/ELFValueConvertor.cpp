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
        return tr("LSB, 2's complement");
    case ELFDATA2MSB:
        return tr("MSB, 2's complement");
    default:
        return unkownValue(value);
    }
}

QString ELFValueConvertor::eiOsabiToDisp(unsigned char value)
{
    switch (value) {
    case ELFOSABI_NONE:
        return tr("Unspecified (0x0)");
    case ELFOSABI_HPUX:
        return tr("Hewlett-Packard HP-UX");
    case ELFOSABI_NETBSD:
        return tr("NetBSD");
    case ELFOSABI_LINUX:
        return tr("Linux");
    case ELFOSABI_SOLARIS:
        return tr("Sun Solaris");
    case ELFOSABI_AIX:
        return tr("AIX");
    case ELFOSABI_IRIX:
        return tr("IRIX");
    case ELFOSABI_FREEBSD:
        return tr("FreeBSD");
    case ELFOSABI_TRU64:
        return tr("Compaq TRU64 UNIX");
    case ELFOSABI_MODESTO:
        return tr("Novell Modesto");
    case ELFOSABI_OPENBSD:
        return tr("Open BSD");
    case ELFOSABI_OPENVMS:
        return tr("Open VMS");
    case ELFOSABI_NSK:
        return tr("Hewlett-Packard Non-Stop Kernel");
    case ELFOSABI_AROS:
        return tr("Amiga Research OS");
    case ELFOSABI_FENIXOS:
        return tr("FenixOS");
    default:
        return unkownValue(value);
    }
}

QString ELFValueConvertor::eTypeToDisp(elf::Elf_Half value)
{
    switch (value) {
    case ET_NONE:
        return tr("None (ET_NONE)");
    case ET_REL:
        return tr("Relocatable (ET_REL)");
    case ET_EXEC:
        return tr("Executable (ET_EXEC)");
    case ET_DYN:
        return tr("Shared (ET_DYN)");
    case ET_CORE:
        return tr("Core (ET_CORE)");
    default:
        return unkownValue(value);
    }
}

QString ELFValueConvertor::eMachineToDisp(elf::Elf_Half value)
{
    switch (value) {
    case EM_NONE:
        return tr("No machine");
    case EM_M32:
        return tr("AT&T WE 32100");
    case EM_SPARC:
        return tr("SPARC");
    case EM_386:
        return tr("Intel 80386");
    case EM_68K:
        return tr("Motorola m68k family");
    case EM_88K:
        return tr("Motorola m88k family");
    case EM_486:
        return tr("Intel 80486");
    case EM_860:
        return tr("Intel 80860");
    case EM_MIPS:
        return tr("MIPS R3000");
    case EM_S370:
        return tr("IBM System/370");
    case EM_MIPS_RS3_LE:
        return tr("MIPS R3000 little-endian");
    case EM_PARISC:
        return tr("HPPA");
    case EM_960:
        return tr("Intel 80960");
    case EM_PPC:
        return tr("PowerPC");
    case EM_PPC64:
        return tr("64-bit PowerPC");
    case EM_S390:
        return tr("IBM S/390");
    case EM_SPU:
        return tr("Sony/Toshiba/IBM SPU");
    case EM_V800:
        return tr("NEC V800 series");
    case EM_FR20:
        return tr("Fujitsu FR20");
    case EM_RH32:
        return tr("TRW RH32");
    case EM_MCORE:
        return tr("Motorola MCore");
    case EM_ARM:
        return tr("ARM");
    case EM_OLD_ALPHA:
        return tr("Digital Alpha");
    case EM_SH:
        return tr("Renesas SuperH");
    case EM_SPARCV9:
        return tr("SPARC v9 64-bit");
    case EM_TRICORE:
        return tr("Siemens Tricore");
    case EM_ARC:
        return tr("ARC Cores");
    case EM_H8_300:
        return tr("Renesas H8/300");
    case EM_H8_300H:
        return tr("Renesas H8/300H");
    case EM_H8S:
        return tr("Renesas H8S");
    case EM_H8_500:
        return tr("Renesas H8/500");
    case EM_IA_64:
        return tr("Intel IA-64 ");
    case EM_MIPS_X:
        return tr("Stanford MIPS-X");
    case EM_COLDFIRE:
        return tr("Motorola Coldfire");
    case EM_68HC12:
        return tr("Motorola M68HC12");
    case EM_MMA:
        return tr("Fujitsu Multimedia Accelerator");
    case EM_PCP:
        return tr("Siemens PCP");
    case EM_NCPU:
        return tr("Sony nCPU embedded RISC processor");
    case EM_NDR1:
        return tr("Denso NDR1");
    case EM_STARCORE:
        return tr("Motorola StarCore");
    case EM_ME16:
        return tr("Toyota ME16");
    case EM_ST100:
        return tr("STMicroelectronics ST100");
    case EM_TINYJ:
        return tr("Advanced Logic Corp. Tiny3");
    case EM_X86_64:
        return tr("AMD x86-64");
    case EM_PDSP:
        return tr("Sony DSP");
    case EM_PDP10:
        return tr("Digital Equipment Corp. PDP-10");
    default:
        return unkownValue(value);
    }
}

QString ELFValueConvertor::eVersionToDisp(elf::Elf_Word value)
{
    switch (value) {
    case EV_NONE:
        return tr("Invalid (0x0)");
    case EV_CURRENT:
        return tr("Current (0x1)");
    default:
        return unkownValue(value);
    }
}

QString ELFValueConvertor::tr(const char *s)
{
    return QObject::tr(s);
}

ELFValueConvertor::ELFValueConvertor() = default;
