"""Personnalise la premiere page du PDF genere sans modifier sa pagination."""
from pathlib import Path
import fitz, math
ROOT=Path(__file__).resolve().parent.parent
pdf=ROOT/'Cours_theorique_IA.pdf'
doc=fitz.open(str(pdf));p=doc[0];W,H=p.rect.width,p.rect.height
# supprime uniquement le contenu de couverture generique
p.add_redact_annot(p.rect,fill=(.045,.11,.17));p.apply_redactions(images=2,graphics=1,text=0)
navy=(.045,.11,.17); teal=(.10,.77,.69); blue=(.40,.70,.89); white=(.94,.97,.99); faint=(.64,.73,.80)
fontreg='/usr/share/fonts/truetype/lato/Lato-Regular.ttf';fontbold='/usr/share/fonts/truetype/lato/Lato-Bold.ttf'
p.insert_font(fontname='LatoCus',fontfile=fontreg);p.insert_font(fontname='LatoBoldCus',fontfile=fontbold)
p.draw_rect(fitz.Rect(0,0,10,H),color=None,fill=teal)
p.draw_rect(fitz.Rect(0,0,W,10),color=None,fill=teal)
# network illustration background
nodes=[(375,140),(450,115),(505,158),(398,220),(475,248),(532,286),(350,300),(460,350)]
for i,(x,y) in enumerate(nodes):
 for j,(xx,yy) in enumerate(nodes):
  if j>i and math.dist((x,y),(xx,yy))<145:
   p.draw_line((x,y),(xx,yy),color=(.17,.32,.43),width=.8)
for i,(x,y) in enumerate(nodes):
 p.draw_circle((x,y),6 if i%3 else 9,color=blue if i%3 else teal,fill=navy,width=1.6)

def write(pos,txt,size,color=white,bold=False):
 p.insert_text(pos,txt,fontsize=size,fontname='LatoBoldCus' if bold else 'LatoCus',color=color)
write((55,82),'MODULE SCIENTIFIQUE • ÉDITION 2026',12,teal,True)
p.draw_line((55,103),(300,103),color=teal,width=2)
write((55,189),'INTELLIGENCE',37,white,True)
write((55,236),'ARTIFICIELLE',43,white,True)
write((55,279),'COURS THÉORIQUE ILLUSTRÉ',16,teal,True)
write((55,311),'Comprendre les mécanismes. Vérifier les équations.',12,white)
write((55,332),'Expérimenter avant de conclure.',12,white)
p.draw_line((55,375),(540,375),color=(.30,.45,.53),width=1.1)
write((55,416),'MATHÉMATIQUES ET DONNÉES',12,blue,True)
write((55,443),'APPRENTISSAGE STATISTIQUE',12,white,True)
write((55,470),'RÉSEAUX DE NEURONES ET PYTORCH',12,blue,True)
write((55,497),'NLP, ATTENTION, TRANSFORMERS ET LLM',12,white,True)
write((55,524),'RECHERCHE D’ÉTATS ET ROBOTIQUE',12,blue,True)
write((55,551),'INGÉNIERIE ET FIABILITÉ DES SYSTÈMES',12,white,True)
p.draw_rect(fitz.Rect(55,620,541,738),color=(.15,.35,.42),fill=(.08,.20,.27),width=.7)
write((73,650),'INCLUS DANS CE DOSSIER',12,teal,True)
write((73,681),'16 FIGURES ORIGINALES   •   EXERCICES CORRIGÉS',11,white,True)
write((73,708),'SOURCES PRIORISÉES   •   SCRIPTS PYTHON',11,white,True)
p.draw_line((55,773),(540,773),color=(.26,.42,.49),width=.8)
write((55,802),'Complément au « Manuel IA — Édition Grands Défis 2026 »',10,faint)
write((55,819),'Support de référence personnel · formation progressive en école d’ingénieurs',9,faint)
# sauvegarde atomique
tmp=pdf.with_name('Cours_theorique_IA_styled.pdf')
doc.save(str(tmp),garbage=3,deflate=True);doc.close();tmp.replace(pdf)
print('cover customized',pdf)
