function hippi(t, ht, ft)
% wykres
plot(t, ft, 'LineWidth', 6, 'Color', [108/255, 233/255, 0]);
hold on;
plot(t, ht, 'LineWidth', 2, 'Color', [130/255, 18/255, 0]);
ylim([min(min(ft), min(ht)) max(max(ft), max(ht))]);
hold off;
end