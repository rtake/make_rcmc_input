%infile=lys_protonated
# REPATH/PM6
RCMC input for lys_protonated
1 1
H          1.801692774332          2.569234973853          1.503926083838
C          0.158000926127          0.758778575797         -0.894590742148
C          0.618315997516          1.993697957815         -0.006159953566
N          1.348078153919          0.640195772639         -1.711940891637
O          1.396023506533          1.785558609413          1.010925680394
O          0.244978224674          3.169345026270         -0.412153239627
H         -0.747076158056          1.119269549270         -1.464875188742
H          1.198724103908          0.752021368777         -2.712617591850
H          1.927827074311         -0.174792886175         -1.518663145377
H          0.603925393547          4.002275255693          0.032040883482
C         -0.186137162762         -0.415854880984          0.019695328478
H         -0.916171386741         -0.107990068667          0.799432605147
H          0.706885215356         -0.768652203795          0.580993329241
C         -0.780252339327         -1.574397524466         -0.797342513872
C         -1.116265659081         -2.767405260685          0.104314517589
H         -0.071714485294         -1.897509305513         -1.586330548603
C         -1.708529821426         -3.929975809779         -0.724700227960
H         -1.836276954702         -2.467640242607          0.890236801744
H         -0.211810207051         -3.115651274460          0.639429686823
H         -1.697831615902         -1.242387144555         -1.326161182505
N         -2.058960380148         -5.130605111468          0.063508080760
H         -0.989755557700         -4.240355466461         -1.517304939367
H         -2.626699333530         -3.591318365232         -1.257437014451
H         -2.760998178143         -4.928439492231          0.767101319782
H         -1.250495005518         -5.522020675687          0.534539740216
Options
Siml_initEQs=0-663
GRRMroot=/home/rtake/GRRMdv9b22/
KeepIntfiles
DetailedOutput=ON
GauProc=1
GauMem=1000
DownDC=50
DownDC-small=6
RCMCOnly
TrafficVolCheck
ReClustering
MatchDecScale=1
StructCheckThreshold=6.0 0.03 0.06
SIML_Temperature=5000
Timescale=1e+9
