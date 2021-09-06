//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// PLUGIN GENERATES "CUSTOM PLUGIN NODE NAME TEMPLATE" FOR AUTODESK MAYA DEVELOPED IN C++
// 
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// VENDOR:			Martin Zetter
// DATE:			00.00.2021
// VERSION:			0.0.1 BETA
// MAYA:			2020.4 (compiled for Autodesk Maya 2020.4)
// OS:				WIN 10 x64
// BRIEF:			Node for creating a Custom Point on Curve Node "zrm_locatorNode"
// NODE:			zrm_nodeName
// 
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// 
// DETAILS:			"CUSTOM RIG CONTROLLER NODE NAME"
// 
// - Description
// - Description
// - Description
// - Description
// - Description
// - Description
// - Description
// - Description
// - Description
// - Description
// - Description
// - Description
//
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  
// LOAD AND CREATE NODE WITH MEL:
// 
// MEL PATH:		C:\Users\User\Documents\maya\2020\scripts
// 
// LOAD PLUG:		loadPlugin zrm_autodeskMayaPlugin;
// UNLOAD PLUG:		unloadPlugin zrm_autodeskMayaPlugin;
// 
// CREATE NODE:		createNode zrm_autodeskMayaPlugin;
// 
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// 
// LOAD AND CREATE NODE WITH PYTHON:
// (MayaCommands imported as cmds)
//
// PYTHON PATH:		C:\Users\User\Documents\maya\2020\scripts
//
// LOAD PLUG:		cmds.loadPlugin zrm_autodeskMayaPlugin
// UNLOAD PLUG:		cmds.unloadPlugin zrm_autodeskMayaPlugin
// 
// CREATE NODE:		cmds.createNode zrm_autodeskMayaPlugin
//
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ADD LINKER INPUT ADDITIONAL DEPENDENCIES
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#pragma comment(lib, "Foundation.lib")
#pragma comment(lib, "OpenMaya.lib")
#pragma comment(lib, "OpenMayaAnim.lib")
#pragma comment(lib, "OpenMayaUI.lib")
#pragma comment(lib, "OpenMayaRender.lib")
#pragma comment(lib, "OpenGl32.lib")

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// INCLUDES
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include "zrm_autodeskMayaPlugin.h"

#include <maya/MGlobal.h>
#include <maya/MFnPlugin.h>
#include <maya/MDrawRegistry.h>

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// MACRO DEFINITION FOR FUNCTIONS BEING EXPORTED TO DLL
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#define MLL_EXPORT extern __declspec(dllexport)

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// NAMESPACE DEFINITION
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

using namespace std;

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// VARIABLE DEFINITION FOR PLUGIN INFO
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// VENDORNAME:
const char* vendorName = "Martin Zetter";

// PLUGINVERSION:
const char* versionNumber = "0.0.1";

// MAYA API VERSION:
const char* apiVersion = "Any";

// PLUGINNAME:
const char* pluginName = "zrm_autodeskMayaPlugin";

// YEAR OF DEVELOPMENT:
const char* devYear = "2021";

// CONTACT INFORMATION:
const char* contact = "martin.zetter@zrm.at";

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// FUNCTION TO INITIALIZE PLUGIN (Maya loads plugin: gets a new node)
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

