#include "Renderable.h"

void Renderable::doRender() {

	if (!_isRendering) return;
	render();
}
