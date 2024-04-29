function [y] = d1func(x)
% Autor: Konrad Burdach

% Warto zauważyć ze licząc granicę przy x -> 0 korzystacjąc z reguły
% L'Hospitala otrzymamy 1/6 oznacza to ze musimy znalaeźć inny sposób na
% liczenie wartosci funckji gdyż przy malych x wiemy ze sin(x) ~ x
% zatem komputer moze uznac to za 0 i wynik nie byłby poprawny

%liczy wartosc dla wektora x funckji y = (x - sin(x)) ./ x ./ x ./ x
y = (x - sin(x)) ./ x ./ x ./ x;

% przy duzych liczę z funckji
W = abs(x) > 1;

% Przy malych korzystam z Taylora
T = ~W;

%Tworzę wektor tam gdzie liczę taylorem
C = ones(size(x(T)));

% liczę Taylora a nastpępnie używam Hornera
% ostatecznie wygląda to tak
% 1/6(1 - (x^2/(4 * 5))(1 - (x^2/(6 * 7))(1 - x^2/(8 * 9)))) dla d = 8
x2 = x(T) .* x(T);
d = 20;

while d >= 4
    C = 1 - ((x2 ./ (d * (d + 1))) .* C);
    d = d - 2;

end
C = (1 / (3 * 2)) .* C;

% Uzupełniam 
y(T) = C;

end
