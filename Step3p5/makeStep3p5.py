import os,shutil,datetime
import getpass
from ROOT import *

#IO directories must be full paths

inputDirNom='/eos/uscms/store/user/sethzenz/fromdcache/Ntuple_Step1V42_Step2Tag_EDMV42_Step2_V6_MC_varsAddedSummed_v19/nominal'   #nominal MC
#inputDir='/eos/uscms/store/user/sethzenz/fromdcache/Ntuple_Step1V42_Step2Tag_EDMV42_Step2_V6_MC_varsAddedSummed_v19/JER_down'   #JER_down
inputDir='/eos/uscms/store/user/sethzenz/fromdcache/Ntuple_Step1V42_Step2Tag_EDMV42_Step2_V6_MC_varsAddedSummed_v19/JER_up'   #JER_up

outputDir='/eos/uscms/store/user/lpcmbja/noreplica/ssagir/step3p5'

#########################################################################################################################
#Helper function for shutil.copytree

def files(dir, files):
    return [f for f in files if os.path.isfile(os.path.join(dir, f))]

#########################################################################################################################

runDir=os.getcwd()

if not os.path.isdir('condor'): os.mkdir('condor')

cTime=datetime.datetime.now()
date='%i_%i_%i'%(cTime.year,cTime.month,cTime.day)

condorDir='/uscmst1b_scratch/lpc1/3DayLifetime/'+getpass.getuser()+'/condorLogs/step3p5/%s/%s'%(date,inputDir.split('/')[-1])#'%s/condor/%s/%s'%(runDir,date,inputDir.split('/')[-1])
outputDir+='/%s/%s'%(date,inputDir.split('/')[-1])

shutil.copytree(inputDir,outputDir,ignore=files)
shutil.copytree(inputDir,condorDir,ignore=files)

os.system('voms-proxy-init -valid 168:00')
proxyPath=os.popen('voms-proxy-info -path')
proxyPath=proxyPath.readline().strip() 

for directory, subDirectories, files in os.walk(inputDir):
    if files:
        relPath=directory.replace(inputDir,'')
        if relPath.startswith('/WHiggs0'): 
        	relPathNom=relPath[:-len(relPath.split('/')[-1])-1]
        else: 
        	relPathNom=relPath
        
        dict={'RUNDIR':runDir, 'RELPATH':relPath, 'RELPATHNOM':relPathNom, 'CONDORDIR':condorDir, 'INPUTDIR':inputDir, 'INPUTDIRNOM':inputDirNom, 'PROXY':proxyPath}
        jdfName='%(CONDORDIR)s/%(RELPATH)s/job'%dict

        jdf=open(jdfName,'w')
        jdf.write(
"""x509userproxy = %(PROXY)s
universe = vanilla
Executable = %(RUNDIR)s/makeStep3p5.sh
Should_Transfer_Files = YES
WhenToTransferOutput = ON_EXIT
Output = %(CONDORDIR)s/%(RELPATH)s/out
Error = %(CONDORDIR)s/%(RELPATH)s/err
Log = %(CONDORDIR)s/%(RELPATH)s/log
Notification = Never
Arguments = %(RUNDIR)s %(INPUTDIR)s/%(RELPATH)s %(INPUTDIRNOM)s/%(RELPATHNOM)s

Queue 1"""%dict)
        jdf.close()
        
        os.chdir('%s/%s'%(outputDir,relPath))
        os.system('condor_submit '+jdfName)
                 
