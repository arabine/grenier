

#include "MyQCombo.h"


MyQCombo::MyQCombo(QWidget *parent, const QMap<int, Title> &theTitleList) : 
	QComboBox(FALSE, parent)
{
	Title ti;

    for(unsigned int i=0;i<theTitleList.count();i++)
	{
		ti = theTitleList[i];
		insertItem(ti.getName(), i);
	}
}
