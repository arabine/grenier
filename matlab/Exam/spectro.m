function [DSP,F] = spectro(y,fs,bits)


DSP=1/bits*abs(fft(y)).^2;
F=(0:length(DSP)-1)/length(DSP)*fs;
