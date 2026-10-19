"""Figures pédagogiques originales du support IA ; aucune donnée externe."""
from pathlib import Path
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.patches import FancyBboxPatch, Rectangle
from matplotlib import rcParams

OUT = Path(__file__).resolve().parent.parent / 'figures'
OUT.mkdir(parents=True,exist_ok=True)
rcParams.update({'font.family':'DejaVu Sans','axes.titlesize':13,'axes.labelsize':9,
                 'font.size':10,'figure.facecolor':'white','axes.spines.top':False,
                 'axes.spines.right':False,'axes.grid':True,'grid.alpha':0.13})
NAV='#18324c'; BLUE='#2878ae'; RED='#be586a'; GREEN='#278d7e'; VIO='#8067b3'
def save(n):
    plt.tight_layout(pad=1.7)
    plt.savefig(OUT/n, dpi=180, bbox_inches='tight', facecolor='white')
    plt.close()

# 1 Gradient
fig,ax=plt.subplots(figsize=(8.5,3.6)); x=np.linspace(-1,7,250); y=(x-3)**2
ax.plot(x,y,lw=2.8,color=BLUE); p=1.0
ax.scatter([p],[(p-3)**2],s=95,color=RED,zorder=4)
ax.plot([p-0.7,p+0.7],[(p-3)**2+(-4)*(-0.7),(p-3)**2+(-4)*0.7],'--',color=RED)
ax.annotate('gradient negatif : deplacer vers la droite',xy=(2.0,1.0),xytext=(3.3,7.5),arrowprops={'arrowstyle':'->','color':NAV},fontsize=9)
ax.set(xlabel='Parametre w', ylabel='Perte L(w)',title='Une dérivée indique la pente locale ; le signe guide la mise à jour');save('01_gradient.png')
# 2 base rate
fig,ax=plt.subplots(figsize=(8.5,3.0))
labels=['Fraudes detectees (TP)','Alertes injustifiees (FP)']; val=[90,495]
ax.barh(labels[::-1],val[::-1],color=[RED,GREEN]);ax.set(xlim=(0,570),xlabel='Nombre de transactions — exemple synthetique',title='Sensibilite 90 % et 5 % de faux positifs, prevalence de 1 %')
for i,v in enumerate(val[::-1]):ax.text(v+8,i,str(v),va='center',fontsize=12,fontweight='bold')
ax.text(290,-0.52,'Precision = 90 / (90 + 495) = 15,4 %',fontsize=10,color=NAV)
save('02_base_rate.png')
#3 regression
rng=np.random.default_rng(30);x=np.linspace(20,120,40);y=1.85*x+24+rng.normal(0,19,40)
fig,ax=plt.subplots(figsize=(8.5,3.5));ax.scatter(x,y,alpha=.65,color=BLUE,label='Observations simulees')
ax.plot(x,1.85*x+24,color=RED,lw=2.5,label='Tendance generatrice')
ax.set(xlabel='Surface (m2)',ylabel='Prix fictif (unites)',title='Regressions : une tendance, pas une certitude individuelle');ax.legend();save('03_regression.png')
#4 split
fig,ax=plt.subplots(figsize=(8.5,1.9));parts=[(0,.6,'Entrainement\n60 %',BLUE),(.6,.2,'Validation\n20 %',VIO),(.8,.2,'Test\n20 %',GREEN)]
for start,sz,label,col in parts:
 ax.add_patch(Rectangle((start,.22),sz,.58,color=col));ax.text(start+sz/2,.51,label,ha='center',va='center',color='white',weight='bold')
