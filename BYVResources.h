

class ResourceManager
{
public:
    ResourceManager();

    void LoadResources(int max);
    int GetRandomResource();
private:
    int resources[5];
};

class GridManager
{
public:
    GridManager(int width, int height, int cellSize);
    
    void InitializeGrid(ResourceManager &resourceManager);
    void DisplayGrid();
    void ClearGrid();
    void SetRandomCell();
private:
    int width;
    int height;
    int area;
    int cellSize;
    int* grid;
    ResourceManager* resourceManager;
};