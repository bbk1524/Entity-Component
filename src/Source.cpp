#include "Entity.h"
#include "ComponentA.h"
#include "ComponentB.h"
int main()
{
	Entity e{ "AB" };
	e.add_component<ComponentA>(43);
	e.add_component<ComponentB>(23, 12);
	e.update();
}
