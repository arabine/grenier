% function [c]=corr(x,y,p,option);
% Calcul des fonctions d'auto et d'intercorrelation de deux signaux 
% a valeurs relles, de meme longueur, pour un retard compris 
% entre -(p-1) et +(p-1) (donc 2p-1 valeurs de la correlation). 
% Les parametres d'entree sont les suivants : 
%       x : vecteur d'entree, 
%       y : vecteur (optionnel), 
%       p : scalaire indiquant le nombre de valeurs de la 
%               fonction a calculer (optionnel), 
%       option : choix de l'estimateur biaise ('b') ou 
%               non biaise ('nb') (optionnel, 'b' par defaut). 
% 
% Exemples :    corr(x) 
%               corr(x,y,'nb') 
%               corr(x,p,'nb') 
%
% Auteur : JFB (c) 1994-1996
%
%-----------------------------------------------------------------------

x=x(:).';  
N=max(size(x)); 
% 
% Tests sur les parametres d'entree 
% 
if nargin == 1 
	y=x; 
	p=max(size(x)); 
	option = 'b'; 
elseif nargin == 2 
	if isstr(y) 
		option = y;     clear y 
		y=x; 
		p=N; 
	else 
		if size(y) == [1 1] 
			p=y;    clear y 
			y=x; 
			option='b'; 
		else 
			option = 'b'; 
			p=N; 
		end; 
	end; 
elseif nargin == 3 
	if size(y)==[1 1] 
		option=p; 
		p=y;    clear y 
		y=x; 
	elseif isstr(p) 
		option=p;       clear p 
		p=N; 
		y=y(:).'; 
	else 
		y=y(:).'; 
		option='b'; 
	end; 
end; 
% 
% Gestion des erreurs 
% 
if max(size(x))~=max(size(y)) 
	error('les deux vecteurs doivent etre de meme dimension') 
end; 
% 
if min(size(x))~= 1 & min(size(x)) ~= 1 
	error('il faut passer deux vecteurs') 
end; 
% 
if size(p)~=[1 1] 
	error('p doit etre un scalaire') 
end; 
% 
if p>N 
	error('p ne peut etre superieur a la dimension du vecteur') 
end; 
% Validite de l'option 
nopt = nan; 
if strcmp(option, 'b') 
	nopt = 0; 
elseif strcmp(option, 'nb') 
	nopt = 1; 
end; 
if isnan(nopt) 
	error('option inconnue') 
end; 
% 
% disp('affichage des parametres d''entree') 
% p 
% option 
% disp('calcul...') 
% 
c=zeros(1,p); 
y=y(:).'; 
for ii=1:p 
	c(ii)=1/(N-nopt*(ii-1))*x(1:N-ii+1)*y(ii:N)'; 
end; 
c1=fliplr(c); 
for ii=2:p 
	c(ii)=1/(N-nopt*(ii-1))*x(ii:N)*y(1:N-ii+1)';
end; 
c2=c(2:p); 
c=[c1 c2]; 
% disp('c''est fini')