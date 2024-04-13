#ifndef LAYER_H_HEADER_GUARD
#define LAYER_H_HEADER_GUARD

#include <bgfx/embedded_shader.h>
#include <bgfx/bgfx.h>
#include <vector>

#include "window.h"
#include "generated/shaders/all.h"

using namespace std;

struct ColorVertex {
  float x_pos;
  float y_pos;
  uint32_t color;
};


class Layer {
  public:
    //Layer(Window window, vector<ColorVertex> &vertices, vector<uint16_t> &indices);
    Layer(vector<ColorVertex> &vertices, vector<uint16_t> &indices, double xScale = 0, double yScale = 0);
    void SetScaleFactor(double xScale, double yScale);
    void UpdateGeometry(vector<ColorVertex> &vertices);
    void UpdateGeometry(vector<uint16_t> &indices);
    void UpdateGeometry(vector<ColorVertex> &vertices, vector<uint16_t> &indices);
    void Draw(bgfx::ViewId view);
    

    vector<ColorVertex> vertices;
    vector<uint16_t> indices;

    double xScale = 1;
    double yScale = 1;

  private:
    // Scales vertices stored in class
    void ScaleVertices(double xScale, double yScale);

    // Buffers
    bgfx::DynamicVertexBufferHandle vertexBuffer;
    bgfx::DynamicIndexBufferHandle indexBuffer;

    // Others
    bgfx::ProgramHandle program;
    bgfx::VertexLayout colorVertexLayout;
};

#endif
