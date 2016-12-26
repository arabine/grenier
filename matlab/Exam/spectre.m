function [DSP,F] = spectre(y,Fe,M)

N = length(y);
DSP = (1/N) * (abs(fft(y,M))).^2;
F = ((0:(M-1))/M)*Fe;
