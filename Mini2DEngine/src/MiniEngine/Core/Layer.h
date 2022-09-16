#pragma once
#include "mepch.h"
#include "MiniEngine/Core/core.h"

namespace MiniEngine
{
	class Layer
	{
	public:
		Layer(const std::string& name = "Layer") {layerName = name; };
		virtual ~Layer() = default;

		virtual void OnAttach() = 0;
		virtual void OnDetach() = 0;
		virtual void OnUpdate(float deltaTime) = 0;

		const std::string GetName() { return layerName; }

	private:
		std::string layerName;
	};
}