ax.text(.5,.05,'Illustration seulement : les proportions varient selon le probleme',ha='center',fontsize=9)
ax.set_xlim(0,1);ax.set_ylim(0,1);ax.axis('off');save('04_splits.png')
#5 overfit
x=np.arange(1,51);tr=.82*np.exp(-x/11)+.04;vl=.75*np.exp(-x/8)+.14+0.00017*np.maximum(x-18,0)**2
fig,ax=plt.subplots(figsize=(8.5,3.3));ax.plot(x,tr,label='Erreur entrainement',lw=2.4,color=BLUE)
ax.plot(x,vl,label='Erreur validation',lw=2.4,color=RED)
ax.axvline(21,linestyle='--',color='gray');ax.text(22,.38,'complexite croissante\npeut nuire a la validation',fontsize=8)
ax.set(xlabel='Complexite / iterations (schematique)',ylabel='Erreur',title='Le meilleur score train ne garantit pas la generalisation');ax.legend();save('05_overfit.png')
#6 confusion
m=np.array([[164,6],[12,18]])
fig,ax=plt.subplots(figsize=(6.4,3.4));im=ax.imshow(m,cmap='Blues')
for i in range(2):
 for j in range(2):ax.text(j,i,str(m[i,j]),ha='center',va='center',size=18,color='white' if m[i,j]>70 else NAV,fontweight='bold')
ax.set_xticks([0,1],['Normal','Fraude']);ax.set_yticks([0,1],['Normal','Fraude']);ax.set_xlabel('Predit');ax.set_ylabel('Reel');ax.set_title('Matrice de confusion — exemple fictif');save('06_confusion.png')
#7 curves vary threshold using handcrafted function plausible
rng=np.random.default_rng(12);labels=np.array([1]*75+[0]*925);score=np.concatenate([rng.beta(4,2,75),rng.beta(1.2,5.2,925)])
thresholds=np.linspace(.02,.99,100); prec=[];rec=[]
for th in thresholds:
 p=score>=th;tp=np.sum(p & (labels==1));fp=np.sum(p & (labels==0));fn=np.sum((~p)&(labels==1))
 prec.append(tp/max(1,tp+fp));rec.append(tp/max(1,tp+fn))
fig,ax=plt.subplots(figsize=(8.5,3.3));ax.plot(thresholds,prec,label='Precision',color=BLUE,lw=2.5);ax.plot(thresholds,rec,label='Rappel',color=RED,lw=2.5)
ax.set(xlabel='Seuil de classification',ylabel='Score',ylim=(0,1.02),title='Compromis precision/rappel : donnees generees artificiellement');ax.legend();save('07_pr_curve.png')
#8 activation
x=np.linspace(-5,5,300);fig,ax=plt.subplots(figsize=(8.5,3.4));ax.plot(x,np.maximum(x,0),label='ReLU',lw=2.4,color=BLUE)
ax.plot(x,1/(1+np.exp(-x)),label='Sigmoide',lw=2.4,color=RED)
ax.plot(x,np.tanh(x),label='tanh',lw=2.2,color=GREEN);ax.axhline(0,c='gray',lw=.5)
ax.set(xlabel='Entree z',ylabel='Activation phi(z)',title='Non-linearites usuelles');ax.legend();save('08_activation.png')
#9 backprop flow
fig,ax=plt.subplots(figsize=(9,2.65));ax.set_xlim(0,10);ax.set_ylim(0,3.4);ax.axis('off')
xs=[1.15,3.7,6.2,8.7];labels=['x\nEntree','h = phi(Wx+b)\nCouche','y chapeau\nPrediction','L\nPerte']
for i,(xx,lbl) in enumerate(zip(xs,labels)):
 rect=FancyBboxPatch((xx-1,.95),2,1.35,boxstyle='round,pad=.2',facecolor=('#e5f1f9' if i<3 else '#f7e5e9'),edgecolor=(BLUE if i<3 else RED),lw=1.5);ax.add_patch(rect)
 ax.text(xx,1.62,lbl,ha='center',va='center',size=9)
 if i<3:ax.annotate('',xy=(xs[i+1]-1.25,1.6),xytext=(xx+1.25,1.6),arrowprops={'arrowstyle':'->','lw':1.9,'color':BLUE})
