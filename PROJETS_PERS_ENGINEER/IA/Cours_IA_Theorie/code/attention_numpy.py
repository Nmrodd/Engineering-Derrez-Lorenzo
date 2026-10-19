"""Attention scaled dot-product pedagogique, sans entrainement."""
import numpy as np

def softmax(x, axis=-1):
    z = x - x.max(axis=axis, keepdims=True)
    ex = np.exp(z)
    return ex / ex.sum(axis=axis, keepdims=True)

def attention(Q,K,V, causal=False):
    scores = Q @ K.T / np.sqrt(Q.shape[1])
    if causal:
        assert Q.shape[0] == K.shape[0]
        scores[np.triu_indices(Q.shape[0],1)] = -np.inf
    weights = softmax(scores,axis=-1)
    return weights @ V, weights

if __name__ == '__main__':
    Q=np.array([[1.,0.],[0.,1.]])
    K=np.array([[1.,0.],[0.,1.]])
    V=np.array([[10.,5.],[20.,1.]])
    value,weights=attention(Q,K,V,causal=True)
    print('poids:\n',weights,'\nvaleurs:\n',value)
    assert np.allclose(weights.sum(axis=1),1.0)
    assert weights[0,1] == 0.
