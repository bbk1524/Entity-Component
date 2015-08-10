#include "ComponentB.h"
#include "ComponentA.h"
#include <iostream>

#include "Entity.h"
ComponentB::ComponentB(Entity* owner)
	: Component(owner)
{}

void ComponentB::update()
{

	std::cout << "Hello from B " << b << std::endl;
}

void ComponentB::init(int b)
{
	this->b = b;
}