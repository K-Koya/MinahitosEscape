#include "Updatable.h"

void Updatable::doUpdate(const float deltaTime) {

	if (!_isUpdating) return;
	update(deltaTime);
}
