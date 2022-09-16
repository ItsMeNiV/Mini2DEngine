#pragma once
#include <MiniEngine.h>
#include "Level.h"

namespace PacmanGame
{
	struct PathElem
	{
		Cell* cell;
		PathElem* parentElem;
		uint16_t G;
	};

	class Pathfinder
	{
    public:
		Pathfinder(Pathfinder& other) = delete;
        void operator=(const Pathfinder&) = delete;
		~Pathfinder() = default;

		static Pathfinder& GetInstance()
		{
			if (instance == nullptr)
				instance = new Pathfinder();
			return *instance;
		}

		void Init(Cell* levelPtrBase, uint16_t levelSize)
		{
			this->levelPtrBase = new PathElem[levelSize];
			this->levelSize = levelSize;

			for (int i = 0; i < levelSize; i++)
				this->levelPtrBase[i].cell = &levelPtrBase[i];
		}

		uint16_t CalculatePath(Cell* cellFrom, Cell* cellTo, std::vector<Cell>& pathBuffer);

	protected:
		Pathfinder() : cellFrom(nullptr), cellTo(nullptr), levelPtrBase(nullptr), levelSize(0) {}
		static Pathfinder* instance;

	private:
		PathElem* cellFrom, * cellTo;
		PathElem* levelPtrBase;
		uint16_t levelSize;
		std::vector<PathElem*> openList;
		std::vector<PathElem*> closedList;

		bool Finished();
		std::vector<PathElem*> GetNeighbours(Cell* searchCell);
		bool DoesListContainCell(Cell* cell, std::vector<PathElem*>& list);
		void RemovePathElem(PathElem& pathElem, std::vector<PathElem*>& list);
		uint16_t CalculateG(PathElem& currentPathElem);
	};
}
