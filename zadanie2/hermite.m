function [w] = hermite(x, y, p)
% klasyczy netwon + dodatek hemita <=> zeruje się mianownik
w = y;
z = y;
for j = 2:length(x)
    for i = j:length(x)
        if x(i-j+1) ~= x(i)
            w(i) = ((z(i-1) - z(i))/(x(i-j+1) - x(i)));
        else
            w(i) = p(i/2);
        end
    end
    z = w;
end
end
