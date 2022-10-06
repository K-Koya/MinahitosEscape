#include "Updatable.h"

void Updatable::doUpdate(float deltaTime) {

	if (!_isActive) return;
	update(deltaTime);
}
