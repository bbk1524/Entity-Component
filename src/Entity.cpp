#include "Entity.h"

#include "Component.h"
#include "ComponentA.h"
#include "ComponentB.h"

#include <memory>


//How the heck am I supposed to pass stuff to the 
//init functions?
//In my final, I passed in a Game* and an x,y,angle

//I want to use the standard system of each component having only data, and making "Systems" which read and write to the components on update
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
        pB->init(pB->get_owner()->get_component<ComponentA>()->a * 2);
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