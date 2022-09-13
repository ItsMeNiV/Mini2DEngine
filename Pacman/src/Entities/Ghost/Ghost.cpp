#include "Ghost.h"
#include "StateIdle.h"
#include "../../Pathfinding/Pathfinder.h"

PacmanGame::Ghost::Ghost(std::string&& name, float x, float y, MiniEngine::Ref<MiniEngine::Texture> texture, MiniEngine::Ref<Level> levelRef)
	: MiniEngine::Entity(std::move(name), x, y, 20.0f, 20.0f, 0.0f, texture), direction(0.0f, 0.0f), levelRef(levelRef)
{
	StateIdle* initialState = new StateIdle();
	SetState(*initialState);
	initialState->SetContext(*this);
	initialState->EntryActions();

	//Check pathfinding
	Cell* cellFrom = &levelRef->GetLevelCellsPtrBase()[40 * ((int)y/20 + 3) + (int)x / 20];
	Cell* cellTo = levelRef->GetCellsByCellType(CellType::PacmanSpawn)[0];
	std::vector<Cell> pathBuffer;
	clock_t start = clock();
	Pathfinder::GetInstance().CalculatePath(cellFrom, cellTo, pathBuffer);
	clock_t timeUsed = clock() - start;
	std::cout << "Pathfinding took " << std::to_string(timeUsed) << "ms" << std::endl; //TODO: Fix pathBuffer is empty
}
