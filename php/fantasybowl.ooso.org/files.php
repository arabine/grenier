<table>
<tr>
    <td>
    <br />
    <br />
    
    Derni�re version en date, pr�te a �tre compil�e avec Visual C++.
    
    <br />
    <a href="downloads/FantasyBowl09-aug-2003.zip">FantasyBowl09-aug-2003.zip</a> (contient les sources de FantasyBowl et de TeamEditor)
    <br />
    <br />
    L'�diteur d'�quipe est maintenant s�par� du jeu, il est disponible ici :
    <br />
    <a href="downloads/TeamEditor09-aug-2003.zip">TeamEditor09-aug-2003.zip</a> (Binaire seulement + fichiers d'�quipes + images)
    <br />
    <br />
    Compilation sous linux :

    <ul>
        <li>generer le makefile : qtdesigner -> cr�er un nouveau projet, ajouter les fichiers sans les moc. Un fichier .pro est 
        cr�� sur le disque.
        <li>qmake -o Makefile nom_projet.pro puis make pour compiler.</li>
    </ul>

    Si des erreurs sont affich�es lors de la compilation ("ne peut pas trouver -lqt"). Editer Makefile et remplacer -lqt par -lqt-mt.
    
    <br />
    <br />
    </td>
</tr>
</table>