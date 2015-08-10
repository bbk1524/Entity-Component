#include <iostream>
#include <vector>
#include <memory>

#include "Component.h"
#include "ComponentA.h"
#include "Entity.h"

int main()
{
	Entity e{ "AB" };
	e.update();
#ifdef _WIN32
	system("Pause");
#endif
}
