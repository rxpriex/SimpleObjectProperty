#ifndef SIMPLE_O_PROPERTY_H
#define SIMPLE_O_PROPERTY_H

#include <functional>
#include <utility>
#include <iostream>
#include <set>

template <typename objectType> class SimpleObjectProperty {
public:
	template<typename... Args>
	SimpleObjectProperty(Args&&... args) :value(new objectType(std::forward<Args>(args)...)) {
		listeners = new std::set<std::function(objectType&, objectType&)>();
	}

	~SimpleObjectProperty() {
		delete value;
		listeners->clear();
		delete listeners;
	}

	virtual void setValue(objectType value);

	virtual objectType& getValue();

	virtual void addListener(std::function<void(objectType&, objectType&)> listener);

	void operator=(SimpleObjectProperty& other) {
		setValue(other);
	}

private:
	objectType* value;
	std::set<std::function<void(objectType&, objectType&)>()>* listeners;
};

#endif // !SIMPLE_O_PROPERTY_H