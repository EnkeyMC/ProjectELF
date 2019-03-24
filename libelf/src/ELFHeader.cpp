//
// Created by MOmac on 06.03.2019.
//

#include "ELFHeader.h"
#include "ELF.h"

namespace elf {

ELFHeader::ELFHeader(const ELF &elf) : elf(elf) {}

ELFHeader::~ELFHeader() {

}

}
