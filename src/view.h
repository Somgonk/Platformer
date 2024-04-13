#ifndef VIEW_H_HEADER_GUARD
#define VIEW_H_HEADER_GUARD

#include <iostream>
#include <bgfx/bgfx.h>
#include <vector>

#include "layer.h"

using namespace std;

class View {
  public: 
    View();
    void AddLayer(Layer layer);
    void Submit();
    void UpdateScaleFactor(double xScale, double yScale);
    
    static bgfx::ViewId nextViewId;
  private:
    bgfx::ViewId view;
    vector<Layer> layers;
};

#endif
