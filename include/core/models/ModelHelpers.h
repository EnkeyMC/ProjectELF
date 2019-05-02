#ifndef MODELHELPERS_H
#define MODELHELPERS_H

#define HEX_ELF_PROP_DECL(name, capitalizedName) \
    Q_PROPERTY(QString name READ get##capitalizedName WRITE set##capitalizedName NOTIFY name##Changed) \
    Q_PROPERTY(QString disp##capitalizedName READ getDisp##capitalizedName NOTIFY name##Changed) \
    Q_PROPERTY(unsigned name##ByteSize READ get##capitalizedName##ByteSize CONSTANT) \
    public: QString get##capitalizedName(void) const; \
            void set##capitalizedName(QString hexValue); \
            QString getDisp##capitalizedName(void) const; \
            unsigned get##capitalizedName##ByteSize() const; \
    Q_SIGNALS: void name##Changed(QString hexValue); \
    private:

#define HEX_ELF_PROP_GET_GETBYTES_SET(_class, name, capitalizedName, elfStruct, elfName, elfType) \
    QString _class::get##capitalizedName() const { \
        if (elfStruct == nullptr) return QString(); \
        return QString::number(elfStruct->get_##elfName(), 16).rightJustified(elfStruct->get_sizeof_##elfName(), '0'); \
    } \
    unsigned _class::get##capitalizedName##ByteSize() const { \
        if (elfStruct == nullptr) return 0; \
        return elfStruct->get_sizeof_##elfName(); \
    } \
    void _class::set##capitalizedName(QString hexValue) { \
        elfStruct->set_##elfName(static_cast<elfType>(hexValue.toUInt(nullptr, 16))); \
        emit name##Changed(hexValue); \
        this->getModel()->setModified(true); \
    }

#endif // MODELHELPERS_H
