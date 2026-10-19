"""Confusion, precision, rappel, F1, sans scikit-learn."""
import numpy as np

def metrics(y_true,y_pred):
    y_true=np.asarray(y_true,dtype=int);y_pred=np.asarray(y_pred,dtype=int)
    assert len(y_true) == len(y_pred)
    tp=int(np.sum((y_true==1)&(y_pred==1)))
    fp=int(np.sum((y_true==0)&(y_pred==1)))
    fn=int(np.sum((y_true==1)&(y_pred==0)))
    tn=int(np.sum((y_true==0)&(y_pred==0)))
    pr=tp/(tp+fp) if tp+fp else 0.
    re=tp/(tp+fn) if tp+fn else 0.
    f1=2*pr*re/(pr+re) if pr+re else 0.
    return {'TP':tp,'FP':fp,'FN':fn,'TN':tn,'precision':pr,'recall':re,'F1':f1}

if __name__ == '__main__':
    truth=[1]*30+[0]*170
    pred=[1]*18+[0]*12+[1]*6+[0]*164
    m=metrics(truth,pred)
    print(m)
    assert abs(m['F1']-2/3) < 1e-12
