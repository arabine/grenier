/*=============================================================================
 * callistowindow.h
 *=============================================================================
 * Fenêtre principale
 *=============================================================================
 * (c) Anthony RABINE - 2002
 * Environment : VC++ 6.0
 * Build : Anthony RABINE - 27/10/2002
 *=============================================================================
 */

#ifndef CALLISTOWINDOW_H
#define CALLISTOWINDOW_H


/* XPM */
static const char *book[] = {
/* width height num_colors chars_per_pixel */
"    32    32      256            2",
/* colors */
"`` c #ffffff",
"`. c #7c8280",
"`# c #6c4a34",
"`a c #3c3e38",
"`b c #9c664c",
"`c c #c4c2bc",
"`d c #545e5c",
"`e c #ac826c",
"`f c #343e96",
"`g c #242e74",
"`h c #6c6664",
"`i c #b47244",
"`j c #a4a2a4",
"`k c #3c1a0c",
"`l c #849bb4",
"`m c #444e8e",
"`n c #6c6e84",
"`o c #54413c",
"`p c #a4764c",
"`q c #5c42ac",
"`r c #343eca",
"`s c #242224",
"`t c #7c8ebc",
"`u c #846a58",
"`v c #343e6c",
"`w c #c4aa9c",
"`x c #a46a84",
"`y c #ac968c",
"`z c #9c6e4c",
"`A c #5462b4",
"`B c #848284",
"`C c #6c52a4",
"`D c #242ea4",
"`E c #747774",
"`F c #acb2b0",
"`G c #34322f",
"`H c #845234",
"`I c #c4825b",
"`J c #04064b",
"`K c #ece2dc",
"`L c #443a7c",
"`M c #b47e54",
"`N c #3c46c2",
"`O c #444a4c",
"`P c #2c327c",
"`Q c #545e84",
"`R c #34469c",
"`S c #6c6e6f",
"`T c #ac6e54",
"`U c #8c8e89",
"`V c #e4d4cc",
"`W c #2c325c",
"`X c #6c5a4c",
"`Y c #242992",
"`Z c #8c9ed4",
"`0 c #544e4c",
"`1 c #543624",
"`2 c #1c1e3c",
"`3 c #3c3e4e",
"`4 c #bcaeac",
"`5 c #444e84",
"`6 c #acbab0",
"`7 c #c48a5c",
"`8 c #c47e5a",
".` c #3c47cf",
".. c #ac6a54",
".# c #646b6c",
".a c #a4aaac",
".b c #949c9c",
".c c #3c4ec4",
".d c #8c6a8c",
".e c #9c7674",
".f c #1c2654",
".g c #8496b5",
".h c #8c6e7c",
".i c #9c6f58",
".j c #34364c",
".k c #a4694b",
".l c #b48b75",
".m c #343eac",
".n c #54240e",
".o c #948a94",
".p c #7c7274",
".q c #644e6c",
".r c #6c82ac",
".s c #dcc6bc",
".t c #646663",
".u c #b47654",
".v c #7c7e84",
".w c #3c42cb",
".x c #848abc",
".y c #946649",
".z c #444664",
".A c #6474b8",
".B c #848a8a",
".C c #747e74",
".D c #846244",
".E c #0c1234",
".F c #bc7b5c",
".G c #444abf",
".H c #747171",
".I c #545654",
".J c #141214",
".K c #74564c",
".L c #c4cac4",
".M c #bc825e",
".N c #2c2d83",
".O c #7c6757",
".P c #3c466c",
".Q c #ccb6ac",
".R c #c49674",
".S c #343a38",
".T c #4c524c",
".U c #54667c",
".V c #3c46a2",
".W c #949192",
".X c #dcdad4",
".Y c #7c5f4f",
".Z c #2c2e94",
".0 c #44404c",
".1 c #bcbec0",
".2 c #c48c68",
".3 c #9ca2a4",
".4 c #2c2e4c",
".5 c #bc7d64",
".6 c #444644",
".7 c #9c6a54",
".8 c #3c42a4",
"#` c #aca6a4",
"#. c #f4f6f4",
"## c #545aac",
"#a c #2c3acc",
"#b c #c49e94",
"#c c #845a8c",
"#d c #9caedc",
"#e c #6c72a4",
"#f c #5c6acc",
"#g c #2c3284",
"#h c #5456a4",
"#i c #1c1e2c",
"#j c #4c3a4c",
"#k c #3c2624",
"#l c #0c0a24",
"#m c #7486dc",
"#n c #ac7a6c",
"#o c #747e9c",
"#p c #ac7657",
"#q c #bc9274",
"#r c #bcb6bc",
"#s c #141a54",
"#t c #7c86a4",
"#u c #945e4c",
"#v c #5c4654",
"#w c #d4ae9c",
"#x c #645149",
"#y c #d4926c",
"#z c #ecdedc",
"#A c #0c0e54",
"#B c #645654",
"#C c #a4726c",
"#D c #946e54",
"#E c #5c666c",
"#F c #343a6c",
"#G c #a47e7c",
"#H c #6c4a54",
"#I c #9c7a64",
"#J c #344284",
"#K c #5c72cc",
"#L c #4c5694",
"#M c #746254",
"#N c #fcfefc",
"#O c #845a44",
"#P c #546694",
"#Q c #7c8edc",
"#R c #3c1e24",
"#S c #444244",
"#T c #74665c",
"#U c #2c221c",
"#V c #2c2a94",
"#W c #242a5c",
"#X c #8c8eb4",
"#Y c #7c543c",
"#Z c #eceae4",
"#0 c #2c3a64",
"#1 c #8c7284",
"#2 c #8c7674",
"#3 c #94665c",
"#4 c #74829c",
"#5 c #343abc",
"#6 c #ccae94",
"#7 c #a46f4b",
"#8 c #7c7878",
"a` c #0c0a4c",
"a. c #4c4c4e",
"a# c #5c628c",
"aa c #4c507c",
"ab c #acacaa",
"ac c #444fbe",
"ad c #a46e54",
"ae c #3c3a50",
"af c #3c42ad",
"ag c #5c260c",
"ah c #cccdc7",
"ai c #cc8a64",
"aj c #1c1e58",
"ak c #242a84",
"al c #b47054",
"am c #8c9eb4",
"an c #343ed4",
"ao c #3c426c",
"ap c #c48264",
"aq c #ac725c",
"ar c #8c9294",
"as c #242a9c",
"at c #9c9d9c",
"au c #1c2a64",
"av c #5c5a54",
"aw c #bc866c",
"ax c #3c48ac",
"ay c #44425c",
"az c #5c5e64",
"aA c #b4b2b4",
"aB c #cc8a54",
"aC c #a4766c",
"aD c #bc7658",
"aE c #8c8a84",
"aF c #7c7e7c",
"aG c #d4b6a4",
"aH c #3c3a34",
"aI c #745a4c",
"aJ c #846254",
"aK c #3c467c",
"aL c #5c667c",
"aM c #e4dad4",
"aN c #bcbecc",
"aO c #2c2e5c",
"aP c #6c72b4",
"aQ c #5c6adc",
"aR c #2c3294",
"aS c #747eac",
"aT c #8c8ec4",
"aU c #7482ac",
"aV c #9c6a47",
"aW c #34429c",
"aX c #6c6a6c",
"aY c #a4a6a4",
"aZ c #3442cc",
"a0 c #24262c",
"a1 c #848686",
"a2 c #84563c",
"a3 c #c4865c",
"a4 c #040a4c",
"a5 c #3c4ac3",
"a6 c #6c7274",
"a7 c #ac7251",
"a8 c #2c3664",
/* pixels */
"````````ao`m`m`m`5`Q`m.t#M``````````````````````````````````````",
"``````.U#Q#L`v#0#WaK#J#j.D.D#u`T#7aV#7.y#H#P#o#e.r#X.xaL`0``````",
"```````l#d`m#l``.J#i.S.S.0.6a.a..I.I#T.H.D`h`u.H#8`B.v#8#i``````",
"``````.g`AaS`t.rao`GaH.S#S.6a.`d.#.t`E`..b`F`FaN#r.1#``3`J``````",
"``````.g.mak.`#faP#q`7.i.Y.K#x`0a..t.H`Ea6`Sa6`Uababah`5`J``````",
"``````.gaf.N.w`r`f.y`8.2#y`8.u#2#oa#aa#E`na1.Wat`FaFah`5`J``````",
"``````.g.8`g.w.``faV`8.5.F.F`8#G#f#m`Z`t.A.A#XaYab`Eahaa`J``````",
"``````.gaf#gaZ.GaWaV`8.F`I.Ma3aD`q#a#aac#f##.z`j.a`E.Laa`J``````",
"```````l.m.NaZ.G`faV`8.M.F.F.F`IaCax`N.w`N`Y`3aYaY`E`c`5`J``````",
"``````.gafak`N.waWaV`8`I.Fa3`I.M`8#c`NaZ`N`Y`3`jab.H`caa`2``````",
"``````.g.V#gaZ.G`faV`8.F.F.F.Fa3.F.F#h`r.G#V`3aY`ja6.1`u.n``````",
"```````laW#gaZ.GaWaV`8.5.F`8.M.Fa3`8.ea5`Nak`3aY`j.H`F.O.n``````",
"``````.gaf`g.w`N`f`z`8a3.Fa3.F`8.F`I`8`C`r.Z`3aYata6`6#M.n``````",
"```````lax`P`N.``faV`8.F.M#waGaG.2.M.F.5ac`Y`3aYata6ab#M.n``````",
"``````.g.8#g.w`N.8.y.5.R.s.l.l`w#N#6aD`I.d`Y`3aYata6ab#B.n``````",
"``````.g.m#gaZ`N`faV.F`V`w.iaV#Y#N#Naw.M`8.q`3#`.Wa6ab.Y.n``````",
"```````lafak.w.G.VaV..#.#N`V#p.i#N#N`eaDa3#7`oaYaraX.b`X.n``````",
"```````lax`P.waZ.8#3#p.D`y#Ia7`K#NaM.y`M`8`b`o.3.W`S.b`X.n``````",
"``````.g.8#g`N`NaW.7.uaV#O.i`K.X`4.Y.k.F`I#7`o.3ar.#ataI.n``````",
"```````l.m`g.`aZ.8.7`8.Fa7.Q#D`##Y.yala3.F.k`oaY.W.#ar#x.n``````",
"```````laf.NaZ.GaW`z`8.F`M#b.y#7.k.F.Fa3.5`b`o.3.W.#aE#x#R``````",
"```````lax#g.waZ.8#D`I.5#p.l.l.5a3.F.M`8.F.k`oaYar`S`U#F`J``````",
"``````.g.8aka5`N.8`b`8.Faw#ZaG.l`M`8.F.F`7a7`o.3.W.t.BaO#A``````",
"```````laf`g.w.GaW.i`8.F#7#Y#Y.kaD.M.F`I#n`L.0`jaE#E`.`Wa```````",
"``````#4ax#gaZ.waW.i.Fa3a7.ka7a7.M`8`8#C.Gas`3aY.B.t#8a8a```````",
"``````ao`3#s.m`raf.i`8.Fa3.F.5`IaDaB`xax.``Y`3aY.B.t`E`Wa```````",
"````````````ao#Wau#YaD`8`I.5`I.F`8#1`NaZ.Gak`3ab`..ta1.f`J``````",
"``````````````````#k#k`1`Hal`I`8.haZax.wac`Y`3aY.B.t.T``````````",
"````````````````````````#k#U`k#v.m.`a5`N`N.Z`3aY`B`G````````````",
"```````````````````````````````2`2ajaR`N.`.Zae`U`G``````````````",
"`````````````````````````````````````2.Eaj`g.j.6````````````````",
"``````````````````````````````````````````#iaz``````````````````"
};



