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
    Layer(vector<ColorVertex> &vertices, vector<uint16_t> &indices); // Layer constructor with existing geometry
    Layer(); // Empty layer constructor
    void UpdateGeometry(vector<ColorVertex> &vertices); // Updates the layer's vertex buffer
    void UpdateGeometry(vector<uint16_t> &indices); // Updates the layer's index buffer
    void UpdateGeometry(vector<ColorVertex> &vertices, vector<uint16_t> &indices); // Updates all of the layer's buffers
    void Draw(bgfx::ViewId view); // Submits buffers for rendering
    
  private:
    // Buffers
    bgfx::DynamicVertexBufferHandle vertexBuffer;
    bgfx::DynamicIndexBufferHandle indexBuffer;

    // Others
    bgfx::ProgramHandle program;
    bgfx::VertexLayout colorVertexLayout;

    vector<ColorVertex> vertices;
    vector<uint16_t> indices;

};

#endif
