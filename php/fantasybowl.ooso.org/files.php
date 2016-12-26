<table>
<tr>
    <td>
    <br />
    <br />
    
    Dernière version en date, prête a être compilée avec Visual C++.
    
    <br />
    <a href="downloads/FantasyBowl09-aug-2003.zip">FantasyBowl09-aug-2003.zip</a> (contient les sources de FantasyBowl et de TeamEditor)
    <br />
    <br />
    L'éditeur d'équipe est maintenant séparé du jeu, il est disponible ici :
    <br />
    <a href="downloads/TeamEditor09-aug-2003.zip">TeamEditor09-aug-2003.zip</a> (Binaire seulement + fichiers d'équipes + images)
    <br />
    <br />
    Compilation sous linux :

    <ul>
        <li>generer le makefile : qtdesigner -> créer un nouveau projet, ajouter les fichiers sans les moc. Un fichier .pro est 
        créé sur le disque.
        <li>qmake -o Makefile nom_projet.pro puis make pour compiler.</li>
    </ul>

    Si des erreurs sont affichées lors de la compilation ("ne peut pas trouver -lqt"). Editer Makefile et remplacer -lqt par -lqt-mt.
    
    <br />
    <br />
    </td>
</tr>
</table>