#include "ComponentA.h"

#include "Entity.h"

ComponentA::ComponentA(Entity* owner)
	: Component(owner)
{}

void ComponentA::update()
{
	std::cout << "Hello from A" << std::endl;
}

void ComponentA::init(int a)
{
	this->a = a;
}