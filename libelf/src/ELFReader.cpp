//
// Created by MOmac on 02.03.2019.
//

#include "ELFReader.h"

elf::ELFReader::ELFReader(std::istream &istream, elf::ELF &output) : istream(istream), elf(output) {

}
