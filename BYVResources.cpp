
#include "FEHLCD.h"
#include "BYVResources.h"
#include "stdlib.h"

int const GRASS = 0;
int const WOOD = 1;
int const ORE = 2;
int const FOOD = 3;
int const WATER = 4;

float const GRASS_PERCENT = .60f;
float const WOOD_PERCENT = .20f;
float const ORE_PERCENT = .10f;
float const FOOD_PERCENT = .10f;
float const WATER_PERCENT = .20f;

ResourceManager::ResourceManager()
{
    for (int i = 0; i < 5; i++)
    {
        resources[i] = 0;
    }
}

void ResourceManager::LoadResources(int max)
{
    resources[GRASS] = max * GRASS_PERCENT;
    resources[WOOD] = max * WOOD_PERCENT;
    resources[ORE] = max * ORE_PERCENT;
    resources[FOOD] = max * FOOD_PERCENT;
    resources[WATER] = max * WATER_PERCENT;
}

int ResourceManager::GetRandomResource()
{
    int resource = rand() % 5;
    if (resources[resource] > 0)
    {
        resources[resource]--;
        return resource;
    }
    else
    {
        return GetRandomResource();
    }
}

GridManager::GridManager(int width, int height, int cellSize)
{
    this->width = width;
    this->height = height;
    this->cellSize = cellSize;
    this->area = width * height;
    this->grid = new int[area];
}

void GridManager::InitializeGrid(ResourceManager &resourceManager)
{
    this->resourceManager = &resourceManager;
    this->resourceManager->LoadResources(area);
    for (int i = 0; i < area; i++)
    {
        int resource = this->resourceManager->GetRandomResource();
        grid[i] = resource;
    }
}

void GridManager::ClearGrid()
{
    this->grid[area] = {0};
}

void GridManager::SetRandomCell()
{
    int randomIndex = rand() % area;
    int resource = resourceManager->GetRandomResource();
    grid[randomIndex] = resource;
}

void GridManager::DisplayGrid()
{
    int offSet = 5;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++)
        {
            LCD.SetFontColor(WHITE);
            LCD.DrawRectangle((i * cellSize) + offSet - 1, (j * cellSize) + offSet - 1, cellSize, cellSize);
            int resource = grid[j * width + i];
            if (resource == WOOD)
                LCD.SetFontColor(BROWN);
            else if (resource == ORE)
                LCD.SetFontColor(GRAY);
            else if (resource == FOOD)
                LCD.SetFontColor(YELLOW);
            else if (resource == WATER)
                LCD.SetFontColor(BLUE);
            else
                LCD.SetFontColor(GREEN);
            LCD.FillRectangle((i * cellSize) + offSet, (j * cellSize) + offSet, cellSize - 3, cellSize - 3);
        }    
    }

    LCD.Update();
}