// Librairies QT
#include <qapplication.h>
#include <qmessagebox.h>
#include <qlistbox.h> 
#include <qgroupbox.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlistbox.h>
#include <qmultilineedit.h>
#include <qtable.h>
#include <qmainwindow.h>
#include <qmenubar.h>
#include <qpopupmenu.h>
#include <qinputdialog.h>
#include <qfile.h>
#include <qtextstream.h>
#include <qstatusbar.h> 
#include <qfiledialog.h>
#include <qpixmap.h>

// Librairies internes
#include "DataBaseManager.h"
#include "NewAuthorFrame.h"
#include "BaseList.h"

class CallistoWindow : public QMainWindow
{
	Q_OBJECT

private:

	// Éléments QT
    QGroupBox *GroupBox4;
    QLineEdit *LineEdit1;
    QLabel *TextLabel1;
    QLabel *TextLabel2;
    QLineEdit *LineEdit2;
    QLabel *TextLabel3;
    QLabel *TextLabel4;
    QLineEdit *LineEdit4;
    QLabel *TextLabel5;
    QMultiLineEdit *MultiLineEdit1;
    QLineEdit *LineEdit3;
    QListBox *ListBox2;
    QTable *booklist;
	QMenuBar *menu;
	QPopupMenu *filemenu, *helpmenu, *newmenu, *optionsmenu;
	QStatusBar *statusbar;
	QPixmap *pixmap;

	// Autres éléments
	NewAuthorFrame *newauteur;
	BaseList *listauteurs;

	// Méthodes internes à la classe
	void setupMenuBar();
	void setupCentralWidgets();
	void initValues();
	void errorDataBase();
	void errorQuery();

public:
	// Variables globales
	bool bookLoaded;	// est ce qu'une base est ouverte ?
	bool modified;	// le fichier a-til été modifié ?
	QString auteur_loaded; // nom de l'auteur chargé
	
	DataBaseManager *DataBaseCnx; // Gestionnaire de connexions à la base de données


	// Constructeurs & Destructeurs
	CallistoWindow( QWidget* parent = 0, const char* name = 0, WFlags f = WType_TopLevel );
	~CallistoWindow()
	{
		delete newauteur;
		delete DataBaseCnx;
	
	}

public slots:
	void aboutBox();
	void newAuthor();
	void newBook();
	void listDataBase();
	void openDataBase(const char *auteur);
	void deleteAuthor(const char *text);

};

#endif

//=============================================================================
// End of callistowindow.h
//=============================================================================