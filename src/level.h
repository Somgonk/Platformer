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
  private:
    void ParseLevelFile();

    int error;
    ifstream levelFS;

    Layer *layer;

    // Level Data
    string name;




    CoordinatePair offset = {0, 0};

    int attempts;
    double bestTime;

    vector<vector<int>> map;
    
};


#endif
