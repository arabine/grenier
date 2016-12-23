#!/bin/bash
echo "Début de la sauvegarde..."
archive='Prog.tar'
tar cf $archive /cygdrive/c/Prog 2> /dev/null
#tar rf $archive /etc 2> /dev/null
#tar rf $archive /home/moi/.Mail 2> /dev/null
bzip2 $archive
archive="${archive}.bz2"
ladate=`date +%Y-%m-%d_%Hh%Mm%Ss`
mv $archive "/cygdrive/h/Sauvegarde_Anthony/${ladate}_${archive}"
echo "Fin de la sauvegarde: "$ladate