for i in range(3,0,-1):ax.annotate('',xy=(xs[i-1]+.2,.45),xytext=(xs[i]-.25,.45),arrowprops={'arrowstyle':'->','lw':1.8,'color':RED})
ax.text(5,2.9,'FORWARD : calcul des activations et de la perte',ha='center',color=BLUE,weight='bold')
ax.text(5,.05,'BACKWARD : calcul des gradients par regle de chaine',ha='center',color=RED,weight='bold');save('09_backprop.png')
#10 embedding
fig,ax=plt.subplots(figsize=(8.5,3.5));
pts={'film':(1,2.1),'cinema':(1.2,1.8),'acteur':(1.7,2.0),'banque':(5.9,1.7),'virement':(5.1,2.1),'solde':(5.4,1.3),'cube':(3.2,4.6),'rotation':(3.65,4.2)}
for name,(xx,yy) in pts.items():
 col=BLUE if name in ['film','cinema','acteur'] else RED if name in ['banque','virement','solde'] else GREEN
 ax.scatter(xx,yy,s=95,color=col);ax.annotate(name,(xx,yy),xytext=(5,6),textcoords='offset points',fontsize=10)
ax.set(xlim=(0,7),ylim=(0.5,5.2),xlabel='Dimension latente 1 (fictive)',ylabel='Dimension latente 2 (fictive)',title='Proximites semantiques schematisees, non apprises');save('10_embeddings.png')
#11 attention
mat=np.array([[.8,.15,.04,.01],[.22,.55,.2,.03],[.18,.24,.48,.10],[.12,.16,.30,.42]])
fig,ax=plt.subplots(figsize=(7.5,3.6));im=ax.imshow(mat,cmap='Blues',vmin=0,vmax=.85)
for i in range(4):
 for j in range(4):ax.text(j,i,f'{mat[i,j]:.2f}',ha='center',va='center',fontsize=9,color='white' if mat[i,j]>.44 else NAV)
ax.set_xticks(range(4),['Le','modele','lit','texte']);ax.set_yticks(range(4),['Le','modele','lit','texte']);ax.set(xlabel='Position de la cle K',ylabel='Position de la requete Q',title='Attention : chaque ligne pese des positions source');fig.colorbar(im,ax=ax,label='Poids apres softmax');save('11_attention.png')
#12 search tree
fig,ax=plt.subplots(figsize=(8.5,3.2));ax.axis('off');nodes=[(4,.9,'s0'),(2,2.,'s1'),(6,2.,'s2'),(1,3.,'s3'),(3,3.,'s4'),(5,3.,'s5'),(7,3.,'s6')]
# need flip height
nodes=[(x,3.9-y,n) for x,y,n in nodes]
for p,c in [(0,1),(0,2),(1,3),(1,4),(2,5),(2,6)]:
 x1,y1,_=nodes[p];x2,y2,_=nodes[c];ax.plot([x1,x2],[y1,y2],color='#9aaaba',lw=1.5)
for x,y,n in nodes:
 ax.scatter([x],[y],s=600,color=GREEN if n=='s4' else BLUE,zorder=3)
 ax.text(x,y,n,ha='center',va='center',color='white',fontsize=10,weight='bold')
ax.text(4,.1,'Chaque branche est une action ; un meme etat peut etre atteint par differents chemins.',ha='center',fontsize=9)
ax.set(xlim=(0,8),ylim=(-.15,3.65));save('12_search_tree.png')
#13 drift
x=np.arange(180);rng=np.random.default_rng(4);series=15 + .018*x + 2*np.sin(x/9) + rng.normal(0,1.25,len(x));series[105:]+=6
fig,ax=plt.subplots(figsize=(8.5,3.4));ax.plot(x,series,color=BLUE,lw=1.1);ax.axvline(105,color=RED,ls='--',lw=2,label='Changement simule du processus')
ax.plot(x[:105],np.repeat(np.mean(series[:105]),105),lw=2,color=GREEN,label='Moyenne historique')
ax.set(xlabel='Temps (unites arbitraires)',ylabel='Signal mesure (fictif)',title='La distribution des donnees peut changer apres deploiement');ax.legend(fontsize=8);save('13_drift.png')
print('generated',len(list(OUT.glob('*.png'))),'figures')
