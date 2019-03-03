//
// Created by MOmac on 03.03.2019.
//

#include "ELFIssue.h"

ELFIssue::ELFIssue(enum ELFIssueType type, enum ELFIssueSource source, const std::string &message)
    : type(type), source(source), message(message)
{

}

ELFIssueType ELFIssue::get_type() const {
    return type;
}

ELFIssueSource ELFIssue::get_source() const {
    return source;
}

const std::string &ELFIssue::get_message() const {
    return message;
}
