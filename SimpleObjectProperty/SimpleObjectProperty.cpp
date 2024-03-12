#include "SimpleObjectProperty.h"

template <typename objectType>
void SimpleObjectProperty<objectType>::addListener(std::function<void(objectType&, objectType&)> listener) {
	listeners->insert(listener);
}

template <typename objectType>
objectType& SimpleObjectProperty<objectType>::getValue() {
	return *value;
}

template <typename objectType>
void setValue(objectType value) {
	delete this->value;
	this->value = &value;
}