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

void ComponentB::init(int b1, int b2)
{
	this->b = b1 * b2;
}