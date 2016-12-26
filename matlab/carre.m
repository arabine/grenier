u = 0;
t = 0:0.001:pi;
for n=1:n*2-1:15
    u = u + (2*(1-cos(pi*n))/(pi*n))*sin(2*pi*n*t);
end
figure1(1);


figure(2);
plot(u);


%y = sin(2*pi*f*t);  % on discrétise un sinus à 50Hz
%w = abs(fft(y));    % on s'intéresse au module de sa transformée de Fourier

%plot(w(1:512));     % les 512 valeurs suivantes sont redondantes

