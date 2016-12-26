#!/usr/bin/perl -w

# liste des fichiers .psf dans un répertoire et affiche 
# le nombre de voies polyphoniques
# belegar@programmationworld.com

print "Entrer un chemin de répertoire (par défaut ./)\n";
$rep =<>; chomp($rep);
$rep= "." if ! $rep;
chdir($rep);
print "Recherche des .psf dans : $rep\n\n";
opendir R, $rep or die "impossible d'ouvrir le rép. $rep";
@liste=readdir(R);
foreach $f (@liste)
{
  next if $f eq "." or $f eq "..";
  if (-f $f)
  {
	if($f =~ /\.psf$/ )
	{
	  open(FIC, $f);
	  @lines = <FIC>;  	# Stockage du contenu dans un tableau
	  close(FIC); 	    # Ferme le fichier
	  $lines[0] =~ /[0-9]+/; # la première ligne contient la valeur
	  print $f."\t: ".$&." voies\n";
	}
  }
}
closedir R;
