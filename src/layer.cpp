#include "layer.h"


const bgfx::EmbeddedShader shaders[3] = {
  BGFX_EMBEDDED_SHADER(vs_basic),
  BGFX_EMBEDDED_SHADER(fs_basic),
  BGFX_EMBEDDED_SHADER_END()
};


Layer::Layer(Window window, vector<ColorVertex> &vertices, vector<uint16_t> &indices) {

  colorVertexLayout.begin()
                     .add(bgfx::Attrib::Position, 2, bgfx::AttribType::Float)
                     .add(bgfx::Attrib::Color0, 4, bgfx::AttribType::Uint8, true)
                     .end();
  
  vertexBuffer = bgfx::createDynamicVertexBuffer(bgfx::makeRef(vertices.data(), sizeof(ColorVertex) * vertices.size()), colorVertexLayout);
  indexBuffer = bgfx::createDynamicIndexBuffer(bgfx::makeRef(indices.data(), sizeof(uint16_t) * indices.size()));

  bgfx::RendererType::Enum renderer_type = bgfx::getRendererType();
  program = bgfx::createProgram(
    bgfx::createEmbeddedShader(shaders, renderer_type, "vs_basic"),
    bgfx::createEmbeddedShader(shaders, renderer_type, "fs_basic"),
    true
  );
  
}

void Layer::UpdateVertexBuffer(vector<ColorVertex> &vertices) {
  bgfx::update(vertexBuffer, 0, bgfx::makeRef(vertices.data(), sizeof(ColorVertex) * vertices.size()));
}

void Layer::Draw(bgfx::ViewId view) {
  bgfx::setVertexBuffer(0, vertexBuffer);
  bgfx::setIndexBuffer(indexBuffer);
  bgfx::submit(view, program);
}

