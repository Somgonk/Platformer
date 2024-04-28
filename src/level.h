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
    Level(string filename);
    ~Level();
    void UpdateGeometry();
    void SetLayer(Layer *layer);
    bool fail();

    int width;
    int height;

    // Level Geometry
    vector<ColorVertex> vertices;
    vector<uint16_t> indices;
    float tileSize;

    // Gameplay
    CoordinatePair PosToIndex(CoordinatePair pos);
    int GetMapData(int x, int y);
    int GetMapData(CoordinatePair pos);
    int PosToData(CoordinatePair pos);
    void CompletedLevel();
    void NextAttempt();
    
    CoordinatePair startingPoint;

  private:
    static const vector<uint32_t> colors; 
    void ParseLevelFile();
    void WriteLevelFile();

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
