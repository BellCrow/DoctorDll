from makeUtils import fileSystemUtils
from makeUtils import msBuildUtils
from makeUtils import returnCodes
from makeUtils import logUtils
import os
import shutil


__relativePathToPrepSolutionFromProjectBase = r"src\DoctorDll.sln"
__relativePathToBinariesFolderToClean = r"artifacts\x64"
try:
    
    baseWorkDirectoryPath = fileSystemUtils.getWorkspaceBaseFolder()

    doctorDllPathBinariesFolder = os.path.join(baseWorkDirectoryPath,__relativePathToBinariesFolderToClean)
    if os.path.exists(doctorDllPathBinariesFolder):
        shutil.rmtree(doctorDllPathBinariesFolder)

    doctorDllPathSolutionPath = os.path.join(baseWorkDirectoryPath,__relativePathToPrepSolutionFromProjectBase)
    msBuildUtils.buildWithDefaultReleaseParameters(doctorDllPathSolutionPath)
    exit(returnCodes.ExitSuccessCode)
except (FileNotFoundError,RuntimeError) as exce:
    logUtils.log("Error in " + os.path.basename(__file__) + ": " + str(exce))
    exit(returnCodes.ExitFailedCode)