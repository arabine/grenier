<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
<html>
<head>
    <title>
      FantasyBowl
    </title>
    <link href="style.css" type="text/css" rel="stylesheet" title="main">
    <link rel="shortcut icon" href="images/polar.ico">
    <meta http-equiv="content-type" content="text/html; charset=iso-8859-1">
    <meta name="author" content="belegar">
    <?include("javascripts.inc");?>
</head>
<body background="images/fond.png">
<center>
<table class="principal" cellspacing="0">
<tr>
    <td>
    <table cellspacing="0">
    <tr>
        <!-- Bandeau de titre -->
        <td rowspan="3" valign="top" align="left"><a href="http://fantasybowl.sourceforge.net/">
            <img src="images/titre.png" border="0" alt=""></a>
        </td>
        <td class="buttons" align="right"><a href="index.php?page=home&sub=news">
                <img src="images/b_home_<?if($page=="home" || !$page) echo 1; else echo 2;?>.png" border="0" alt="">
            </a>
        </td>
        <td class="buttons" align="right"><a href="index.php?page=shots&sub=win">
            <img src="images/b_shots_<?if($page=="shots") echo 1; else echo 2;?>.png" border="0" alt=""></a>
        </td>
        <td class="buttons" align="right"><a href="index.php?page=down&sub=files">
            <img src="images/b_down_<?if($page=="down") echo 1; else echo 2;?>.png" border="0" alt=""></a>
        </td>
        <td class="buttons" align="right"><a href="index.php?page=misc&sub=about">
            <img src="images/b_misc_<?if($page=="misc") echo 1; else echo 2;?>.png" border="0" alt=""></a>
        </td>
    </tr>
    <tr>
        <?// Boutons secondaires
            echo "<td class=\"subbuttons\" align=\"left\">"; echo $subButton1; echo "</td>\n";
            echo "<td class=\"subbuttons\" align=\"right\">"; echo $subButton2; echo "</td>\n";
            echo "<td class=\"subbuttons\" align=\"right\">"; echo $subButton3; echo "</td>\n";
            echo "<td class=\"subbuttons\" align=\"right\">"; echo $subButton4; echo "</td>\n";
        ?>
    </tr>
    <tr>
        <td colspan="4">
            <p style="text-align: center;">
                    <font size="3"><b>&nbsp;&nbsp;&nbsp;Statut actuel</b></font>
                    <br />
                    Version courante : FantasyBowl 0.3 <i>&lt;road-to-1.0&gt;</i> et TeamEditor 1.0<br />
                    Date : 09 aug 2003<br />
            </p>
        </td>
    </tr>
    <tr><td width="100%" height="10px" valign="top" colspan="5"><img src="images/pixel.png" border="0" alt=""></td></tr>
        <!-- Corps de la page -->
    <tr>
        <td colspan="5">