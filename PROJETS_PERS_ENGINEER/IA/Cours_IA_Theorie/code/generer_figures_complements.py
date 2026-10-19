"""Figures complementaires, originales, pour chapitres d'approfondissement."""
from pathlib import Path
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.patches import Rectangle, FancyBboxPatch
OUT=Path(__file__).resolve().parent.parent/'figures'
OUT.mkdir(exist_ok=True)
BLUE='#2878ae'; RED='#be586a'; GREEN='#278d7e'; NAV='#18324c'
plt.rcParams.update({'font.family':'DejaVu Sans','font.size':10,'figure.facecolor':'white','axes.grid':True,'grid.alpha':.1})
def save(name):
 plt.tight_layout(pad=1.6);plt.savefig(OUT/name,dpi=175,bbox_inches='tight',facecolor='white');plt.close()
# PCA
rng=np.random.default_rng(7);v=rng.normal(size=(300,2));m=v@np.array([[2.4,1.7],[.4,1.0]])
mu=m.mean(axis=0);cov=np.cov(m.T);eig,vec=np.linalg.eigh(cov);v1=vec[:,np.argmax(eig)]
fig,ax=plt.subplots(figsize=(8.5,3.6));ax.scatter(m[:,0],m[:,1],s=13,alpha=.33,color=BLUE)
ax.plot([mu[0]-5*v1[0],mu[0]+5*v1[0]],[mu[1]-5*v1[1],mu[1]+5*v1[1]],color=RED,lw=3,label='Axe de variance maximale')
ax.set(xlabel='Variable 1 (synthetique)',ylabel='Variable 2 (synthetique)',title='PCA : une direction qui conserve la variance dominante');ax.legend();save('14_pca.png')
# convolution
fig,ax=plt.subplots(figsize=(8.3,3.3));ax.axis('off');ax.set_xlim(0,10);ax.set_ylim(0,4.1)
A=np.array([[1,1,0,0,0],[1,1,0,0,0],[1,1,1,0,0],[0,0,0,1,1],[0,0,0,1,1]])
for i in range(5):
 for j in range(5):
  x=.25+j*.54;y=3.56-i*.54
  ax.add_patch(Rectangle((x,y),.52,.52,facecolor='#bcdced' if A[i,j] else '#f0f4f7',edgecolor='white'))
  ax.text(x+.26,y+.27,str(A[i,j]),ha='center',va='center',fontsize=10)
ax.add_patch(Rectangle((.25,3.56-2*.54),3*.54,3*.54,fill=False,edgecolor=RED,lw=2.8))
ax.text(1.56,.52,'Image 5 x 5',ha='center',fontsize=10,color=NAV)
ax.annotate('',xy=(4.1,2.4),xytext=(3.1,2.4),arrowprops={'arrowstyle':'->','lw':2,'color':NAV})
K=np.array([[1,0,-1],[1,0,-1],[1,0,-1]])
for i in range(3):
 for j in range(3):
  x=4.3+j*.56;y=3.3-i*.56
  ax.add_patch(Rectangle((x,y),.54,.54,facecolor='#f9e6e9',edgecolor='white'))
  ax.text(x+.27,y+.27,str(K[i,j]),ha='center',va='center',fontsize=10)
ax.text(5.1,.52,'Noyau 3 x 3',ha='center',fontsize=10,color=NAV)
ax.annotate('',xy=(7.2,2.4),xytext=(6.1,2.4),arrowprops={'arrowstyle':'->','lw':2,'color':NAV})
responses=np.array([[np.sum(A[i:i+3,j:j+3]*K) for j in range(3)] for i in range(3)])
for i in range(3):
 for j in range(3):
  x=7.45+j*.66;y=3.35-i*.66
  ax.add_patch(Rectangle((x,y),.64,.64,facecolor=('#bcead7' if responses[i,j] != 0 else '#d9e5e9'),edgecolor='white'))
  ax.text(x+.32,y+.32,str(int(responses[i,j])),ha='center',va='center',fontsize=10)
ax.text(8.4,.52,'Reponse 3 x 3',ha='center',fontsize=10,color=NAV)
save('15_convolution.png')
# Transformer
fig,ax=plt.subplots(figsize=(9.2,3.6));ax.set_xlim(0,10);ax.set_ylim(0,5);ax.axis('off')
stages=[('IDs tokens','(B,T)'),('Embeddings','(B,T,d_model)'),('Q, K, V','(B,T,d_k)'),('Attention','(B,T,d_v)'),('Logits','(B,T,V)')]
for i,(head,shape) in enumerate(stages):
 xx=.1+i*2.04
 box=FancyBboxPatch((xx,2),1.74,1.55,boxstyle='round,pad=.12',facecolor=('#dfeff8' if i<3 else '#e0f3eb'),edgecolor=(BLUE if i<3 else GREEN),lw=1.6)
 ax.add_patch(box);ax.text(xx+.87,2.94,head,ha='center',va='center',color=NAV,fontweight='bold',fontsize=9)
 ax.text(xx+.87,2.5,shape,ha='center',va='center',fontsize=8)
 if i<4: ax.annotate('',xy=(xx+2.02,2.77),xytext=(xx+1.78,2.77),arrowprops={'arrowstyle':'->','lw':2,'color':NAV})
ax.text(4.95,4.37,'Trajet d\'un modele autoregressif (dimensions simplifiees)',ha='center',color=NAV,fontsize=11,fontweight='bold')
ax.text(4.95,.85,'Le masque causal concerne les poids d\'attention : chaque position utilise seulement son passe.',ha='center',color=RED,fontsize=9)
save('16_transformer_flow.png')
print('added',3,'figures')
