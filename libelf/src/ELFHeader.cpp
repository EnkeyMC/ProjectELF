//
// Created by MOmac on 06.03.2019.
//

#include "ELFHeader.h"

namespace elf {

ELFHeader::ELFHeader(const ELF &elf, const endianess_converter &convertor) : converter(convertor), elf(elf) {}
}
