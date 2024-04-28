#include "level.h"

/*
 * Level file (.lf)
 * ------------
 * levelName
 * width height
 * attempts 
 * 
 * map (ex. 1 0 0
 *          1 1 1 
 *          0 1 0)
 */


const vector<uint32_t> Level::colors {
  0xdddddddd,
  0x55555555,
  0x0000dd00,
  0xffff5500,
  0x000077ff
};


Level::Level(string filename) {
  this->filename = filename;
  levelFS.open(filename);
  if (!levelFS.is_open()) {
    error = 1;
    return;
  }

  ParseLevelFile();
  NextAttempt();
}

Level::~Level() {
  levelFS.close();
  vertices.clear();
  indices.clear();
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

  //cout << "Tile size: " << tileSize << endl;
  
  vector<ColorVertex> currentVertices {
    {-1.0f + offset.x, 1.0f - offset.y, colors.at(1)},
    {-1.0f + tileSize + offset.x, 1.0f - offset.y, colors.at(1)},
    {-1.0f + tileSize + offset.x, 1.0f - tileSize - offset.y, colors.at(1)},
    {-1.0f + offset.x, 1.0f - tileSize - offset.y, colors.at(1)}
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
      if (map.at(y).at(x) != 0) {
        if (map.at(y).at(x) == 2) {
          startingPoint = {(x - width / 2.0f) * tileSize + tileSize / 2, -((y - height / 2.0f) * tileSize + tileSize / 2)};
        }
        for (int i = 0; i < currentVertices.size(); i++) {
          currentVertices.at(i).color = colors.at(map.at(y).at(x));
        }
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

  cout << name << endl;

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
  //cout << "Map size: " << map.at(0).size() << " x " << map.size() << endl;

  if (levelFS.fail()) {
    cout << "Level load error" << endl;
    error = 1;
    return;
  }
  levelFS.close();
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

CoordinatePair Level::PosToIndex(CoordinatePair pos) {
  CoordinatePair index;

  index.x = (int)round(((pos.x + 1 + tileSize / 2) / 2) * (width - 1) * (1 + 1.0 / ( width - 1)) - 1);
  index.y = height - (int)round(((pos.y + 1 + tileSize / 2) / 2) * (height - 1) * (1 + 1.0 / (height - 1)));


  if (index.x == -0 || index.x < 0) index.x = 0;
  if (index.y == -0 || index.x < 0) index.y = 0;
  if (index.x > width - 1) index.x = width - 1;
  if (index.y > height - 1) index.y = height - 1;
  /* 
  cout << "Pos:  ( x: " << pos.x << ", y: " << pos.y << " )" << endl;
  cout << "Index:( x: " << index.x << ", y: " << index.y << " )" << endl;
  */
  return index;
  
}
int Level::GetMapData(int x, int y) {
  return map[y][x];
}
int Level::GetMapData(CoordinatePair pos) {
  return map[pos.y][pos.x];
}

int Level::PosToData(CoordinatePair pos) {
  return GetMapData(PosToIndex(pos));
}

void Level::CompletedLevel() {
  WriteLevelFile();
}

void Level::NextAttempt() {
  attempts++;
  cout << "Attempt " << attempts << endl;
}

void Level::WriteLevelFile() {
  ofstream outFS;
  outFS.open(filename);

  if (!outFS.is_open()) {
    cout << "file write error" << endl;
  }

  //Clears file
  outFS << "";
 
  outFS << name << "\n";
  outFS << width << " " << height << "\n";
  outFS << attempts << "\n\n";

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      outFS << map.at(y).at(x) << " ";
    }
    outFS << "\n";
  }
  outFS.close();
}

