function [area] = simpson(a, b, G)
% korzystam ze wzory na zlożoną kwadraturę simpsona
H = (b - a) / ((length(G)-1)/2);
sum = G(1) + G(length(G));

% biorę skrajne wartości
for i = 3:2:length(G)-1
    sum = sum + 2 * G(i);
end

% biorę środkowe wartości
for i = 2:2:length(G)-1
    sum = sum + 4 * G(i);
end

area = H/6 * sum;

end

