from makeUtils import binaryUtils
from makeUtils import returnCodes

__NunitConsoleRunnerBinaryPath = r'C:\libs\bin\NUnit.org\nunit-console\nunit3-console.exe'
__NunitTestRunnerDefaultArguments = r'--config=Release --dispose-runners --skipnontestassemblies {} --where "cat != IgnoreAppVeyor"'

def RunUnitTestsOfSolution(solutionPath):
    nunitArguments = __NunitTestRunnerDefaultArguments.format(solutionPath)
    (returnCode,_) = binaryUtils.callExeWithArguments(__NunitConsoleRunnerBinaryPath,nunitArguments,False)
    if (not (returnCode == returnCodes.ExitSuccessCode)):
        raise RuntimeError(f"Test unit runner returned exit code, that was uneqal to the success code. Returned code: {returnCode}")

