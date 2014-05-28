from DataCard import *
from sys import argv

###############################################################################################
#
# doPostProc.py creates dataCard with 0P and 0M signals by default, for hypothesis testing.
# This script makes separate dataCards for 0P, 0M, and 50/50 mix for simple limit setting.
# Usage: python makeAllDataCards.py <inputDir>
# <inputDir> should contain a 'yields.p' pickle file from which a dataCard can be constructed.
#
###############################################################################################

try: inputDir=argv[1]
except:
    print "No input dir specified"
    exit(1)

for signal in ['Wh_125p6_0P','Wh_125p6_0M','Wh_125p6_0Mf05ph0']:

    theCard=DataCard(signalNames=[signal])
    theCard.fromPickle(inputDir+'/yields.p')
    theCard.construct()

    shortName=signal.split('_')[-1]
    theCard.toTxt(inputDir+'/dataCard_'+shortName+'.txt')

    
