#pragma once
#ifndef MASTERLAYER_H
#define MASTERLAYER_H

// Data
#include "MasterManager.h"

// Requests
#include "AuthRequest.h"
#include "LayoutRequest.h"
#include "BoRequest.h"
#include "BoListRequest.h"

// Responses
#include "AuthResponse.h"
#include "LayoutResponse.h"
#include "BoResponse.h"
#include "BoListResponse.h"

// Layers
#include "AuthLayer.h"
#include "GroupLayer.h"
#include "PermissionLayer.h"
#include "DataLayer.h"

#include <vector>

class MasterLayer {
public:
	MasterLayer ();
	~MasterLayer ();

	AuthResponse getAuthentication (AuthRequest req);

	LayoutResponse getLayout (LayoutRequest req);

	BoResponse getBo (BoRequest req);
	BoListResponse getBoList (BoListRequest req);

private:
	MasterManager masterManager;
	AuthLayer authLayer;
	GroupLayer groupLayer;
	PermissionLayer permissionLayer;
	DataLayer dataLayer;
};

#endif // !MASTERLAYER_H