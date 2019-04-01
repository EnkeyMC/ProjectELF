//
// Created by MOmac on 30.03.2019.
//

#include "ELFProgramHeader.h"
#include "ELFStructureBase.h"
#include "ELF.h"

elf::ELFStructureBase::~ELFStructureBase() = default;

elf::ELFStructureBase::ELFStructureBase(ELF &elf) : elf(elf) {

}