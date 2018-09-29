#pragma once
#ifndef MASTERLAYER_H
#define MASTERLAYER_H

// Data
#include "MasterManager.h"

// Requests
#include "AuthRequest.h"

#include "AddLayoutRequest.h"
#include "LayoutRequest.h"
#include "SetLayoutRequest.h"

#include "AddBoRequest.h"
#include "BoRequest.h"
#include "SetBoRequest.h"

#include "BoListRequest.h"

#include "AddBoMetaRequest.h"
#include "BoMetaRequest.h"
#include "SetBoMetaRequest.h"

// Responses
#include "AuthResponse.h"

#include "AddLayoutResponse.h"
#include "LayoutResponse.h"
#include "SetLayoutResponse.h"

#include "AddBoResponse.h"
#include "BoResponse.h"
#include "SetBoResponse.h"

#include "BoListResponse.h"

#include "AddBoMetaResponse.h"
#include "BoMetaResponse.h"
#include "SetBoMetaResponse.h"

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

	// Auth
	AuthResponse getAuthentication (AuthRequest req); // login

	// Layout
	AddLayoutResponse addLayout (AddLayoutRequest req);
	LayoutResponse getLayout (LayoutRequest req);
	SetLayoutResponse setLayout (SetLayoutRequest req);

	// Bo
	AddBoResponse addBo (AddBoRequest req);
	BoResponse getBo (BoRequest req);
	SetBoResponse setBo (SetBoRequest req);

	// BoList
	BoListResponse getBoList (BoListRequest req);

	// BoMeta
	AddBoMetaResponse addBoMeta (AddBoMetaRequest req);
	BoMetaResponse getBoMeta (BoMetaRequest req);
	SetBoMetaResponse setBoMeta (SetBoMetaRequest req);

private:
	MasterManager masterManager;
	AuthLayer authLayer;
	GroupLayer groupLayer;
	PermissionLayer permissionLayer;
	DataLayer dataLayer;
};

#endif // !MASTERLAYER_H