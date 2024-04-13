#ifndef LEVEL_H_HEADER_GUARD
#define LEVEL_H_HEADER_GUARD

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "layer.h"

using namespace std;

class Level {
  public:
    Level(string filename);
    void UpdateGeometry();
    bool fail();

    // Level Geometry
    vector<ColorVertex> vertices;
    vector<uint16_t> indices;

  private:
    void ParseLevelFile();

    int error;
    ifstream levelFS;

    // Level Data
    string name;
    int width;
    int height;

    int attempts;
    double bestTime;

    vector<vector<int>> map;
    
};


#endif