MLL_EXPORT MStatus initializePlugin(MObject pluginObj)
{
	// TRACK STATUS OF MAYA FUNCTION CALLS
	MStatus status;

	// INSTANTIATE MFN-PLUGIN FUNCTION TO REGISTER PLUGIN
	MFnPlugin pluginFn(pluginObj, vendorName, versionNumber, apiVersion, &status);

	// LOGGING: PRINT PLUGIN INFORMATION TO MAYA OUTPUT WINDOW
	cout << "[ZRM]-Plugin: " << pluginName << ", Version: " << versionNumber /*<< ", Vendor: " << vendorName << ", Developed: " << devYear << ", Contact:" << contact*/ << endl << endl;

	// REGISTER THE NODE (DO NOT HARDCODE TYPE-ID)
	status = pluginFn.registerNode(pluginName,
		zrm_autodeskMayaPlugin::typeId,
		zrm_autodeskMayaPlugin::creator,
		zrm_autodeskMayaPlugin::initialize,
		MPxNode::kLocatorNode,
		&zrm_autodeskMayaPlugin::kDrawDbClassification
	);

	if (!status)
	{
		// PRINT PLUGIN INFO ERROR TO MAYA COMMAND HISTORY
		MGlobal::displayError("Failed To Initialize Plugin : " + status.errorString());
		return(status);


		// PRINT PLUGIN INFO ERROR TO MAYA COMMAND HISTORY
		MGlobal::displayError(MString("Failed To Register Node: " + status.errorString()));
		return(status);

	}
	// LOGGING: PRINT PLUGIN INFORMATION TO MAYA OUTPUT WINDOW
	cout << "Sucessfully Registered Plugin: " << pluginName << endl;


	//REGISTER BOX HANDLE DRAW OVERRIDE
	status = MHWRender::MDrawRegistry::registerDrawOverrideCreator(
		zrm_autodeskMayaPlugin::kDrawDbClassification,
		zrm_autodeskMayaPlugin::kPluginRegistrantId,
		zrm_autodeskMayaPluginDrawOverride::creator
	);

	if (!status)
	{
		MGlobal::displayError(MString("Failed To Register Node Draw Override: " + status.errorString()));
		return(status);
	}
	else
	{
		// LOGGING: PRINT PLUGIN INFORMATION TO MAYA OUTPUT WINDOW
		cout << "Sucessfully Registered Locator Node Draw Override: " << pluginName << endl;
		return(status);
	}
	CHECK_MSTATUS_AND_RETURN_IT(status);
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
// FUNCTION TO UNINITIALIZE PLUGIN (Maya unloads plugin: node gets unloaded)
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

MLL_EXPORT MStatus uninitializePlugin(MObject pluginObj)
{
	// TRACK STATUS OF MAYA FUNCTION CALLS
	MStatus status;

	// DEREGISTER BOX HANDLE DRAW OVERRIDE
	status = MHWRender::MDrawRegistry::deregisterDrawOverrideCreator(
		zrm_autodeskMayaPlugin::kDrawDbClassification,
		zrm_autodeskMayaPlugin::kPluginRegistrantId
	);

	// INSTANTIATE MFN-PLUGIN FUNCTION TO DEREGISTER PLUGIN
	MFnPlugin pluginFn(pluginObj);

	if (!status)
	{
		MGlobal::displayError(MString("Failed To Deregister Node Draw Override: " + status.errorString()));
		return(status);

		// PRINT PLUGIN INFORMATION TO MAYA OUTPUT WINDOW
		cout << "Failed To Deregister Locator Node Draw Override: " << pluginName << endl;
	}
	else
	{
		// PRINT PLUGIN INFORMATION TO MAYA OUTPUT WINDOW
		cout << "Sucessfully Deregistered Locator Node Draw Override: " << pluginName << endl;
	}
	return(status);

	// DEREGISTER THE NODE (DO NOT HARDCODE TYPE-ID)
	status = pluginFn.deregisterNode(zrm_autodeskMayaPlugin::typeId);

	if (!status)
	{
		// PRINT PLUGIN INFO ERROR TO MAYA COMMAND HISTORY
		MGlobal::displayError(MString("Failed To Deregister Node: " + status.errorString()));
		return(status);

		// LOGGING: PRINT PLUGIN INFORMATION TO MAYA OUTPUT WINDOW
		cout << "Unable To Deregister Plugin: " << pluginName << std::endl;

	}
	else
	{
		// LOGGING: PRINT PLUGIN INFORMATION TO MAYA OUTPUT WINDOW
		cout << "Sucessfully Deregistered Plugin: " << pluginName << endl << endl;

	}
	CHECK_MSTATUS_AND_RETURN_IT(status);
}
