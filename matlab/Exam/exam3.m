[y,fs,bits]=wavread('piano.wav');
t=(1:length(y))/fs;
figure(1)
subplot(2,2,1)
plot(t,y);
title('representation temporelle du signal piano')

%determination du spectrogramme du signal piano
[B,F,T]=specgram(y,256,fs,ones(1,256),0);
subplot(2,2,2)
imagesc(T,F,10*log10(abs(B))), axis xy, colormap(jet);
title('spectrogramme du signal piano')

subplot(2,2,3)
mesh(T,F,10*log10(abs(B)));
xlabel('temps');
ylabel('frequence');
title('spectrogramme du signal piano')

%determination de la DSP du signal piano 
[DSP,F] = spectro(y,fs,bits);
subplot(2,2,4)
plot(F,DSP)
title('representation de la DSP du signal piano')


%representation temporelle du signal dans sa zone stationnaire
figure(2)
x = y(10000:25000) ;
t=(1:length(x))/fs;
plot(t,y(10000:25000))
title('representation temporelle du signal piano dans sa zone stationnaire');
