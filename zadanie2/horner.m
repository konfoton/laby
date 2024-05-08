function [ht] = horner(w, t, x)
% horner do wzoru newtona wektorowy 
ht  = w(length(x)) .* (t - x(length(x) - 1));
for i = length(x)-1:-1:2
    ht = (t - x(i-1)) .* (ht + w(i));
end
ht = ht + w(1);

end