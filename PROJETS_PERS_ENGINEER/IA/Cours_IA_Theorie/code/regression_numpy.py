"""Régression linéaire de zéro, données artificielles."""
import numpy as np

def fit_regression(X, y, lr=0.04, steps=250):
    X = np.asarray(X, dtype=float)
    y = np.asarray(y, dtype=float)
    assert X.ndim == 1 and y.shape == X.shape
    # Centrage/reduction pour une optimisation plus stable
    mu, sigma = X.mean(), X.std()
    assert sigma > 0
    z = (X - mu) / sigma
    w, b = 0.0, 0.0
    losses = []
    for _ in range(steps):
        pred = w*z + b
        err = pred - y
        losses.append(np.mean(err**2))
        dw = 2*np.mean(err*z)
        db = 2*np.mean(err)
        w -= lr*dw
        b -= lr*db
    return w, b, mu, sigma, np.array(losses)

if __name__ == '__main__':
    rng = np.random.default_rng(123)
    X = np.linspace(20, 80, 120)
    y = 2*X + 40 + rng.normal(0, 7, 120)
    w,b,mu,sigma,losses = fit_regression(X,y)
    print('erreur initiale',round(float(losses[0]),3),'erreur finale',round(float(losses[-1]),3))
    print('prediction pour 50',round(float(w*((50-mu)/sigma)+b),2))
    assert losses[-1] < losses[0]
