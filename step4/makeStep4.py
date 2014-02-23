import os,shutil,datetime

#IO directories must be full paths

#inputDir='/eos/uscms/store/user/sethzenz/fromdcache/Ntuple_Step1V42_Step2Tag_EDMV42_Step2_V6_MC_varsAddedSummed_v19'
inputDir='/eos/uscms/store/user/sethzenz/fromdcache/Ntuple_Step1V42_Step2Tag_EDMV42_Step2_V6_MC_varsAddedSummed_v19/nominal'
outputDir='/uscmst1b_scratch/lpc1/3DayLifetime/jstupak'

#########################################################################################################################
#Helper function for shutil.copytree

def files(dir, files):
    return [f for f in files if os.path.isfile(os.path.join(dir, f))]

#########################################################################################################################

runDir=os.getcwd()

if not os.path.isdir('condor'): os.mkdir('condor')

cTime=datetime.datetime.now()
date='%i_%i_%i'%(cTime.year,cTime.month,cTime.day)

condorDir='%s/condor/%s/%s'%(runDir,date,inputDir.split('/')[-1])
outputDir+='/%s/%s'%(date,inputDir.split('/')[-1])

shutil.copytree(inputDir,outputDir,ignore=files)
shutil.copytree(inputDir,condorDir,ignore=files) 

for directory, subDirectories, files in os.walk(inputDir):
    if files:
        relPath=directory.replace(inputDir+'/','')
        
        dict={'RUNDIR':runDir, 'RELPATH':relPath, 'CONDORDIR':condorDir, 'INPUTDIR':inputDir}
        jdfName='%(CONDORDIR)s/%(RELPATH)s/job'%dict

        jdf=open(jdfName,'w')
        jdf.write(
"""universe = vanilla
Executable = %(RUNDIR)s/makeStep4.sh
Should_Transfer_Files = YES
WhenToTransferOutput = ON_EXIT
Output = %(CONDORDIR)s/%(RELPATH)s/out
Error = %(CONDORDIR)s/%(RELPATH)s/err
Log = %(CONDORDIR)s/%(RELPATH)s/log
Notification = Never
Arguments = %(RUNDIR)s %(INPUTDIR)s/%(RELPATH)s

Queue 1"""%dict)
        jdf.close()
        
        os.chdir('%s/%s'%(outputDir,relPath))
        os.system('condor_submit '+jdfName)
                 
