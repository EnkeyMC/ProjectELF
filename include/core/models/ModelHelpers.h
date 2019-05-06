#ifndef MODELHELPERS_H
#define MODELHELPERS_H

#define HEX_ELF_PROP_DECL(name, capitalizedName) \
    Q_PROPERTY(QString name READ get##capitalizedName WRITE set##capitalizedName NOTIFY name##Changed) \
    Q_PROPERTY(QString disp##capitalizedName READ getDisp##capitalizedName NOTIFY name##Changed) \
    Q_PROPERTY(unsigned name##ByteSize READ get##capitalizedName##ByteSize CONSTANT) \
    public: QString get##capitalizedName(void) const; \
            void set##capitalizedName(const QString &hexValue); \
            QString getDisp##capitalizedName(void) const; \
            unsigned get##capitalizedName##ByteSize() const; \
    Q_SIGNALS: void name##Changed(QString hexValue); \
    private:

#define HEX_ELF_PROP_GET_GETBYTES_SET(_class, name, capitalizedName, elfStruct, elfName, elfType) \
    QString _class::get##capitalizedName() const { \
        if (elfStruct == nullptr) return QString(); \
        return QString::number(elfStruct->get_##elfName(), 16).rightJustified(static_cast<int>(elfStruct->get_sizeof_##elfName()*2), '0'); \
    } \
    unsigned _class::get##capitalizedName##ByteSize() const { \
        if (elfStruct == nullptr) return 0; \
        return elfStruct->get_sizeof_##elfName(); \
    } \
    void _class::set##capitalizedName(const QString &hexValue) { \
        if (hexValue == get##capitalizedName()) return; \
        elfStruct->set_##elfName(static_cast<elfType>(hexValue.toULongLong(nullptr, 16))); \
        emit name##Changed(hexValue); \
        emit dataChanged(); \
    }

#define HEX_ELF_PROP_GETDISP_W_CONVERTER(_class, capitalizedName, elfStruct, elfName, converterFunc) \
    QString _class::getDisp##capitalizedName() const { \
        if (elfStruct == nullptr) return QString(); \
        return ELFValueConverter::converterFunc(elfStruct->get_##elfName()); \
    }

#define HEX_ELF_PROP_GETDISP_DEFAULT(_class, capitalizedName) \
    QString _class::getDisp##capitalizedName() const { \
        return QString("0x") + get##capitalizedName(); \
    }

#define HEX_ELF_PROP_GETDISP_NAME(_class, capitalizedName, elfStruct, elfName) \
    QString _class::getDisp##capitalizedName() const { \
        if (elfStruct == nullptr) return QString(); \
        auto name = elf->get_name(elfStruct->get_##elfName()); \
        if (name == nullptr) return "<<INVALID>>"; \
        return name; \
    }

#define HEX_ELF_PROP_GETDISP_BYTES(_class, capitalizedName, elfStruct, elfName) \
    QString _class::getDisp##capitalizedName() const { \
        if (elfStruct == nullptr) return QString(); \
        return QString::number(elfStruct->get_##elfName()) + " B"; \
    }

#define HEX_ELF_PROP_GETDISP_DECIMAL(_class, capitalizedName, elfStruct, elfName) \
    QString _class::getDisp##capitalizedName() const { \
        if (elfStruct == nullptr) return QString(); \
        return QString::number(elfStruct->get_##elfName()); \
    }

#endif // MODELHELPERS_H
