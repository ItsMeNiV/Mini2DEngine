#include "Sandbox.h"

#include <iostream>

void Sandbox::OnAttach()
{
	std::cout << "Layer attached" << std::endl;
}

void Sandbox::OnDetach()
{
	std::cout << "Layer detached" << std::endl;
}

void Sandbox::OnUpdate(float deltaTime)
{
	std::cout << "Sandbox Layer updated" << std::endl;
}
