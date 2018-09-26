#include "BoMetaResponse.h"



BoMetaResponse::BoMetaResponse () {}


BoMetaResponse::~BoMetaResponse () {}

bool BoMetaResponse::getSuccess () {
	return success;
}

void BoMetaResponse::setSuccess (bool _success) {
	success = _success;
}
