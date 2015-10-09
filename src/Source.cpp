#include "Entity.h"
#include "ComponentA.h"
#include "ComponentB.h"
#include <vector>

int main()
{
	Entity e{ "AB" };
	e.add_component<ComponentA>(43);
	e.add_component<ComponentB>(23, 12);
	e.update();

	std::vector<Entity> entities;
	entities.emplace_back("A");
	//The above doesn't work. Make it work.
}
