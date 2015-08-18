#pragma once

#include "Component.h"

class ComponentB : public Component
{
public:
	ComponentB(Entity* owner);
	~ComponentB() = default;
	void update() override;
	void init(int b1, int b2);
//private:
	int b;
};