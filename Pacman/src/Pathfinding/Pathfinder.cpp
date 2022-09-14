#include "Pathfinder.h"

#define G_HORVER 10

namespace PacmanGame
{

    Pathfinder* Pathfinder::instance = nullptr;

    uint16_t Pathfinder::CalculatePath(Cell* cellFrom, Cell* cellTo, std::vector<Cell>& pathBuffer)
    {
        uint16_t pathLength = 1;

        for (int i = 0; i < levelSize; i++)
        {
            if (levelPtrBase[i].cell->id == cellFrom->id)
                this->cellFrom = &levelPtrBase[i];
            if (levelPtrBase[i].cell->id == cellTo->id)
                this->cellTo = &levelPtrBase[i];
        }

        if(cellFrom != nullptr && cellTo != nullptr)
        {
            PathElem* currentCell = this->cellFrom;
            openList.push_back(currentCell);

            do
            {
                RemovePathElem(*currentCell, openList);
                closedList.push_back(currentCell);

                std::vector<PathElem*> neighbours = GetNeighbours(currentCell->cell);
                for (PathElem* neighbour : neighbours)
                {
                    if (DoesListContainCell(neighbour->cell, openList))
                    {
                        uint16_t moveG = CalculateG(*currentCell);
                        if (currentCell->G + moveG < neighbour->G) //This path is better
                        {
                            neighbour->parentElem = currentCell;
                            neighbour->G = moveG;
                        }
                    }
                    else
                    {
                        neighbour->G = CalculateG(*currentCell);
                        neighbour->parentElem = currentCell;
                        openList.push_back(neighbour);
                    }
                }

                if (openList.size() == 0)
                {
                    std::cout << "Couldn't find path" << std::endl;
                    return 0;
                }
                PathElem* lowestGElem = openList[0];
                for (PathElem* e : openList)
                {
                    if (e->G < lowestGElem->G && !DoesListContainCell(e->cell, closedList))
                        lowestGElem = e;
                }
                currentCell = lowestGElem;
            } while (!Finished());

            //Fill buffer
            PathElem* iterElem = this->cellTo;
            while (iterElem->cell->id != cellFrom->id)
            {
                pathLength++;
                iterElem = iterElem->parentElem;
            }

            pathBuffer.resize(pathLength);
            PathElem* currElem = this->cellTo;
            for (int i = 1; i <= pathLength; i++)
            {
                pathBuffer[pathLength - i] = *currElem->cell;
                currElem = currElem->parentElem;
            }

            //Cleanup
            openList.clear();
            closedList.clear();
        }
        return pathLength;
    }

    bool Pathfinder::Finished()
    {
        return DoesListContainCell(cellTo->cell, closedList);
    }

    std::vector<PathElem*> Pathfinder::GetNeighbours(Cell* searchCell)
    {
        std::vector<PathElem*> returnList;

        //TODO: Replace hardcoded level width 40

        //Top
        PathElem* top = &levelPtrBase[((searchCell->y - 1) * 40) + searchCell->x];
        if(top->cell->type != CellType::Wall && !DoesListContainCell(top->cell, closedList))
            returnList.push_back(top);
        //Left
        PathElem* left = &levelPtrBase[(searchCell->y * 40) + searchCell->x - 1];
        if (left->cell->type != CellType::Wall && !DoesListContainCell(left->cell, closedList))
            returnList.push_back(left);
        //Bottom
        PathElem* bottom = &levelPtrBase[((searchCell->y + 1) * 40) + searchCell->x];
        if (bottom->cell->type != CellType::Wall && !DoesListContainCell(bottom->cell, closedList))
            returnList.push_back(bottom);
        //Right
        PathElem* right = &levelPtrBase[(searchCell->y * 40) + searchCell->x + 1];
        if (right->cell->type != CellType::Wall && !DoesListContainCell(right->cell, closedList))
            returnList.push_back(right);

        return returnList;
    }

    bool Pathfinder::DoesListContainCell(Cell* cell, std::vector<PathElem*>& list)
    {
        for (PathElem* e : list)
        {
            if (e->cell->id == cell->id)
            {
                return true;
            }
        }
        return false;
    }

    void Pathfinder::RemovePathElem(PathElem& pathElem, std::vector<PathElem*>& list)
    {
        list.erase(std::remove_if(begin(list), end(list), [pathElem](PathElem* e)
            {
                return e->cell->id == pathElem.cell->id;
            }), list.end());
    }
    uint16_t Pathfinder::CalculateG(PathElem& currentPathElem)
    {
        return currentPathElem.G + G_HORVER;
    }
}
