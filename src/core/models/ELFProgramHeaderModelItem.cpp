//
// Created by MOmac on 17.03.2019.
//

#include "core/models/ELFProgramHeaderModelItem.h"

#define ELF_STRUCT this->elf->get_program_headers()[index]

ELFProgramHeaderModelItem::ELFProgramHeaderModelItem(ELFModel *parent, std::shared_ptr<elf::ELF> elf, unsigned index)
    : ELFIndexedModelItem(parent, std::move(elf), index), segmentModelItem(nullptr)
{
    onStructureChanged();
}

ELFProgramHeaderModelItem::~ELFProgramHeaderModelItem() {
    delete segmentModelItem;
}

ELFSegmentModelItem *ELFProgramHeaderModelItem::getSegmentModelItem() const
{
    return this->segmentModelItem;
}
HEX_ELF_PROP_GET_GETBYTES_SET(ELFProgramHeaderModelItem, type, Type, ELF_STRUCT, p_type, elf::Elf_Word)
HEX_ELF_PROP_GET_GETBYTES_SET(ELFProgramHeaderModelItem, flags, Flags, ELF_STRUCT, p_flags, elf::Elf_Word)
HEX_ELF_PROP_GET_GETBYTES_SET(ELFProgramHeaderModelItem, offset, Offset, ELF_STRUCT, p_offset, elf::Elf64_Off)
HEX_ELF_PROP_GET_GETBYTES_SET(ELFProgramHeaderModelItem, vaddr, Vaddr, ELF_STRUCT, p_vaddr, elf::Elf64_Addr)
HEX_ELF_PROP_GET_GETBYTES_SET(ELFProgramHeaderModelItem, paddr, Paddr, ELF_STRUCT, p_paddr, elf::Elf64_Addr)
HEX_ELF_PROP_GET_GETBYTES_SET(ELFProgramHeaderModelItem, filesz, Filesz, ELF_STRUCT, p_filesz, elf::Elf_Xword)
HEX_ELF_PROP_GET_GETBYTES_SET(ELFProgramHeaderModelItem, memsz, Memsz, ELF_STRUCT, p_memsz, elf::Elf_Xword)
HEX_ELF_PROP_GET_GETBYTES_SET(ELFProgramHeaderModelItem, align, Align, ELF_STRUCT, p_align, elf::Elf_Xword)

HEX_ELF_PROP_GETDISP_DEFAULT(ELFProgramHeaderModelItem, Type)
HEX_ELF_PROP_GETDISP_DEFAULT(ELFProgramHeaderModelItem, Flags)
HEX_ELF_PROP_GETDISP_DEFAULT(ELFProgramHeaderModelItem, Offset)
HEX_ELF_PROP_GETDISP_DEFAULT(ELFProgramHeaderModelItem, Vaddr)
HEX_ELF_PROP_GETDISP_DEFAULT(ELFProgramHeaderModelItem, Paddr)
HEX_ELF_PROP_GETDISP_BYTES(ELFProgramHeaderModelItem, Filesz, ELF_STRUCT, p_filesz)
HEX_ELF_PROP_GETDISP_BYTES(ELFProgramHeaderModelItem, Memsz, ELF_STRUCT, p_memsz)
HEX_ELF_PROP_GETDISP_DEFAULT(ELFProgramHeaderModelItem, Align)

bool ELFProgramHeaderModelItem::isValid() const {
    return ELF_STRUCT->is_header_valid();
}

void ELFProgramHeaderModelItem::onStructureChanged() {
    auto header = this->elf->get_header();
    sizeInFile = header->get_e_phentsize();
    addressInFile = header->get_e_phoff() + index * header->get_e_phentsize();
    if (ELF_STRUCT->is_header_valid() && segmentModelItem == nullptr) {
        segmentModelItem = new ELFSegmentModelItem(this->getModel(), this->elf, this->index);
    } else if (!ELF_STRUCT->is_header_valid() && segmentModelItem != nullptr) {
        delete segmentModelItem;
        segmentModelItem = nullptr;
    } else if (segmentModelItem != nullptr) {
        emit segmentModelItem->structureChanged();
    }

    emit typeChanged(getType());
    emit flagsChanged(getFlags());
    emit offsetChanged(getOffset());
    emit vaddrChanged(getVaddr());
    emit paddrChanged(getPaddr());
    emit fileszChanged(getFilesz());
    emit memszChanged(getMemsz());
    emit alignChanged(getAlign());
}
