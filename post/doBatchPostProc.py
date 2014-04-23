import os

dict={'dir':os.environ['CMSSW_BASE']+'/src/VHbb/post'}

jdf=open('condor.job','w')
jdf.write(
"""universe = vanilla
Executable = %(dir)s/doBatchPostProc.sh
Should_Transfer_Files = YES
WhenToTransferOutput = ON_EXIT
Output = condor.out
Error = condor.err
Log = condor.log
Notification = Never
Arguments = %(dir)s

Queue 1"""%dict)
jdf.close()

os.system('condor_submit condor.job')
                  
