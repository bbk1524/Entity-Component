#pragma once

#include "Component.h"
#include <iostream>

class ComponentA : public Component
{
public:
	ComponentA(Entity* owner);
	~ComponentA() = default;
	void update() override;
	void init(int a);
	int a;
};
