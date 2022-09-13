#pragma once
#include "MiniEngine.h"
#include "../Level.h"

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
		Pathfinder(Cell& cellFrom, Cell& cellTo, Cell* levelPtrBase, uint16_t levelSize)
			: levelPtrBase(levelPtrBase), levelSize(levelSize)
		{
			this->cellFrom.cell = &cellFrom;
			this->cellTo.cell = &cellTo;
		}

		uint16_t CalculatePath(Cell* pathBuffer);

	private:
		PathElem cellFrom, cellTo;
		Cell* levelPtrBase;
		uint16_t levelSize;
		std::vector<PathElem> openList;
		std::vector<PathElem> closedList;

		bool Finished();
		std::vector<Cell&> GetNeighbours(Cell& searchCell);
		bool DoesListContainCell(Cell& cell, std::vector<PathElem>& list);
		void RemovePathElem(PathElem& pathElem, std::vector<PathElem>& list);
		uint16_t CalculateG(PathElem& currentPathElem);
	};
}