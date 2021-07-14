//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// PLUGIN GENERATES A PLUGIN FOR AUTODESK MAYA
// 
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// VENDOR:			Martin Zetter
// DATE:			10.05.2021
// VERSION:			0.0.1 BETA
// MAYA:			2020.4 (compiled for Autodesk Maya 2020.4)
// OS:				WIN 10 x64
// BRIEF:			Node for creating a Custom Point on Curve Node "zrm_locatorNode"
// NODE:			zrm_locatorNode
// 
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// 
// DETAILS:			CUSTOM PLUGIN FOR AUTODESK MAYA
// 
// This node is setting up a CUSTOM PLUGIN FOR AUTODESK MAYA
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
// INCLUDES
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include "zrm_autodeskMayaPlugin.h"
#include "zrm_autodeskMayaPluginOverride.h"

#include <maya/MGlobal.h>
#include <maya/MFnPlugin.h>
#include <maya/MDrawRegistry.h>

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// MACRO DEFINITION FOR FUNCTIONS BEING EXPORTED TO DLL
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#define MLL_EXPORT extern __declspec(dllexport)

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

// MEL SCRIPT FILENAME:
const char* melFileName = "zrm_locatorNode.mel";

// MEL SCRIPT FUNCTION (run when load PLUGIN from Maya:
const char* loadFunc = "zrm_autodeskMayaPluginLoad";

// MEL SCRIPT FUNCTION (run when unload PLUGIN from Maya:
const char* unloadFunc = "zrm_autodeskMayaPluginUnload";


const MString pluginRegistrantId("zrm_autodeskMayaPlugin");


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// FUNCTION TO INITIALIZE PLUGIN (Maya loads plugin: gets a new node)
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

MLL_EXPORT MStatus initializePlugin(MObject pluginObj)
{

	// TRACK STATUS OF MAYA FUNCTION CALLS
	MStatus status;

	// INSTANTIATE MFN-PLUGIN FUNCTION TO REGISTER PLUGIN
	MFnPlugin pluginFn(pluginObj, vendorName, versionNumber, apiVersion, &status);

	// PRINT PLUGIN INFORMATION TO MAYA OUTPUT WINDOW
	std::cout << "[ZRM]-Plugin: " << pluginName << ", Version: " << versionNumber /*<< ", Vendor: " << vendorName << ", Developed: " << devYear << ", Contact:" << contact*/ << std::endl << endl;

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
	// PRINT PLUGIN INFORMATION TO MAYA OUTPUT WINDOW
	std::cout << "Sucessfully Registered Plugin: " << pluginName << std::endl;


	//REGISTER BOX HANDLE DRAW OVERRIDE
	status = MHWRender::MDrawRegistry::registerDrawOverrideCreator(
		zrm_autodeskMayaPlugin::kDrawDbClassification,
		zrm_autodeskMayaPlugin::kPluginRegistrantId,
		zrm_autodeskMayaPluginOverride::creator //Changed to DeawOverride instead of override only
	);

	if (!status)
	{
		MGlobal::displayError(MString("Failed To Register Node Draw Override: " + status.errorString()));
		return(status);
	}
	else
	{
		// PRINT PLUGIN INFORMATION TO MAYA OUTPUT WINDOW
		std::cout << "Sucessfully Registered Locator Node Draw Override: " << pluginName << std::endl;
		return(status);
	}
	CHECK_MSTATUS_AND_RETURN_IT(status);
	return status;
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
		std::cout << "Failed To Deregister Locator Node Draw Override: " << pluginName << std::endl;
	}
	else
	{
		// PRINT PLUGIN INFORMATION TO MAYA OUTPUT WINDOW
		std::cout << "Sucessfully Deregistered Locator Node Draw Override: " << pluginName << std::endl;
	}
	return(status);

	// DEREGISTER THE NODE (DO NOT HARDCODE TYPE-ID)
	status = pluginFn.deregisterNode(zrm_autodeskMayaPlugin::typeId);

	if (!status)
	{
		// PRINT PLUGIN INFO ERROR TO MAYA COMMAND HISTORY
		MGlobal::displayError(MString("Failed To Deregister Node: " + status.errorString()));
		return(status);

		// PRINT PLUGIN INFORMATION TO MAYA OUTPUT WINDOW
		std::cout << "Unable To Deregister Plugin: " << pluginName << std::endl;

	}
	else
	{
		// PRINT PLUGIN INFORMATION TO MAYA OUTPUT WINDOW
		std::cout << "Sucessfully Deregistered Plugin: " << pluginName << std::endl << endl;

	}
	CHECK_MSTATUS_AND_RETURN_IT(status);
	return(status);
}













