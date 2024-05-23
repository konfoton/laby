function [x] = gausse(A, b)
A(:, length(A)+1) = b;
for i = 1:length(A)-2
    for j = i+1:length(A)-1
        A(j, :) = A(j, :) - A(i, :) .* A(j, i) ./ A(i, i);
    end
end
x = ones(1, length(A)-1);
for i = length(A)-1:-1:1
    x(i) = A(i, end);
    for j = length(A)-1:-1:i+1
        x(i) = x(i) - A(i, j) * x(j);
    end
    x(i) = x(i) / A(i, i);
end

end

