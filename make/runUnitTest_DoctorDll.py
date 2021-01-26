from makeUtils import binaryUtils
from makeUtils import fileSystemUtils
from makeUtils import returnCodes
from makeUtils import logUtils
import os.path

#TODO: probably locate this with something like vswhere exe?
__vsTestExePath = r"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\TestWindow\vstest.console.exe"
__relativePathToTestDll = r"artifacts\x64\Release\UnitTests.dll"
try:
    baseWorkDirectoryPath = fileSystemUtils.getWorkspaceBaseFolder()
    fullTestDllPath = os.path.join(baseWorkDirectoryPath,__relativePathToTestDll)
    (returnCode,_) = binaryUtils.callExeWithArguments(__vsTestExePath,fullTestDllPath,False)
    exit(returnCode)
except (FileNotFoundError,RuntimeError) as exce:
    logUtils.log("Error in " + os.path.basename(__file__) + ": " + str(exce))
    exit(returnCodes.ExitFailedCode)