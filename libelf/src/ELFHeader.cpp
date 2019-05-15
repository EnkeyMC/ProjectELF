//
// Created by MOmac on 06.03.2019.
//

#include "ELFHeader.h"
#include "ELF.h"

namespace elf {

ELFHeader::ELFHeader(ELF &elf) : ELFStructureBase(elf), header_valid(false) {}

bool ELFHeader::is_header_valid() const {
    return header_valid;
}

void ELFHeader::set_header_valid(bool valid) {
    header_valid = valid;
}

}
