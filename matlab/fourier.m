f = 50;     % fr�quence du signal
fe = 1024;  % fr�quence d'�chantillonnage
n = 0:fe;
t = n/fe;   % = n.Te

y = sin(2*pi*f*t);  % on discr�tise un sinus � 50Hz
w = abs(fft(y));    % on s'int�resse au module de sa transform�e de Fourier

%plot(w(1:512));     % les 512 valeurs suivantes sont redondantes

