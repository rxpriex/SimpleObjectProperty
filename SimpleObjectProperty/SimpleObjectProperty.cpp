#ifndef SIMPLE_O_PROPERTY_CPP
#define SIMPLE_O_PROPERTY_CPP

#include "SimpleObjectProperty.h"

template <typename objectType>
void SimpleObjectProperty<objectType>::addListener(std::function<void(objectType&, objectType&)> listener) {
	listeners->push_back(listener);
}

template <typename objectType>
objectType& SimpleObjectProperty<objectType>::getValue() {
	return *value;
}

template <typename objectType>
template <typename... Args>
void SimpleObjectProperty<objectType>::setValue(Args&&... arg) {
	objectType* newVal = new objectType(std::forward<Args>(arg)...);
	for (int i = 0; i < listeners->size();i++) {
		(listeners->at(i))(*this->value,*newVal);
	}

	delete this->value;
	this->value = newVal;
}

#endif // !SIMPLE_O_PROPERTY_CPP