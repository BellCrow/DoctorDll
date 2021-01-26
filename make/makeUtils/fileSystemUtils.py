import sys
import os
'''
    Returns the base of the whole repository structure. From there you can make easy path concatenation.
'''
def getWorkspaceBaseFolder():
    
    pathOfThisScriptFile = os.path.abspath(__file__)
    workSpaceFolderPath = os.path.abspath(os.path.join(pathOfThisScriptFile, "../../.."))
    return workSpaceFolderPath