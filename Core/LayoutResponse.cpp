#include "LayoutResponse.h"



LayoutResponse::LayoutResponse () {}


LayoutResponse::~LayoutResponse () {}

bool LayoutResponse::isSuccess () {
	return success;
}

void LayoutResponse::setSuccess (bool _success) {
	success = _success;
}

Layout * LayoutResponse::getLayout () {
	return layout;
}

void LayoutResponse::setLayout (Layout * _layout) {
	layout = _layout;
}
