#include "BoResponse.h"



BoResponse::BoResponse () {}


BoResponse::~BoResponse () {}

bool BoResponse::getSuccess () {
	return success;
}

void BoResponse::setSuccess (bool _success) {
	success = _success;
}
