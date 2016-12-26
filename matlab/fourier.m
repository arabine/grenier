f = 50;     % fréquence du signal
fe = 1024;  % fréquence d'échantillonnage
n = 0:fe;
t = n/fe;   % = n.Te

y = sin(2*pi*f*t);  % on discrétise un sinus à 50Hz
w = abs(fft(y));    % on s'intéresse au module de sa transformée de Fourier

%plot(w(1:512));     % les 512 valeurs suivantes sont redondantes

