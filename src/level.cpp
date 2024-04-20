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
  if (map.size() == 0) {
    return;
  }
  tileSize = 2.0 / max(width, height);


  if (width > height) {
    offset.y = ((width - height) * tileSize) / 2;
  }
  if (height > width) {
    offset.x = ((height - width) * tileSize) / 2;
  }

  cout << "Tile size: " << tileSize << endl;
  
  vector<ColorVertex> currentVertices {
    {-1.0f + offset.x, 1.0f - offset.y, 0x55555555},
    {-1.0f + tileSize + offset.x, 1.0f - offset.y, 0x55555555},
    {-1.0f + tileSize + offset.x, 1.0f - tileSize - offset.y, 0x55555555},
    {-1.0f + offset.x, 1.0f - tileSize - offset.y, 0x55555555}
  };

  vector<uint16_t> currentIndices {
    0, 1, 2,
    3, 2, 0
  };

  this->vertices.clear();
  this->indices.clear();

  for (int y = 0; y < map.size(); y++) {
    for (int x = 0; x < map.at(0).size(); x++) {
      //cout << map.at(y).at(x) << " ";
      if (map.at(y).at(x) == 1) {
        for (int i = 0; i < currentVertices.size(); i++) {
          this->vertices.push_back(currentVertices.at(i));
        }
        for (int i = 0; i < currentIndices.size(); i++) {
          this->indices.push_back(currentIndices.at(i));
          currentIndices.at(i) += currentVertices.size();
        }
      }
      for (int i = 0; i < currentVertices.size(); i++) {
        currentVertices.at(i).x_pos += tileSize;
      }
    }
    for (int i = 0; i < currentVertices.size(); i++) {
      currentVertices.at(i).y_pos -= tileSize;
      currentVertices.at(i).x_pos -= (tileSize * width);
    }
    //cout << endl;
  }
}

void Level::ParseLevelFile() {
  getline(levelFS, name);
  levelFS >> width;
  levelFS >> height;
  levelFS >> attempts;
  levelFS >> bestTime;

  //Populates map vector
  vector<int> currentRow;
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int currentTile;
      levelFS >> currentTile;
      currentRow.push_back(currentTile);
      if (levelFS.fail()) {
        cout << "Read Failiure: ( x: " << x << ", y: " << y << " )" << endl;
      }
    }
    this->map.push_back(currentRow);
    currentRow.clear();
  }
  cout << "Map size: " << map.at(0).size() << " x " << map.size() << endl;

  if (levelFS.fail()) {
    cout << "Level load error" << endl;
    error = 1;
    return;
  }
}

void Level::SetLayer(Layer *layer) {
  this->layer = layer;
  
  UpdateGeometry();

  if (this->vertices.size() != 0 && this->indices.size() != 0) {
    this->layer->UpdateGeometry(this->vertices, this->indices);
  } else {
    cout << "No data in vertices or indices vectors" << endl;
  }
}

bool Level::fail() {
  if (error) {
    return true;
  }
  return false;
}

