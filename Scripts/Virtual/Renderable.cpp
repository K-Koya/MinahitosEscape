#include "Renderable.h"

void Renderable::doRender() {

	if (!_isActive) return;
	render();
}