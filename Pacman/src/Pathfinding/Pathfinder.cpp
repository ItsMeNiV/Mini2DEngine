#include "Pathfinder.h"

#define G_HORVER 10

namespace PacmanGame
{
    uint16_t Pathfinder::CalculatePath(Cell* pathBuffer)
    {
        uint16_t pathLength = 0;
        PathElem& currentCell = cellFrom;
        openList.push_back(currentCell);

        while (!Finished())
        {
            RemovePathElem(currentCell, openList);
            closedList.push_back(currentCell);

            std::vector<Cell&> neighbours = GetNeighbours(*currentCell.cell);
            for (Cell& neighbourCell : neighbours)
            {
                PathElem neighbour;
                neighbour.cell = &neighbourCell;
                if (DoesListContainCell(neighbourCell, openList))
                {
                    uint16_t moveG = CalculateG(currentCell);
                    if (currentCell.G + moveG < neighbour.G) //This path is better
                    {
                        neighbour.parentElem = &currentCell;
                        neighbour.G = moveG;
                    }
                }
                else
                {
                    neighbour.G = CalculateG(currentCell);
                    openList.push_back(neighbour);
                    neighbour.parentElem = &currentCell;
                }
            }

            assert(openList.size() != 0); //If openlist is empty we cannot find the path
            PathElem* lowestGElem = &openList[0];
            for (PathElem& e : openList)
            {
                if (e.G < lowestGElem->G && !DoesListContainCell(*e.cell, closedList))
                    lowestGElem = &e;
            }
            currentCell = *lowestGElem;
        }

        //Fill buffer
        pathBuffer = new Cell[pathLength];
        PathElem& currElem = cellTo;
        for (int i = pathLength - 1; i >= 0; i--)
        {
            pathBuffer[i] = *currElem.cell;
            currElem = *currElem.parentElem;
        }

        //Cleanup
        openList.clear();
        closedList.clear();
        return pathLength;
    }

    bool Pathfinder::Finished()
    {
        return false;
    }

    std::vector<Cell&> Pathfinder::GetNeighbours(Cell& searchCell)
    {
        std::vector<Cell&> returnList;
        returnList.reserve(4);

        //TODO: Replace hardcoded level width 40

        //Top
        Cell& top = levelPtrBase[((searchCell.y - 1) * 40) + searchCell.x];
        if(!DoesListContainCell(top, closedList))
            returnList.push_back(top);
        //Left
        Cell& left = levelPtrBase[(searchCell.y * 40) + searchCell.x - 1];
        if (!DoesListContainCell(left, closedList))
            returnList.push_back(left);
        //Bottom
        Cell& bottom = levelPtrBase[((searchCell.y + 1) * 40) + searchCell.x];
        if (!DoesListContainCell(bottom, closedList))
            returnList.push_back(bottom);
        //Right
        Cell& right = levelPtrBase[(searchCell.y * 40) + searchCell.x + 1];
        if (!DoesListContainCell(right, closedList))
            returnList.push_back(right);

        return returnList;
    }

    bool Pathfinder::DoesListContainCell(Cell& cell, std::vector<PathElem>& list)
    {
        for (PathElem& e : list)
        {
            if (e.cell == &cell)
            {
                return true;
            }
        }
        return false;
    }

    void Pathfinder::RemovePathElem(PathElem& pathElem, std::vector<PathElem>& list)
    {
        list.erase(std::remove_if(begin(list), end(list), [pathElem](PathElem& e)
            {
                return e.cell == pathElem.cell;
            }), list.end());
    }
    uint16_t Pathfinder::CalculateG(PathElem& currentPathElem)
    {
        return currentPathElem.G + G_HORVER;
    }
}
