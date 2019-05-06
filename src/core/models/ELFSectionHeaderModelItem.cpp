//
// Created by MOmac on 17.03.2019.
//

#include "core/models/ELFSectionHeaderModelItem.h"

#define ELF_STRUCT elf->get_section_headers()[index]

ELFSectionHeaderModelItem::ELFSectionHeaderModelItem(ELFModel *parent, std::shared_ptr<elf::ELF> elf, unsigned index)
    : ELFIndexedModelItem(parent, std::move(elf), index)
{
    auto header = this->elf->get_header();
    sizeInFile = header->get_e_shentsize();
    addressInFile = header->get_e_shoff() + index * header->get_e_shentsize();
    sectionModelItem = new ELFSectionModelItem(parent, this->elf, this->index);
}

ELFSectionHeaderModelItem::~ELFSectionHeaderModelItem() {
    delete sectionModelItem;
}

ELFSectionModelItem *ELFSectionHeaderModelItem::getSectionModelItem() const
{
    return this->sectionModelItem;
}

HEX_ELF_PROP_GET_GETBYTES_SET(ELFSectionHeaderModelItem, name, Name, ELF_STRUCT, sh_name, elf::Elf_Word)
HEX_ELF_PROP_GET_GETBYTES_SET(ELFSectionHeaderModelItem, type, Type, ELF_STRUCT, sh_type, elf::Elf_Word)
HEX_ELF_PROP_GET_GETBYTES_SET(ELFSectionHeaderModelItem, flags, Flags, ELF_STRUCT, sh_flags, elf::Elf_Xword)
HEX_ELF_PROP_GET_GETBYTES_SET(ELFSectionHeaderModelItem, addr, Addr, ELF_STRUCT, sh_addr, elf::Elf64_Addr)
HEX_ELF_PROP_GET_GETBYTES_SET(ELFSectionHeaderModelItem, offset, Offset, ELF_STRUCT, sh_offset, elf::Elf64_Off)
HEX_ELF_PROP_GET_GETBYTES_SET(ELFSectionHeaderModelItem, size, Size, ELF_STRUCT, sh_size, elf::Elf_Xword)
HEX_ELF_PROP_GET_GETBYTES_SET(ELFSectionHeaderModelItem, link, Link, ELF_STRUCT, sh_link, elf::Elf_Word)
HEX_ELF_PROP_GET_GETBYTES_SET(ELFSectionHeaderModelItem, info, Info, ELF_STRUCT, sh_info, elf::Elf_Word)
HEX_ELF_PROP_GET_GETBYTES_SET(ELFSectionHeaderModelItem, addralign, Addralign, ELF_STRUCT, sh_addralign, elf::Elf_Xword)
HEX_ELF_PROP_GET_GETBYTES_SET(ELFSectionHeaderModelItem, entsize, Entsize, ELF_STRUCT, sh_entsize, elf::Elf_Xword)

HEX_ELF_PROP_GETDISP_NAME(ELFSectionHeaderModelItem, Name, ELF_STRUCT, sh_name)
HEX_ELF_PROP_GETDISP_DEFAULT(ELFSectionHeaderModelItem, Type)
HEX_ELF_PROP_GETDISP_DEFAULT(ELFSectionHeaderModelItem, Flags)
HEX_ELF_PROP_GETDISP_DEFAULT(ELFSectionHeaderModelItem, Addr)
HEX_ELF_PROP_GETDISP_DEFAULT(ELFSectionHeaderModelItem, Offset)
HEX_ELF_PROP_GETDISP_BYTES(ELFSectionHeaderModelItem, Size, ELF_STRUCT, sh_size)
HEX_ELF_PROP_GETDISP_DEFAULT(ELFSectionHeaderModelItem, Link)
HEX_ELF_PROP_GETDISP_DEFAULT(ELFSectionHeaderModelItem, Info)
HEX_ELF_PROP_GETDISP_DEFAULT(ELFSectionHeaderModelItem, Addralign)
HEX_ELF_PROP_GETDISP_BYTES(ELFSectionHeaderModelItem, Entsize, ELF_STRUCT, sh_entsize)
