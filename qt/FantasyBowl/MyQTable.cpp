

#include "MyQTable.h"


MyQTable::MyQTable( int numRows, int numCols, QWidget * parent, const char * name )
					: QTable( numRows, numCols,  parent,  name )
{
	connect(this, SIGNAL(valueChanged(int,int)), this , SLOT(checkValue(int,int)));
	connect(this, SIGNAL(recalcTotal()), parent , SLOT(calculTotal()));
	connect(this, SIGNAL(doubleClicked(int,int,int,const QPoint &)), parent , SLOT(showPlayerSkills(int,int)));
}

void MyQTable::checkValue(int row, int col)
{
	if(text(row,col).length()==0)
		return;

	if(col>=2 && col<=5)
	{
		if(text(row,col).toInt()<=0)
		{
			setText(row,col,"1");
			return;
		}
		else if(text(row,col).toInt()>10)
			{
				setText(row,col,"10");
				return;
			}
	
	}
	else if(col==14)
		{
			if(text(row,col).toInt()<=0)
				{
					setText(row,col,"0");
					return;
				}
				else if(text(row,col).toInt()>200000)
					{
						setText(row,col,"200000");
						return;
					}
			emit recalcTotal();
		}
}
