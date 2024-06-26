#include "layer.h"


const bgfx::EmbeddedShader shaders[3] = {
  BGFX_EMBEDDED_SHADER(vs_basic),
  BGFX_EMBEDDED_SHADER(fs_basic),
  BGFX_EMBEDDED_SHADER_END()
};


Layer::Layer(vector<ColorVertex> &vertices, vector<uint16_t> &indices) {
  this->vertices = vertices;

  
  colorVertexLayout.begin()
                     .add(bgfx::Attrib::Position, 2, bgfx::AttribType::Float)
                     .add(bgfx::Attrib::Color0, 4, bgfx::AttribType::Uint8, true)
                     .end();
  
  vertexBuffer = bgfx::createDynamicVertexBuffer(
      bgfx::makeRef(this->vertices.data(), sizeof(ColorVertex) * this->vertices.size()), 
      colorVertexLayout, 
      BGFX_BUFFER_ALLOW_RESIZE
    );
  indexBuffer = bgfx::createDynamicIndexBuffer(
      bgfx::makeRef(indices.data(), sizeof(uint16_t) * indices.size()), 
      BGFX_BUFFER_ALLOW_RESIZE
    );

  bgfx::RendererType::Enum renderer_type = bgfx::getRendererType();
  program = bgfx::createProgram(
    bgfx::createEmbeddedShader(shaders, renderer_type, "vs_basic"),
    bgfx::createEmbeddedShader(shaders, renderer_type, "fs_basic"),
    true
  );
}

Layer::Layer() {
  colorVertexLayout.begin()
                     .add(bgfx::Attrib::Position, 2, bgfx::AttribType::Float)
                     .add(bgfx::Attrib::Color0, 4, bgfx::AttribType::Uint8, true)
                     .end();
  
  vertexBuffer = bgfx::createDynamicVertexBuffer(1, colorVertexLayout, BGFX_BUFFER_ALLOW_RESIZE);
  indexBuffer = bgfx::createDynamicIndexBuffer(1, BGFX_BUFFER_ALLOW_RESIZE);

  bgfx::RendererType::Enum renderer_type = bgfx::getRendererType();
  program = bgfx::createProgram(
    bgfx::createEmbeddedShader(shaders, renderer_type, "vs_basic"),
    bgfx::createEmbeddedShader(shaders, renderer_type, "fs_basic"),
    true
  );

}

void Layer::UpdateGeometry(vector<ColorVertex> &vertices) {
  this->vertices.clear();
  this->vertices = vertices;
  bgfx::update(vertexBuffer, 0, bgfx::makeRef(this->vertices.data(), sizeof(ColorVertex) * this->vertices.size()));
}
void Layer::UpdateGeometry(vector<uint16_t> &indices) {
  this->indices.clear();
  this->indices = indices;
  bgfx::update(indexBuffer, 0, bgfx::makeRef(this->indices.data(), sizeof(uint16_t) * this->indices.size()));
}
void Layer::UpdateGeometry(vector<ColorVertex> &vertices, vector<uint16_t> &indices) {
  UpdateGeometry(vertices);
  UpdateGeometry(indices);
}

void Layer::Draw(bgfx::ViewId view) {
    bgfx::setVertexBuffer(0, vertexBuffer);
    bgfx::setIndexBuffer(indexBuffer);
    bgfx::submit(view, program);
}

