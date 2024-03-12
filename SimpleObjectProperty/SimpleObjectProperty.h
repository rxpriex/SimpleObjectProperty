#ifndef SIMPLE_O_PROPERTY_H
#define SIMPLE_O_PROPERTY_H

#include <functional>
#include <utility>
#include <vector>

template <typename objectType> class SimpleObjectProperty {
public:
	template<typename... Args>
	SimpleObjectProperty(Args&&... args) :value(new objectType(std::forward<Args>(args)...)) {
		listeners = new std::vector<std::function<void(objectType&, objectType&)>>();
	}

	~SimpleObjectProperty() {
		delete value;
		listeners->clear();
		delete listeners;
	}

	virtual void addListener(std::function<void(objectType&, objectType&)> listener);

	template<typename... Args>
	void setValue(Args&&... args);

	virtual objectType& getValue();

	void operator=(SimpleObjectProperty& other) {
		setValue(other);
	}

private:
	objectType* value;
	std::vector<std::function<void(objectType&, objectType&)>>* listeners;
};

#include "SimpleObjectProperty.cpp"

#endif // !SIMPLE_O_PROPERTY_H