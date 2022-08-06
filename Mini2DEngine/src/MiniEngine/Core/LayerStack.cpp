#include "mepch.h"
#include "LayerStack.h"

namespace MiniEngine
{
	LayerStack::~LayerStack()
	{
		for (Layer* layer : layers)
		{
			layer->OnDetach();
			delete layer;
		}
	}
	void LayerStack::PushLayer(Layer* layer)
	{
		layers.emplace(layers.begin() + indexLastInsertion, layer);
		indexLastInsertion++;
		layer->OnAttach();
	}
	void LayerStack::PopLayer(Layer* layer)
	{
		auto it = std::find(layers.begin(), layers.begin() + indexLastInsertion, layer);
		if (it != layers.begin() + indexLastInsertion)
		{
			layer->OnDetach();
			layers.erase(it);
			indexLastInsertion--;
		}
	}
}