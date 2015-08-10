#include "Component.h"

Component::Component(Entity* owner)
	: owner(owner)
{}

Entity* Component::get_owner()
{
	return owner;
}