#include "level.h"

/*
 * Level file (.lf)
 * ------------
 * levelName
 * width height
 * attempts(default 0) best_time(default -1)
 * 
 * map (ex. 1 0 0
 *          1 1 1 
 *          0 1 0)
 * 
 */


Level::Level(string filename) {
  levelFS.open(filename);
  if (!levelFS.is_open()) {
    error = 1;
    return;
  }

  ParseLevelFile();
}

void Level::UpdateGeometry() {
  
}

void Level::ParseLevelFile() {
  getline(levelFS, name);
  levelFS >> width;
  levelFS >> height;
  levelFS >> attempts;
  levelFS >> bestTime;

  //Populates map vector
  for(int row = 0; row < height; row++) {
    vector<int> currentRow;
    for (int col = 0; col < width; col++) {
      int currentTile;
      levelFS >> currentTile;
      currentRow.push_back(currentTile);
      cout << currentTile << endl;
    }
    map.push_back(currentRow);
  }
  if (levelFS.fail()) {
    error = 1;
    map.clear();
    return;
  }
}

bool Level::fail() {
  if (error) {
    return true;
  }
  return false;
}
