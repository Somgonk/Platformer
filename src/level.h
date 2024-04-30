#ifndef LEVEL_H_HEADER_GUARD
#define LEVEL_H_HEADER_GUARD

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "layer.h"
#include "coordinates.h"

using namespace std;

class Level {
  public:
    Level(string filename); // Constructor 
    ~Level(); // Destructor
    void UpdateGeometry(); // Updates layer's vertices and indices
    void SetLayer(Layer *layer); // Sets view layer to draw to
    bool fail();

    int width;
    int height;

    // Level Geometry
    vector<ColorVertex> vertices;
    vector<uint16_t> indices;
    float tileSize;

    // Gameplay
    CoordinatePair PosToIndex(CoordinatePair pos); // Converts screen coordinates to map indices
    int GetMapData(int x, int y); // Returns the value of map index (x,y)
    int GetMapData(CoordinatePair pos); // Returns the value of map index pos
    int PosToData(CoordinatePair pos); // Returns the value of map at corresponding index to pos
    void CompletedLevel(); // Changes to next level
    void NextAttempt(); // Adds to attempts
    
    CoordinatePair startingPoint;

  private:
    static const vector<uint32_t> colors; 
    void ParseLevelFile(); // Converts level file into variable values
    void WriteLevelFile(); // Converts variable values into level file

    int error;
    ifstream levelFS;
    string filename;
    vector<string> files;
    int currentLevel;

    Layer *layer;

    // Level Data
    string name;

    CoordinatePair offset = {0, 0};

    int attempts;

    vector<vector<int>> map;
    
};


#endif
