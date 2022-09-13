#include "Ghost.h"
#include "StateIdle.h"

PacmanGame::Ghost::Ghost(std::string&& name, float x, float y, MiniEngine::Ref<MiniEngine::Texture> texture)
	: MiniEngine::Entity(std::move(name), x, y, 20.0f, 20.0f, 0.0f, texture), direction(0.0f, 0.0f)
{
	StateIdle* initialState = new StateIdle();
	SetState(*initialState);
	initialState->SetContext(*this);
	initialState->EntryActions();


}
