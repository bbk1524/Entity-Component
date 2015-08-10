#pragma once

#include "Component.h"

class ComponentB : public Component
{
public:
	ComponentB(Entity* owner);
	~ComponentB() = default;
	void update() override;
	void init(int b);
//private:
	int b;
};