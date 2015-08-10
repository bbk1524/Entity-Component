#pragma once
#include <string>
#include <vector>
#include <memory>

#include "Component.h"

class Entity
{
public:
	Entity(std::string type);
	~Entity() = default;
	void update();

	//Don't assign this to anything in callers!!!
	template<typename T>
	T* get_component()
	{
		for (auto& c : components)
		{
			T* result = dynamic_cast<T*>(c.get());
			if (result != nullptr) { return result; }
		}
		return nullptr;
	}

private:
	std::vector<std::unique_ptr<Component>> components;
	//bool is_valid{ false };
};