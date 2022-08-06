#pragma once
#include "MiniEngine.h"

class Sandbox : public MiniEngine::Layer
{
public:
	Sandbox() : Layer("Sandbox layer") {};
	virtual ~Sandbox() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;
	void OnUpdate(float deltaTime) override;
};