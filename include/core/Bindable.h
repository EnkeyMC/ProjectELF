//
// Created by MOmac on 25.04.2019.
//

#ifndef PROJECTELF_BINDABLE_H
#define PROJECTELF_BINDABLE_H

#include <type_traits>

template <typename T>
class Bindable {
public:
    Bindable();
    Bindable(T value);

    ~Bindable();

    const T &get() const;

    void set(T newValue);

    void bindTo(Bindable<T> &bindable);

    void bindBidirectional(Bindable<T> &bindable);

    Bindable<T> &operator=(const T& newValue);

    Bindable<T> &operator=(T&& newValue) noexcept;

private:
    void valueChanged();

    void onValueChanged(T newValue);

    Bindable<T> *bound;

    T value;
};

template<typename T>
Bindable<T>::Bindable() {
    bound = nullptr;
}

template<typename T>
Bindable<T>::Bindable(T value) {
    this->bound = nullptr;
    this->value = value;
}

template<typename T>
Bindable<T>::~Bindable() {
    if (bound != nullptr) {
        if (bound->bound == this)
            bound->bound = nullptr;
    }
}

template<typename T>
void Bindable<T>::set(T newValue) {
    if (this->value != newValue) {
        this->value = newValue;
        this->valueChanged();
    }
}

template<typename T>
Bindable<T> &Bindable<T>::operator=(const T &newValue) {
    if (this->value != newValue) {
        this->value = newValue;
        this->valueChanged();
    }
    return *this;
}

template<typename T>
Bindable<T> &Bindable<T>::operator=(T &&newValue) noexcept {
    if (this->value != newValue) {
        this->value = newValue;
        this->valueChanged();
    }
    return *this;
}

template<typename T>
const T &Bindable<T>::get() const {
    return this->value;
}

template<typename T>
void Bindable<T>::valueChanged() {
    if (bound != nullptr)
        bound->onValueChanged(value);
}

template<typename T>
void Bindable<T>::onValueChanged(T newValue) {
    if (this->value != newValue) {
        this->value = newValue;
    }
}

template<typename T>
void Bindable<T>::bindTo(Bindable<T> &bindable) {
    assert(bound == nullptr);
    if (this == &bindable)
        throw std::invalid_argument("Cannot bind bindable to self");

    this->value = bindable.value;
    bindable.bound = this;
}

template<typename T>
void Bindable<T>::bindBidirectional(Bindable<T> &bindable) {
    assert(bound == nullptr);
    if (this == &bindable)
        throw std::invalid_argument("Cannot bind bindable to self");

    this->value = bindable.value;
    this->bound = &bindable;
    bindable.bound = this;
}


#endif //PROJECTELF_BINDABLE_H
