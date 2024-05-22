function [area] = trapezy(a, b, G)
% korzystam ze wzoru na kwadraturę trapezów
H = (b-a) / (length(G) - 1);
sum = G(1) + G(length(G));

% suma po wartościach
for i = 2:length(G)-1
    sum = sum + 2 * G(i);
end

area = sum * H/2; 

end

