#include "LayoutRequest.h"



LayoutRequest::LayoutRequest () {}


LayoutRequest::~LayoutRequest () {}

int LayoutRequest::getLayoutID () {
	return layoutID;
}

void LayoutRequest::setLayoutID (int id) {
	layoutID = id;
}
