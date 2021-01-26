from makeUtils import binaryUtils

__InnoSetupCompilerAbsolutePath = r"C:/Program Files (x86)/Inno Setup 6/ISCC.exe"

'''
Calls the innosetup cli tool to compile the inno setup script under the given path.
'''
def compileInnoSetUpScript(innoSetupScriptPath):
    (errorCode, _) = binaryUtils.callExeWithArguments(__InnoSetupCompilerAbsolutePath,innoSetupScriptPath, False)
    if(errorCode != 0):
        raise RuntimeError(f"Innosetup compiler produced error code {errorCode}.")