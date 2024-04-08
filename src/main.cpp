#include <iostream>
#include <bx/bx.h>
#include <bgfx/bgfx.h>
#include <bgfx/embedded_shader.h>
#include <bgfx/platform.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <glm/glm/vec2.hpp>

#include "window.h"
#include "generated/shaders/all.h"

using namespace std;


static const bgfx::EmbeddedShader kEmbeddedShaders[] =
        {
                BGFX_EMBEDDED_SHADER(vs_basic),
                BGFX_EMBEDDED_SHADER(fs_basic),
                BGFX_EMBEDDED_SHADER_END()
        };

struct NormalColorVertex
{
  glm::vec2 position;
  uint32_t color;
};




int main() {
  Window window;
 

  NormalColorVertex kTriangleVertices[] =
            {
                    {{-0.5f, -0.5f}, 0xffffffff},
                    {{0.5f, -0.5f}, 0xffffffff},
                    {{0.0f, 0.5f}, 0xffffffff},
            };

    const uint16_t kTriangleIndices[] =
            {
                    0, 1, 2, 
            };

    bgfx::VertexLayout color_vertex_layout;
    color_vertex_layout.begin()
                       .add(bgfx::Attrib::Position, 2, bgfx::AttribType::Float)
                       .add(bgfx::Attrib::Color0, 4, bgfx::AttribType::Uint8, true)
                       .end();

    bgfx::VertexBufferHandle vertex_buffer = bgfx::createVertexBuffer(bgfx::makeRef(kTriangleVertices, sizeof(kTriangleVertices)), color_vertex_layout);
    bgfx::IndexBufferHandle index_buffer = bgfx::createIndexBuffer(bgfx::makeRef(kTriangleIndices, sizeof(kTriangleIndices)));

    bgfx::RendererType::Enum renderer_type = bgfx::getRendererType();
    bgfx::ProgramHandle program = bgfx::createProgram(
            bgfx::createEmbeddedShader(kEmbeddedShaders, renderer_type, "vs_basic"),
            bgfx::createEmbeddedShader(kEmbeddedShaders, renderer_type, "fs_basic"),
            true
    );


  while (!glfwWindowShouldClose(window.window)) {
		glfwPollEvents();

    bgfx::setViewRect(window.view, 0, 0, bgfx::BackbufferRatio::Equal);
    bgfx::setViewClear(window.view, BGFX_CLEAR_COLOR, 0x0000ff00);

    bgfx::touch(window.view);
    
    bgfx::setState(
                BGFX_STATE_WRITE_R
                        | BGFX_STATE_WRITE_G
                        | BGFX_STATE_WRITE_B
                        | BGFX_STATE_WRITE_A
        );

        bgfx::setVertexBuffer(0, vertex_buffer);
        bgfx::setIndexBuffer(index_buffer);
        bgfx::submit(window.view, program);

    bgfx::frame();

  }

  bgfx::shutdown();
	glfwTerminate();

  return 0;
}
