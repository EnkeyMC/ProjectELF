//
// Created by MOmac on 29.04.2019.
//

#include <QObject>

#include "core/ELFIssueConverter.h"

QString ELFIssueConverter::toReadable(const elf::ELFIssue &issue) {
    return severityToReadable(issue.get_severity()) + ": " + sourceToReadable(issue.get_source(), issue.get_index())
        + " " + typeToReadable(issue.get_type()) + ".";
}

QString ELFIssueConverter::severityToReadable(elf::ELFIssueSeverity severity) {
    switch (severity) {
        case elf::ISEV_WARNING:
            return tr("Warning");
        case elf::ISEV_ERROR:
            return tr("Error");
        case elf::ISEV_CRITICAL:
            return tr("Critical");
        default:
            return "";
    }
}

QString ELFIssueConverter::sourceToReadable(elf::ELFIssueSource source, unsigned index) {
    switch (source) {
        case elf::ISRC_HEADER:
            return tr("Header");
        case elf::ISRC_EI_MAGN:
            return "EI_MAG";
        case elf::ISRC_EI_CLASS:
            return "EI_CLASS";
        case elf::ISRC_EI_DATA:
            return "EI_DATA";
        case elf::ISRC_E_VERSION:
            return "E_VERSION";
        case elf::ISRC_E_ENTRY:
            return "E_ENTRY";
        case elf::ISRC_E_PHOFF:
            return "E_PHOFF";
        case elf::ISRC_E_PHENTSIZE:
            return "E_PHENTSIZE";
        case elf::ISRC_E_PHNUM:
            return "E_PHNUM";
        case elf::ISRC_E_SHOFF:
            return "E_SHOFF";
        case elf::ISRC_E_SHENTSIZE:
            return "E_SHENTSIZE";
        case elf::ISRC_E_SHNUM:
            return "E_SHNUM";
        case elf::ISRC_E_EHSIZE:
            return "E_EHSIZE";
        case elf::ISRC_E_SHSTRNDX:
            return "E_SHSTRNDX";
        case elf::ISRC_SECTION_HEADERS:
            return tr("Section Header Table");
        case elf::ISRC_SH_NAME:
            return tr("SH_NAME in section header #%1").arg(QString::number(index));
        case elf::ISRC_SH_OFFSET:
            return tr("SH_OFFSET in section header #%1").arg(QString::number(index));
        case elf::ISRC_SH_SIZE:
            return tr("SH_SIZE in section header #%1").arg(QString::number(index));
        case elf::ISRC_SH_ENTSIZE:
            return tr("SH_ENTSIZE in section header #1").arg(QString::number(index));
        case elf::ISRC_PROGRAM_HEADERS:
            return tr("Program Header Table");
        case elf::ISRC_P_OFFSET:
            return tr("P_OFFSET in program header #%1").arg(QString::number(index));
        case elf::ISRC_P_FILESZ:
            return tr("P_FILESZ in program header #%1").arg(QString::number(index));
        case elf::ISRC_SECTION:
            return tr("Section #%1").arg(QString::number(index));
        case elf::ISRC_SEGMENT:
            return tr("Segment #%1").arg(QString::number(index));
        default:
            return "";
    }
}

QString ELFIssueConverter::typeToReadable(elf::ELFIssueType type) {
    switch (type) {
        case elf::ITYPE_OVERLAPS_SECTION:
            return tr("overlaps other section");
        case elf::ITYPE_OUT_OF_BOUNDS:
            return tr("is out of file bounds");
        case elf::ITYPE_OVERLAPS_HEADER:
            return tr("overlaps header");
        case elf::ITYPE_INVALID:
            return tr("has invalid value");
        case elf::ITYPE_UNEXPECTED_EOF:
            return tr("could not be read from the file");
        default:
            return "";
    }
}

QString ELFIssueConverter::tr(const char *s) {
    return QObject::tr(s);
}
