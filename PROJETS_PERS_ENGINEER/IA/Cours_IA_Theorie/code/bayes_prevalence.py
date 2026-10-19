"""Variation de la valeur predictive positive selon le taux de base."""
def precision_from_rates(prevalence, sensitivity, false_positive_rate):
    tp = sensitivity*prevalence
    fp = false_positive_rate*(1-prevalence)
    return tp/(tp+fp)

if __name__ == '__main__':
    for p in (0.10, 0.01, 0.001):
        value = precision_from_rates(p, .90, .05)
        print(f'prevalence={p:.3%}, precision={value:.2%}')
