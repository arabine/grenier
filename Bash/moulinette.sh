#!/bin/bash
root_file="/cygdrive/z/Root"


search () {
for dir in `echo *`
#  ==> `echo *` lists all the files in current working directory,
#+ ==> without line breaks.
#  ==> Similar effect to for dir in *
#  ==> but "dir in `echo *`" will not handle filenames with blanks.
do
    if [ -d "$dir" ] ; then # ==> If it is a directory (-d)...
      
        if [ "$dir" == "CVS" ] ; then
            cp $root_file $dir
            echo "$dir --> fichier copié"
        fi

        if cd "$dir" ; then         # ==> If can move to subdirectory...
            search `expr $1 + 1`      # with recursion ;-)
            # ==> Function calls itself.
            cd ..
        fi
    
    fi
done
}


if [ $# != 0 ] ; then
  cd $1 # move to indicated directory.
  #else # stay in current directory
fi

echo "Initial directory = `pwd`"

search 0

exit 0
