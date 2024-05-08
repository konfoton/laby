function [t, ht, ft] = interphvals(f, df, a, b, n, M)
% autor: Konrad Burdach
[x, y, p, t, ft] = organize(a, b, n, M, f, df);
[w] = hermite(x, y, p);
[ht] = horner(w, t, x);
end