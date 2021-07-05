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

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// SET ARGUMENT (PLUGINNUMBER) FOR TYPE-ID
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

MTypeId zrm_pointOnCurveNode::typeId(0x0007F1FD);

MTypeId zrm_stretchSoftIKNode::typeId(0x0007F2FD);

MTypeId zrm_aimUpVecNode::typeId(0x0007F3FD);

MTypeId zrm_locatorNode::typeId(0x0007F4FD);

MTypeId zrm_controllerNode::typeId(0x0007F5FD); // TO DO

MTypeId zrm_snapDeformerNode::typeId(0x0007F6FD);

MTypeId zrm_stressMapNode::typeId(0x0007F7FD);

MTypeId zrm_pushDeformerNode::typeId(0x0007F8FD);

MTypeId zrm_blendDeformerNode::typeId(0x0007F9FD); // TO DO

MTypeId zrm_attractDeformerNode::typeId(0x007F10FD); // TO DO

MTypeId zrm_chainOnPathNode::typeId(0x007F11FD);

MTypeId zrm_relaxDeformerNode::typeId(0x007F12FD); // TO DO HOMEWORK

MTypeId zrm_railSpineNode::typeId(0x007F13FD); // TO DO

MTypeId zrm_rigControllerNode::typeId(0x007F14FD); // TO DO

MTypeId zrm_rigCtlNode::typeId(0x007F15FD); // TO DO










