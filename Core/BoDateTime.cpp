#include "BoDateTime.h"



BoDateTime::BoDateTime () {}


BoDateTime::~BoDateTime () {}

unsigned long BoDateTime::getMilli () {
	return ms_since_epoch;
}

void BoDateTime::setMilli (unsigned long milli) {
	ms_since_epoch = milli;
}
