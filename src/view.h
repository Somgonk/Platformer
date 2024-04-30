#ifndef VIEW_H_HEADER_GUARD
#define VIEW_H_HEADER_GUARD

#include <iostream>
#include <bgfx/bgfx.h>
#include <vector>

#include "layer.h"

using namespace std;

class View {
  public: 
    View(); // Constructor
    void AddLayer(Layer layer); // Appends a layer to layers
    void Submit(); // Submits layers to rendering
        
    static bgfx::ViewId nextViewId; // For varying view ids 
  private:
    bgfx::ViewId view;
    vector<Layer> layers;
};

#endif
