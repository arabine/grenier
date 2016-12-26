clear all;
close all;


%analyse spectrale d'un fichier *.wav

%representation temporelle du signal
[y,fs,bits] = wavread('piano');
t=(1:length(y))/fs;
figure(1)
subplot(2,2,1)
plot(t,y)

pause;
% methode du periodogramme

[freq,dsp]=spectre(y,fs,bits);
figure(2);
plot(freq,dsp);