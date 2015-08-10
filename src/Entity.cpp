#include "Entity.h"

#include "Component.h"
#include "ComponentA.h"
#include "ComponentB.h"

#include <memory>


//How the heck am I supposed to pass stuff to the 
//init functions?
//In my final, I passed in a Game* and an x,y,angle
Entity::Entity(std::string type)
{
	if (type == "A")
	{
		auto pA = std::make_unique<ComponentA>(this);
		pA->init(34);
		components.push_back(std::move(pA));
	}

	if (type == "B")
	{
		auto pB = std::make_unique<ComponentB>(this);
		pB->init(4);
		components.push_back(std::move(pB));
	}

	if (type == "AB")
	{
		auto pA = std::make_unique<ComponentA>(this);
		pA->init(34);
		components.push_back(std::move(pA));

		auto pB = std::make_unique<ComponentB>(this);
		pB->init(this->get_component<ComponentA>()->a + 1);
		components.push_back(std::move(pB));
	}
}

void Entity::update()
{
	for (auto& c : components)
	{
		c->update();
	}
}