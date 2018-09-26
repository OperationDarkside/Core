#include "BoListResponse.h"



BoListResponse::BoListResponse () {}


BoListResponse::~BoListResponse () {}

bool BoListResponse::getSuccess () {
	return success;
}

void BoListResponse::setSuccess (bool _success) {
	success = _success;
}
