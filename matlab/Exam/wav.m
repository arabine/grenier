%analyse spectrale d'un fichier *.wav

%representation temporelle du signal
[y,fs,bits] = wavread('eject');
figure(1)
subplot(2,2,1)
plot(t,y)
title('representation temporelle du signal eject.wav ');

%representation de la densité spectrale de puissance
n=length(y);
[b,f,t] = specgram(y,n,fs,ones(1,n),o);
subplot(2,2,2)
plot(f,b)
title('DSP du signal eject.wav ');

%restriction du signal a sa zone stationnaire

%representation temporelle du signal
subplot(2,2,3)
x = y(50000:60000) ;
plot(x)
title('representation temporelle du signal eject.wav dans sa zone stationnaire');

%representation de la densité spectrale de puissance
n=length(x);
[DSP,F] = spectre(x,1,2*n);
subplot(2,2,4)
plot(F,DSP)
title('DSP du signal eject.wav dans sa zone stationnaire');

%representation de la densité spectrale de puissance en decibel
figure(2)
n=length(x);
[DSP,F] = spectre(x,1,2*n);
DSP_10db = 10*log(DSP) ;
plot(F,DSP_10db)
title('DSP du signal eject.wav dans sa zone stationnaire en decibel');



