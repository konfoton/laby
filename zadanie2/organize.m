function [x, y, p, t, ft] = organize(a, b, n, M, f, df)
% Tworzę węzły
c = linspace(a, b, n);

% Przygotowanie pod hermita
x = ones(1, length(c) * 2);
p = df(c);

% rzeczy pod wykres
t = linspace(a, b, M);
ft = f(t);

% Przygotowanie pod hermita (doublowanie argumentow i wartosci)
for i = 1:length(c)
    x(2 * (i - 1) + 1) = c(i);
    x(2 * (i - 1) + 2) =  c(i);
end

w = f(c);
y = ones(1, length(c) * 2);

for i = 1:length(c)
    y(2 * (i - 1) + 1) = w(i);
    y(2 * (i - 1) + 2) =  w(i);
end
end