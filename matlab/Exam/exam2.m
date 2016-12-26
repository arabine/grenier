clear all;
close all;

%lecture du fichier son
[y,fs,bits]=wavread('piano.wav');
[y1,fs1,bits1]=wavread('trompette.wav');
[y2,fs2,bits2]=wavread('hautbois.wav');

%calcul du spectrogramme 
[B,F,T]=specgram(y,256,fs,ones(1,256),0);
%Affichage divers
figure
subplot(3,2,1)
t=(1:length(y))/fs;
plot(t,y);
title('signal piano.wav')

subplot(3,2,2)
fx2=1/bits*abs(fft(y)).^2;
freq=(0:length(fx2)-1)/length(fx2)*fs;
plot(freq,fx2)
title('densité spectrale de puissance du piano')



subplot(3,2,3)
t1=(1:length(y1))/fs1;
plot(t1,y1);
title('signal trompette.wav')

subplot(3,2,4)
fx3=1/bits*abs(fft(y1)).^2;
freq1=(0:length (fx3)-1)/length(fx3)*fs1;
%fx2=abs(fft(y,8192)).*abs(fft(y,8192))/8192;
plot(freq1,fx3)
title('densité spectrale de puissance du trompette')

subplot(3,2,5)
t2=(1:length(y2))/fs2;
plot(t2,y2);
title('signal hautbois.wav')

subplot(3,2,6)
fx4=1/bits*abs(fft(y2)).^2;
freq2=(0:length(fx4)-1)/length(fx4)*fs2;
%fx2=abs(fft(y,8192)).*abs(fft(y,8192))/8192;
plot(freq2,fx4)
title('densité spectrale de puissance du hautbois.wav')
figure

imagesc(T,F,10*log10(abs(B))), axis xy, colormap(jet);
title('periodogramme piano.wav')

figure
mesh(T,F,10*log10(abs(B)));
xlabel('temps');
ylabel('frequence');
title('densité spectrale de puissance du signal doppler')



