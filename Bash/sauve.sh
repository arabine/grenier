#!/bin/bash
echo "Debut de la sauvegarde..."
#mount -t smbfs -o username=alderande,password=coffee //Emul2/BackupAlderande /backup
echo "Repertoire backup monte."
archive='archive.tar'
cd /tmp
echo "entre dans /tmp."
tar cf $archive /var/lib/cvsroot 2> /dev/null
echo "tar /etc .."
tar rf $archive /etc 2> /dev/null
echo "tar /var/www .."
tar rf $archive /var/www 2> /dev/null
echo "tar /var/lib/mysql .."
tar rf $archive /var/lib/mysql 2> /dev/null
echo "bzip2 de l'archive."
bzip2 $archive
archive="${archive}.bz2"
ladate=`date +%Y-%m-%d_%Hh%Mm%Ss`
echo "transfert de l'archive .."
mv $archive "/backup/${ladate}_${archive}"
echo "dump de mysql .."
mysqldump -u root -p coffee gestion_soft > /backup/dumpmysql.sql
echo "demontage de l'archive"
#umount -l /backup
#umount -f /backup
echo "Fin de la sauvegarde: "$ladat
