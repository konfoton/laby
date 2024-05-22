function [Q] = trzydokint(G, a, b)
% Autor: Konrad Burdach
% Wiemy, że 3^k + 1 jest zawsze parzyste dlatego dziele go na dwa podziały
% jeden liczę simpsonem a drugi trapezem (ostatnie dwa punkty to trapez)
% liczę przedział
H = (b-a) / (length(G)-1);

% simpson
A = G(:, 1:end-1);
Q = simpson(a, b-H, A);

% trapez
B = G(:, end-1:end);
Q = Q + trapezy(b-H,b, B);

end



