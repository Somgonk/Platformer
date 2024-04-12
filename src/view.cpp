#include "view.h"

bgfx::ViewId View::nextViewId = 0;

View::View() {
  view = nextViewId;
  nextViewId ++;
}

void View::AddLayer(Layer layer) {
  layers.push_back(layer);
}

void View::Submit() {
  bgfx::setViewRect(view, 0, 0, bgfx::BackbufferRatio::Equal);
  bgfx::setViewClear(view, BGFX_CLEAR_COLOR);

  bgfx::touch(view);

  for (int i = 0; i < layers.size(); i++) {
    bgfx::setState(
        BGFX_STATE_WRITE_R
        | BGFX_STATE_WRITE_G
        | BGFX_STATE_WRITE_B
        | BGFX_STATE_WRITE_A
    );

    layers.at(i).Draw(view);
  }

}
